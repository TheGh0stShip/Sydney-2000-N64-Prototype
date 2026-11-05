#!/usr/bin/env python3
"""Emit an exact big-endian u32 C initializer for a reviewed ROM data range."""

from __future__ import annotations

import argparse
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--start", required=True, type=lambda value: int(value, 0))
    parser.add_argument("--size", required=True, type=lambda value: int(value, 0))
    parser.add_argument("--symbol", required=True)
    parser.add_argument("--section", required=True)
    args = parser.parse_args()

    if args.start % 4 or args.size <= 0 or args.size % 4:
        raise ValueError("u32 source ranges must be positive and four-byte aligned")
    image = args.rom.read_bytes()
    data = image[args.start:args.start + args.size]
    if len(data) != args.size:
        raise ValueError("requested range escapes ROM")

    words = [int.from_bytes(data[index:index + 4], "big")
             for index in range(0, len(data), 4)]
    lines = [
        "/* Compiler-built runtime tables: curves, state names, pointers, and storage. */",
        "typedef unsigned int u32;",
        "typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];",
        "",
        f'u32 {args.symbol}[{len(words)}] __attribute__((section("{args.section}"))) = {{',
    ]
    for index in range(0, len(words), 8):
        lines.append("    " + ", ".join(f"0x{word:08X}" for word in words[index:index + 8]) + ",")
    lines.extend(["};", ""])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines))


if __name__ == "__main__":
    main()
