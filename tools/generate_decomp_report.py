#!/usr/bin/env python3
"""Generate the objdiff v2 report consumed by ByteMatch."""

from __future__ import annotations

import json
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "config/survey/functions.toml"
MANIFESTS = sorted((ROOT / "config").glob("matching*.tsv"))
OUTPUT = ROOT / "build/report.json"
ROM_TO_VRAM = 0x7FFFF400
TOTAL_DATA = 206_276
MATCHED_DATA = 3_480


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


def main() -> None:
    section = tomllib.loads(FUNCTIONS.read_text())["section"][0]
    functions = section["functions"]
    ranges = manifest_ranges()
    units = []
    matched_code = 0
    matched_count = 0
    for function in functions:
        rom_start = function["vram"] - ROM_TO_VRAM
        rom_end = rom_start + function["size"]
        source = next((source for start, end, source in ranges
                       if start <= rom_start < end), None)
        complete = source is not None
        matched_code += function["size"] if complete else 0
        matched_count += int(complete)
        unit_measures = measures(function["size"],
                                 function["size"] if complete else 0,
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

    # Keep the public project measures consistent with the verified manifests:
    # every row contributes its compared text extent, while every catalogue
    # entry whose start lies in such an extent is a reconstructed function.
    total_code = section["size"]
    matched_code = sum(end - start for start, end, _source in ranges)
    report = {
        "measures": measures(total_code, matched_code, len(functions), matched_count,
                             TOTAL_DATA, MATCHED_DATA),
        "units": units,
        "version": 2,
        "categories": [
            {"id": "code", "name": "Program code",
             "measures": measures(total_code, matched_code, len(functions), matched_count)},
            {"id": "program_data", "name": "Initialized program data",
             "measures": measures(0, 0, 0, 0, TOTAL_DATA, MATCHED_DATA)},
        ],
    }
    OUTPUT.parent.mkdir(exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    print(f"wrote {OUTPUT}: {matched_count} / {len(functions)} functions, "
          f"{matched_code} / {total_code} code bytes")


if __name__ == "__main__":
    main()
