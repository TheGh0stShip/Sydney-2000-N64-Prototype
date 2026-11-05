#!/usr/bin/env python3
"""Generate the objdiff v2 report consumed by ByteMatch."""

from __future__ import annotations

import hashlib
import json
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "config/survey/functions.toml"
MANIFESTS = sorted((ROOT / "config").glob("matching*.tsv"))
OUTPUT = ROOT / "build/report.json"
ROM_TO_VRAM = 0x7FFFF400
DATA_LEDGER = ROOT / "config/matching_data.json"


def measures(code: int, matched: int, functions: int, matched_functions: int,
             data: int = 0, matched_data: int = 0) -> dict:
    code_percent = 100.0 * matched / code if code else 0.0
    data_percent = 100.0 * matched_data / data if data else 0.0
    function_percent = 100.0 * matched_functions / functions if functions else 0.0
    return {
        "fuzzy_match_percent": code_percent,
        "total_code": str(code),
        "matched_code": str(matched),
        "matched_code_percent": code_percent,
        "total_data": str(data),
        "matched_data": str(matched_data),
        "matched_data_percent": data_percent,
        "total_functions": functions,
        "matched_functions": matched_functions,
        "matched_functions_percent": function_percent,
        "complete_code": str(matched),
        "complete_code_percent": code_percent,
        "complete_data": str(matched_data),
        "complete_data_percent": data_percent,
        "total_units": functions,
        "complete_units": matched_functions,
    }


def manifest_ranges() -> list[tuple[int, int, str]]:
    ranges = []
    for manifest in MANIFESTS:
        for line in manifest.read_text().splitlines():
            if not line or line.startswith("#"):
                continue
            fields = line.split("\t")
            start, size = int(fields[0], 0), int(fields[1], 0)
            ranges.append((start, start + size, fields[2]))
    return ranges


def merge_ranges(ranges: list[tuple[int, int]]) -> list[tuple[int, int]]:
    """Count each byte once, including adjacent matches from separate units."""
    merged: list[tuple[int, int]] = []
    for start, end in sorted(ranges):
        if end <= start:
            raise ValueError(f"invalid matching range {start:#x}..{end:#x}")
        if merged and start <= merged[-1][1]:
            merged[-1] = (merged[-1][0], max(merged[-1][1], end))
        else:
            merged.append((start, end))
    return merged


def covered_bytes(start: int, end: int, merged: list[tuple[int, int]]) -> int:
    return sum(max(0, min(end, right) - max(start, left))
               for left, right in merged)


def missing_ranges(start: int, end: int,
                   merged: list[tuple[int, int]]) -> list[tuple[int, int]]:
    missing = []
    cursor = start
    for left, right in merged:
        if right <= cursor or left >= end:
            continue
        if cursor < left:
            missing.append((cursor, left))
        cursor = max(cursor, min(end, right))
    if cursor < end:
        missing.append((cursor, end))
    return missing


def load_data_measures(path: Path | None = None) -> tuple[int, int]:
    """Require compiler-verified, current initialized-data provenance (no ROM needed)."""
    ledger_path = path or DATA_LEDGER
    ledger = json.loads(ledger_path.read_text())
    if ledger.get("version") != 1:
        raise ValueError("unsupported initialized-data ledger version")
    identity = tomllib.loads((ROOT / "config/segments.toml").read_text())["rom"]["sha1"]
    if ledger.get("rom_sha1") != identity:
        raise ValueError("initialized-data ledger belongs to another ROM")
    inputs = ledger.get("inputs", [])
    if not inputs:
        raise ValueError("initialized-data ledger has no input provenance")
    tracked = set()
    for item in inputs:
        relative = Path(item["path"])
        if relative.is_absolute() or ".." in relative.parts:
            raise ValueError(f"invalid ledger input path: {relative}")
        source = ROOT / relative
        if hashlib.sha256(source.read_bytes()).hexdigest() != item["sha256"]:
            raise ValueError(f"stale data ledger input: {relative}; run make data-ledger")
        tracked.add(relative.as_posix())
    for manifest in MANIFESTS:
        if manifest.relative_to(ROOT).as_posix() not in tracked:
            raise ValueError(f"unverified manifest: {manifest}; run make data-ledger")
    classification = ledger["classification"]
    provenance = {item["path"]: item["sha256"] for item in inputs}
    if provenance.get(classification["path"]) != classification["sha256"]:
        raise ValueError("data classification is missing from ledger provenance")
    verification = ledger["verification"]
    if verification["units"] <= 0 or verification["units"] != verification["exact_units"]:
        raise ValueError("data ledger includes unverified compilation units")
    ranges = [(item["rom_start"], item["rom_end"]) for item in ledger["ranges"]]
    if ranges != merge_ranges(ranges):
        raise ValueError("data ledger ranges must be sorted and non-overlapping")
    if any(item["size"] != item["rom_end"] - item["rom_start"]
           for item in ledger["ranges"]):
        raise ValueError("inconsistent initialized-data extent")
    total, matched = ledger["total_data"], ledger["matched_data"]
    if matched != sum(end - start for start, end in ranges) or not 0 <= matched <= total:
        raise ValueError("inconsistent initialized-data totals")
    return total, matched


def main() -> None:
    total_data, matched_data = load_data_measures()
    section = tomllib.loads(FUNCTIONS.read_text())["section"][0]
    functions = section["functions"]
    ranges = manifest_ranges()
    merged = merge_ranges([(start, end) for start, end, _ in ranges])
    units = []
    matched_count = 0
    for function in functions:
        rom_start = function["vram"] - ROM_TO_VRAM
        rom_end = rom_start + function["size"]
        source = next((source for start, end, source in ranges
                       if start < rom_end and rom_start < end), None)
        matched_bytes = covered_bytes(rom_start, rom_end, merged)
        complete = matched_bytes == function["size"]
        matched_count += int(complete)
        unit_measures = measures(function["size"], matched_bytes,
                                 1, int(complete))
        units.append({
            "name": function["name"],
            "measures": unit_measures,
            "functions": [{
                "name": function["name"],
                "size": str(function["size"]),
                "fuzzy_match_percent": unit_measures["fuzzy_match_percent"],
                "address": str(function["vram"]),
                "metadata": {"virtual_address": str(function["vram"])},
            }],
            "metadata": {
                "complete": complete,
                "source_path": source or f"asm/us/{function['name']}.s",
                "progress_categories": ["code"],
                "auto_generated": not complete,
            },
        })

    # Manifest rows can overlap (whole libraries and individual functions).
    # Only their union within the surveyed text segment contributes code bytes.
    total_code = section["size"]
    text_start = section["rom"]
    text_end = text_start + total_code
    matched_code = covered_bytes(text_start, text_end, merged)
    gaps = missing_ranges(text_start, text_end, merged)
    report = {
        "measures": measures(total_code, matched_code, len(functions), matched_count,
                             total_data, matched_data),
        "units": units,
        "version": 2,
        "categories": [
            {"id": "code", "name": "Program code",
             "measures": measures(total_code, matched_code, len(functions), matched_count)},
            {"id": "program_data", "name": "Initialized program data",
             "measures": measures(0, 0, 0, 0, total_data, matched_data)},
        ],
    }
    OUTPUT.parent.mkdir(exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    gap_report = {
        "text_rom_start": text_start,
        "text_rom_end": text_end,
        "unmatched_code_bytes": total_code - matched_code,
        "unmatched_ranges": [
            {"rom_start": start, "rom_end": end,
             "vram_start": start + ROM_TO_VRAM,
             "vram_end": end + ROM_TO_VRAM, "size": end - start}
            for start, end in gaps
        ],
        "incomplete_functions": [unit["name"] for unit in units
                                 if not unit["metadata"]["complete"]],
        "function_gaps": [
            {"name": function["name"], "size": function["size"],
             "matched_bytes": int(unit["measures"]["matched_code"]),
             "missing_ranges": [
                 {"rom_start": left, "rom_end": right, "size": right - left}
                 for left, right in missing_ranges(
                     function["vram"] - ROM_TO_VRAM,
                     function["vram"] - ROM_TO_VRAM + function["size"], merged)
             ]}
            for function, unit in zip(functions, units)
            if not unit["metadata"]["complete"]
        ],
    }
    OUTPUT.with_name("decomp_gaps.json").write_text(
        json.dumps(gap_report, indent=2) + "\n")
    print(f"wrote {OUTPUT}: {matched_count} / {len(functions)} functions, "
          f"{matched_code} / {total_code} code bytes")


if __name__ == "__main__":
    main()
