#!/usr/bin/env python3
"""Generate and verify a byte-complete inventory of the preservation ROM."""

from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from hashlib import sha1
import json
from pathlib import Path
import struct
import sys

from verify import EXPECTED_SHA1, EXPECTED_SIZE


DIRECTORY_START = 0x1A3AB0
RECORD_SIZE = 0x4C
NAMED_FILE_LAST = 1560
ZERO_FILL_START = 0x1DC1CE2


REGIONS = (
    (0x0000000, 0x0000040, "rom_header", "N64 cartridge header"),
    (0x0000040, 0x0001000, "ipl3", "CIC 6102 boot program"),
    (0x0001000, 0x0069070, "resident_program", "resident MIPS/RSP code and initialized data"),
    (0x0069070, 0x0127640, "overlay_bank", "dynamically loaded MIPS code and data banks"),
    (0x0127640, DIRECTORY_START, "runtime_catalog", "event runtime and ROM-load catalog"),
    (DIRECTORY_START, 0x0224B78, "file_directory", "6955 fixed-size file records"),
    (0x0224B78, 0x02596A0, "texture_header", "sprite-texture catalog payload"),
    (0x02596A0, 0x055D554, "texture_payload", "sprite-texture subresources and alignment"),
    (0x055D554, ZERO_FILL_START, "named_file_payload", "named files and alignment"),
    (ZERO_FILL_START, EXPECTED_SIZE, "zero_fill", "unused cartridge capacity"),
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--output-dir", type=Path, default=Path("config/inventory"))
    parser.add_argument("--check", action="store_true")
    return parser.parse_args()


def decode_name(raw: bytes) -> str:
    name = raw.split(b"\0", 1)[0].decode("ascii")
    if not name or "\t" in name or "\n" in name or "\r" in name:
        raise ValueError(f"invalid archive name {name!r}")
    return name


def file_kind(name: str) -> str:
    if name.startswith("sprtexgtx:"):
        return "sprite_texture"
    if "." not in name.rsplit("\\", 1)[-1]:
        return "untyped"
    return name.rsplit(".", 1)[1].lower()


def merge_extents(extents: set[tuple[int, int]]) -> list[tuple[int, int]]:
    merged: list[list[int]] = []
    for start, end in sorted(extents):
        if not merged or start > merged[-1][1]:
            merged.append([start, end])
        elif end > merged[-1][1]:
            merged[-1][1] = end
    return [(start, end) for start, end in merged]


def gaps_between(
    start: int, end: int, extents: set[tuple[int, int]]
) -> list[tuple[int, int]]:
    gaps: list[tuple[int, int]] = []
    cursor = start
    for extent_start, extent_end in merge_extents(extents):
        if extent_start < start or extent_end > end:
            raise ValueError("archive extent escapes its assigned region")
        if extent_start > cursor:
            gaps.append((cursor, extent_start))
        cursor = max(cursor, extent_end)
    if cursor < end:
        gaps.append((cursor, end))
    return gaps


def render(rom: bytes) -> dict[str, str]:
    if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError("unsupported game image")

    cursor = 0
    for start, end, _, _ in REGIONS:
        if start != cursor or end <= start:
            raise ValueError("top-level regions are not contiguous")
        cursor = end
    if cursor != len(rom):
        raise ValueError("top-level regions do not cover the complete ROM")
    if any(rom[ZERO_FILL_START:]):
        raise ValueError("declared zero-fill suffix contains nonzero data")

    count = struct.unpack_from(">I", rom, DIRECTORY_START)[0]
    if count != 6955:
        raise ValueError(f"unexpected archive record count: {count}")
    directory_end = DIRECTORY_START + 4 + count * RECORD_SIZE
    if directory_end != 0x224B78:
        raise ValueError(f"unexpected archive directory end: 0x{directory_end:X}")

    records: list[dict[str, object]] = []
    extent_indices: defaultdict[tuple[int, int], list[int]] = defaultdict(list)
    for index in range(count):
        record_at = DIRECTORY_START + 4 + index * RECORD_SIZE
        size, logical_offset, aux = struct.unpack_from(">III", rom, record_at)
        name = decode_name(rom[record_at + 12 : record_at + RECORD_SIZE])
        physical_start = directory_end + logical_offset
        physical_end = physical_start + size
        if physical_end > ZERO_FILL_START:
            raise ValueError(f"record {index} exceeds meaningful ROM data")
        role = (
            "texture_header"
            if index == 0
            else "named_file"
            if index <= NAMED_FILE_LAST
            else "texture_subresource"
        )
        record = {
            "index": index,
            "record_at": record_at,
            "logical_offset": logical_offset,
            "physical_start": physical_start,
            "physical_end": physical_end,
            "size": size,
            "aux": aux,
            "role": role,
            "kind": file_kind(name),
            "name": name,
            "sha1": sha1(rom[physical_start:physical_end]).hexdigest(),
        }
        records.append(record)
        extent_indices[(physical_start, physical_end)].append(index)

    expected_ranges = {
        "texture_header": (0x224B78, 0x2596A0),
        "texture_subresource": (0x2596A0, 0x55D554),
        "named_file": (0x55D554, 0x1DC1CE1),
    }
    role_extents: defaultdict[str, set[tuple[int, int]]] = defaultdict(set)
    for record in records:
        role_extents[str(record["role"])].add(
            (int(record["physical_start"]), int(record["physical_end"]))
        )
    padding: list[tuple[int, int, str]] = []
    for role, (start, end) in expected_ranges.items():
        for gap_start, gap_end in gaps_between(start, end, role_extents[role]):
            if gap_end - gap_start != 1 or rom[gap_start:gap_end] != b"\xFF":
                raise ValueError(
                    f"unexpected {role} gap 0x{gap_start:X}..0x{gap_end:X}"
                )
            padding.append((gap_start, gap_end, role))
    if rom[0x1DC1CE1:ZERO_FILL_START] != b"\xFF":
        raise ValueError("missing final archive alignment byte")
    padding.append((0x1DC1CE1, ZERO_FILL_START, "named_file"))
    if len(padding) != 2093:
        raise ValueError(f"unexpected archive padding count: {len(padding)}")

    region_lines = ["start\tend\tsize\tclass\tdescription"]
    for start, end, kind, description in REGIONS:
        region_lines.append(
            f"0x{start:X}\t0x{end:X}\t{end - start}\t{kind}\t{description}"
        )

    record_lines = [
        "index\trecord_at\tlogical_offset\tphysical_start\tphysical_end\tsize\taux\trole\tkind\tcanonical_index\tsha1\tname"
    ]
    for record in records:
        extent = (int(record["physical_start"]), int(record["physical_end"]))
        canonical = min(extent_indices[extent])
        record_lines.append(
            "\t".join(
                (
                    str(record["index"]),
                    f"0x{int(record['record_at']):X}",
                    f"0x{int(record['logical_offset']):X}",
                    f"0x{int(record['physical_start']):X}",
                    f"0x{int(record['physical_end']):X}",
                    str(record["size"]),
                    f"0x{int(record['aux']):X}",
                    str(record["role"]),
                    str(record["kind"]),
                    str(canonical),
                    str(record["sha1"]),
                    str(record["name"]),
                )
            )
        )

    padding_lines = ["start\tend\tsize\tvalue\tbetween"]
    for start, end, role in sorted(padding):
        padding_lines.append(f"0x{start:X}\t0x{end:X}\t1\t0xFF\t{role}")

    kind_counts = Counter(str(record["kind"]) for record in records)
    duplicate_aliases = sum(len(indices) - 1 for indices in extent_indices.values())
    summary = {
        "rom": {
            "size": len(rom),
            "sha1": EXPECTED_SHA1,
            "meaningful_end": f"0x{ZERO_FILL_START:X}",
            "zero_fill_bytes": len(rom) - ZERO_FILL_START,
            "coverage_bytes": len(rom),
            "coverage_percent": 100.0,
        },
        "archive": {
            "directory_start": f"0x{DIRECTORY_START:X}",
            "directory_end": f"0x{directory_end:X}",
            "payload_base": f"0x{directory_end:X}",
            "payload_end": f"0x{ZERO_FILL_START:X}",
            "records": count,
            "named_files": NAMED_FILE_LAST,
            "texture_subresources": count - NAMED_FILE_LAST - 1,
            "texture_header_records": 1,
            "duplicate_aliases": duplicate_aliases,
            "alignment_bytes": len(padding),
            "kinds": dict(sorted(kind_counts.items())),
        },
        "regions": len(REGIONS),
    }

    return {
        "regions.tsv": "\n".join(region_lines) + "\n",
        "archive_records.tsv": "\n".join(record_lines) + "\n",
        "archive_padding.tsv": "\n".join(padding_lines) + "\n",
        "summary.json": json.dumps(summary, indent=2, sort_keys=True) + "\n",
    }


def main() -> int:
    args = parse_args()
    try:
        outputs = render(args.rom.read_bytes())
    except (OSError, UnicodeError, ValueError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    if args.check:
        stale = []
        for name, expected in outputs.items():
            path = args.output_dir / name
            if not path.is_file() or path.read_text() != expected:
                stale.append(str(path))
        if stale:
            print("stale inventory: " + ", ".join(stale), file=sys.stderr)
            return 1
        print("inventory: exact, complete, and current")
        return 0

    args.output_dir.mkdir(parents=True, exist_ok=True)
    for name, content in outputs.items():
        (args.output_dir / name).write_text(content)
    print(f"inventory: wrote {len(outputs)} files to {args.output_dir}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
