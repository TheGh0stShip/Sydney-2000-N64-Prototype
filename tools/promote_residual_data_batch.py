#!/usr/bin/env python3
"""Promote a large reviewed residual-data batch into exact C data units."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
RESIDUALS = ROOT / "config/residual_literals.json"
UNITS = ROOT / "config/data/units.json"


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def emit_source(path: Path, symbol: str, data: bytes, rom_start: int) -> None:
    words = [int.from_bytes(data[index:index + 4], "big")
             for index in range(0, len(data), 4)]
    lines = [
        f"/* Initialized overlay/runtime data at ROM 0x{rom_start:X}. */",
        "typedef unsigned int u32;",
        "typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];",
        "",
        f'u32 {symbol}[{len(words)}] __attribute__((section(".data"))) = {{',
    ]
    for index in range(0, len(words), 8):
        lines.append("    " + ", ".join(
            f"0x{word:08X}" for word in words[index:index + 8]) + ",")
    lines.extend(["};", ""])
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--minimum-bytes", type=lambda value: int(value, 0), default=100_000)
    args = parser.parse_args()
    if args.minimum_bytes < 100_000:
        raise ValueError("large-pass promotion requires at least 100000 bytes")

    residual = json.loads(RESIDUALS.read_text())
    manifest = json.loads(UNITS.read_text())
    segments = {item["id"]: item for item in manifest["segments"]}
    existing_ids = {item["id"] for item in manifest["units"]}
    candidates = []
    for item in residual["ranges"]:
        start, size = item["rom_start"], item["size"]
        if start % 4 or size % 4:
            continue
        segment = next((entry for entry in (segments["event_bank"], segments["runtime"])
                        if entry["rom_start"] <= start and start + size <= entry["rom_end"]), None)
        if segment is not None:
            candidates.append((item, segment))
    candidates.sort(key=lambda pair: pair[0]["size"], reverse=True)

    selected, total = [], 0
    for pair in candidates:
        selected.append(pair)
        total += pair[0]["size"]
        if total >= args.minimum_bytes:
            break
    if total < args.minimum_bytes:
        raise ValueError(f"only {total} aligned residual bytes are eligible")

    promoted_ids = set()
    new_units = []
    for item, segment in selected:
        start, size = item["rom_start"], item["size"]
        vram = start + segment["vram_delta"]
        unit_id = f'{segment["id"]}_data_{vram:08X}'
        if unit_id in existing_ids:
            raise ValueError(f"duplicate data unit {unit_id}")
        source = Path("src/data") / f"{unit_id}.c"
        output = ROOT / source
        if output.exists():
            raise ValueError(f"refusing to overwrite {source}")
        data = bytes.fromhex(item["data_hex"])
        if len(data) != size or digest(data) != item["sha256"]:
            raise ValueError(f'{item["id"]}: residual data integrity changed')
        emit_source(output, unit_id, data, start)
        source_hash = digest(output.read_bytes())
        new_units.append({
            "id": unit_id,
            "source": str(source),
            "inputs": {str(source): source_hash},
            "pipeline": "sn",
            "flags": ["-O2", "-G0", "-mcpu=vr4300", "-mips3", "-mhard-float", "-meb"],
            "include_dirs": [],
            "symbols": {},
            "sections": [{"name": ".data", "segment": segment["id"],
                          "rom_start": start, "vram": vram, "size": size,
                          "sha256": item["sha256"]}],
        })
        promoted_ids.add(item["id"])

    manifest["units"].extend(new_units)
    residual["ranges"] = [item for item in residual["ranges"] if item["id"] not in promoted_ids]
    UNITS.write_text(json.dumps(manifest, indent=2) + "\n")
    RESIDUALS.write_text(json.dumps(residual, indent=2) + "\n")
    print(f"promoted {len(new_units)} units, {total} bytes")


if __name__ == "__main__":
    main()
