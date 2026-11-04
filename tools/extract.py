#!/usr/bin/env python3
"""Extract immutable ranges used while splitting the program."""

from pathlib import Path
import sys

from verify import EXPECTED_SHA1, EXPECTED_SIZE
from hashlib import sha1

PROGRAM_START = 0x1000
PROGRAM_END = 0x69070


def main() -> int:
    if len(sys.argv) != 3:
        print(f"usage: {Path(sys.argv[0]).name} ROM OUT_DIR", file=sys.stderr)
        return 2
    rom_path = Path(sys.argv[1])
    out_dir = Path(sys.argv[2])
    rom = rom_path.read_bytes()
    if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
        print("error: unsupported game image", file=sys.stderr)
        return 1
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "header.bin").write_bytes(rom[:0x40])
    (out_dir / "ipl3.bin").write_bytes(rom[0x40:PROGRAM_START])
    (out_dir / "main_segment.bin").write_bytes(rom[PROGRAM_START:PROGRAM_END])
    print(f"main segment: 0x{PROGRAM_START:X}..0x{PROGRAM_END:X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
