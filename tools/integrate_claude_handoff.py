#!/usr/bin/env python3
"""Integrate a reconciled Claude handoff as one ownership transaction.

The input list must contain only parent-verified, policy-eligible packages.  The
tool derives placements from PARENT_VERIFY.json, replaces every overlapping
matching row, subtracts recovered text/data from residual and initialized-data
ownership, and registers all required SN delta manifests.
"""

from __future__ import annotations

import argparse
import copy
import hashlib
import json
from pathlib import Path
import re
import shutil


ROOT = Path(__file__).resolve().parents[1]
DEFAULT_HANDOFF = Path("/tmp/sydney-claude-handoff")
SEGMENTS = (
    (0x69070, 0x6DF40, "ceremony", Path("config/overlay/ceremony"), 0x80007924),
    (0x6DF40, 0x70800, "closing", Path("config/overlay/closing"), 0x80002554),
    (0x70800, 0x127640, "event_bank", Path("config/overlay/event_bank"), 0x80000000),
    (0x127640, 0x1A3AB0, "runtime", Path("config/runtime"), 0x7FF5C710),
)
ROW_RE = re.compile(r"^(0x[0-9A-Fa-f]+)\t(0x[0-9A-Fa-f]+)\t")
SPECIAL_DESTINATIONS = {
    # Same runtime VRAM names occur in distinct overlay/ROM identities.
    "cg_a2a68": "src/overlays/event_bank_func_800A2A68_full.c",
    "fdc_144db0": "src/runtime/func_800A14C0_rom_144DB0.c",
    "fdc_bc388": "src/overlays/event_bank_func_80071948_rom_BC388.c",
}


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def segment_for(start: int, end: int):
    for lo, hi, name, directory, delta in SEGMENTS:
        if lo <= start < end <= hi:
            return name, directory, delta
    raise ValueError(f"range {start:#x}..{end:#x} crosses an executable segment")


def subtract(start: int, end: int, cuts: list[tuple[int, int]]) -> list[tuple[int, int]]:
    pieces = [(start, end)]
    for cut_start, cut_end in cuts:
        next_pieces = []
        for left, right in pieces:
            if cut_end <= left or right <= cut_start:
                next_pieces.append((left, right))
            else:
                if left < cut_start:
                    next_pieces.append((left, cut_start))
                if cut_end < right:
                    next_pieces.append((cut_end, right))
        pieces = next_pieces
    return pieces


def parse_row(line: str):
    match = ROW_RE.match(line)
    if not match:
        return None
    start, size = (int(value, 0) for value in match.groups())
    return start, start + size


def emit_data_source(path: Path, symbol: str, section: str, data: bytes, rom: int) -> None:
    lines = [f"/* Initialized data retained at ROM 0x{rom:X}. */"]
    if len(data) % 4 == 0 and rom % 4 == 0:
        words = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data), 4)]
        lines.extend(["typedef unsigned int u32;",
                      "typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];", "",
                      f'u32 {symbol}[{len(words)}] __attribute__((section("{section}"))) = {{'])
        for index in range(0, len(words), 8):
            lines.append("    " + ", ".join(f"0x{word:08X}" for word in words[index:index + 8]) + ",")
    else:
        qualifier = "const " if section.startswith((".rodata", ".rdata")) else ""
        lines.extend(["typedef unsigned char u8;", "",
                      f'{qualifier}u8 {symbol}[{len(data)}] __attribute__((section("{section}"))) = {{'])
        for index in range(0, len(data), 16):
            lines.append("    " + ", ".join(f"0x{value:02X}" for value in data[index:index + 16]) + ",")
    lines.extend(["};", ""])
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--handoff", type=Path, default=DEFAULT_HANDOFF)
    parser.add_argument("--list", type=Path)
    parser.add_argument("--apply", action="store_true")
    args = parser.parse_args()
    handoff = args.handoff
    list_path = args.list or handoff / "READY_NEW.txt"
    names = [line.strip() for line in list_path.read_text().splitlines() if line.strip()]
    rom = (ROOT / "baserom.z64").read_bytes()
    diff_map = {}
    for line in (handoff / "READY_INTEGRATION_DIFF.tsv").read_text().splitlines():
        fields = line.split("\t")
        if len(fields) >= 3:
            diff_map[fields[0]] = fields

    candidates = []
    for name in names:
        package = handoff / name
        row_fields = (package / "ROW.tsv").read_text().strip().split("\t")
        if len(row_fields) != 5:
            raise ValueError(f"{name}: expected one five-field ROW.tsv")
        verify = json.loads((package / "PARENT_VERIFY.json").read_text())
        if verify.get("exact") != 1 or verify.get("failed") or len(verify.get("results", [])) != 1:
            raise ValueError(f"{name}: parent verification is not one exact result")
        result = verify["results"][0]
        if result.get("pipeline") != "sn" or not result.get("exact") or not result.get("digest_ok"):
            raise ValueError(f"{name}: unacceptable verification result")
        start, size = int(row_fields[0], 0), int(row_fields[1], 0)
        end = start + size
        if result["text"]["size"] != size or not result["text"]["match"]:
            raise ValueError(f"{name}: text extent mismatch")
        delta = (int(result["text"]["vram"]) - start) & 0xFFFFFFFF
        seg_name, directory, default_delta = segment_for(start, end)
        source = SPECIAL_DESTINATIONS.get(name, row_fields[2])
        if not source.startswith("src/"):
            current = diff_map.get(name, ["", "", ""])[2].split()
            current = next((item for item in current if item.startswith("src/") and item.endswith(".c")), None)
            if current is None:
                raise ValueError(f"{name}: no production source destination")
            source = current
        sections = []
        for section in result.get("sections", []):
            data_start = (int(section["vram"]) - delta) & 0xFFFFFFFF
            sections.append((data_start, data_start + int(section["size"]), section["name"]))
        row_fields[2] = source
        candidates.append({"name": name, "package": package, "start": start, "end": end,
                           "delta": delta, "segment": seg_name, "directory": directory,
                           "default_delta": default_delta, "source": source,
                           "row": "\t".join(row_fields), "sections": sections})

    text_ranges = sorted((item["start"], item["end"]) for item in candidates)
    data_ranges = sorted((a, b) for item in candidates for a, b, _ in item["sections"])
    for ranges, label in ((text_ranges, "text"), (data_ranges, "data")):
        for first, second in zip(ranges, ranges[1:]):
            if first[1] > second[0]:
                raise ValueError(f"overlapping candidate {label}: {first} / {second}")

    matching_paths = sorted(set(ROOT.glob("config/**/matching*.tsv")))
    rewritten = {}
    removed_rows = []
    for path in matching_paths:
        kept = []
        for line in path.read_text().splitlines():
            extent = parse_row(line)
            if extent and any(extent[0] < end and start < extent[1] for start, end in text_ranges):
                removed_rows.append((str(path.relative_to(ROOT)), line))
            else:
                kept.append(line)
        rewritten[path] = kept

    manifests: dict[Path, list[str]] = {}
    for item in candidates:
        if item["delta"] == item["default_delta"]:
            manifest = ROOT / item["directory"] / "matching_sn.tsv"
        else:
            manifest = ROOT / item["directory"] / f'matching_delta_{item["delta"]:08x}_sn.tsv'
        manifests.setdefault(manifest, []).append(item["row"])
    for manifest, rows in manifests.items():
        lines = rewritten.get(manifest, manifest.read_text().splitlines() if manifest.exists() else [])
        comments = [line for line in lines if line.startswith("#") or not line.strip()]
        records = [line for line in lines if parse_row(line)] + rows
        records.sort(key=lambda line: parse_row(line)[0])
        rewritten[manifest] = comments + records

    residual_path = ROOT / "config/residual_literals.json"
    residual = json.loads(residual_path.read_text())
    all_claims = text_ranges + data_ranges
    residual_ranges = []
    for item in residual["ranges"]:
        start, end = item["rom_start"], item["rom_start"] + item["size"]
        for index, (left, right) in enumerate(subtract(start, end, all_claims)):
            data = rom[left:right]
            clone = copy.deepcopy(item)
            clone.update(id=f'{item["id"]}_part{index}' if (left, right) != (start, end) else item["id"],
                         rom_start=left, size=right-left, sha256=digest(data), data_hex=data.hex())
            residual_ranges.append(clone)
    residual["ranges"] = residual_ranges

    units_path = ROOT / "config/data/units.json"
    units = json.loads(units_path.read_text())
    new_units = []
    split_sources = []
    for unit in units["units"]:
        touched = any(section["rom_start"] < end and start < section["rom_start"] + section["size"]
                      for section in unit["sections"] for start, end in data_ranges)
        if not touched:
            new_units.append(unit)
            continue
        for section in unit["sections"]:
            start, end = section["rom_start"], section["rom_start"] + section["size"]
            pieces = subtract(start, end, data_ranges)
            for left, right in pieces:
                data = rom[left:right]
                vram = section["vram"] + (left - start)
                unit_id = f'{section["segment"]}_data_{vram:08X}'
                source = Path("src/data") / f"{unit_id}.c"
                split_sources.append((ROOT / source, unit_id, section["name"], data, left))
                clone = {key: copy.deepcopy(value) for key, value in unit.items()
                         if key not in ("id", "source", "inputs", "sections")}
                clone.update(id=unit_id, source=str(source), inputs={str(source): "PENDING"}, sections=[{
                    **section, "rom_start": left, "vram": vram, "size": right-left,
                    "sha256": digest(data),
                }])
                new_units.append(clone)
    units["units"] = sorted(new_units, key=lambda unit: min(s["rom_start"] for s in unit["sections"]))

    custom = sorted((item["segment"], item["directory"], item["delta"])
                    for item in candidates if item["delta"] != item["default_delta"])
    custom = sorted(set(custom))
    print(f"packages={len(candidates)} text={sum(b-a for a,b in text_ranges)} "
          f"data={sum(b-a for a,b in data_ranges)} removed_rows={len(removed_rows)} "
          f"custom_manifests={len(custom)} split_data_units={len(split_sources)}")
    if not args.apply:
        return

    for item in candidates:
        destination = ROOT / item["source"]
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(item["package"] / "SOURCE.c", destination)
    for path, lines in rewritten.items():
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\n".join(lines).rstrip() + "\n")
    for path, symbol, section, data, start in split_sources:
        emit_data_source(path, symbol, section, data, start)
    for unit in units["units"]:
        if list(unit["inputs"].values()) == ["PENDING"]:
            source = ROOT / unit["source"]
            unit["inputs"][unit["source"]] = digest(source.read_bytes())
    units_path.write_text(json.dumps(units, indent=2) + "\n")
    residual_path.write_text(json.dumps(residual, indent=2) + "\n")

    print("wrote global transaction")


if __name__ == "__main__":
    main()
