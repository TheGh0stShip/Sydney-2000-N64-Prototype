#!/usr/bin/env python3
"""Apply narrowly selected instruction scheduling fixes to KMC assembly."""

from __future__ import annotations

import argparse
from pathlib import Path
import re


def move_first_address_before_ra_save(lines: list[str]) -> list[str]:
    matches: list[int] = []
    for index in range(len(lines) - 2):
        save = lines[index].strip().replace(" ", "")
        address = lines[index + 1].strip()
        call = lines[index + 2].strip()
        if (
            save == "sw\t$31,16($sp)".replace(" ", "")
            and re.fullmatch(r"la\s+\$4,[A-Za-z_][A-Za-z0-9_]*", address)
            and call.startswith("jal\t")
        ):
            matches.append(index)

    if len(matches) != 1:
        raise ValueError(
            "expected exactly one adjacent 'sw $31,16($sp)' / 'la $4,...' pair; "
            f"found {len(matches)}"
        )

    index = matches[0]
    symbol = lines[index + 1].strip().split(",", 1)[1]
    indent = lines[index][: len(lines[index]) - len(lines[index].lstrip())]
    replacement = [
        f"{indent}.set\tnoreorder\n",
        f"{indent}lui\t$4,%hi({symbol})\n",
        lines[index],
        lines[index + 2],
        f"{indent}addiu\t$4,$4,%lo({symbol})\n",
        f"{indent}.set\treorder\n",
    ]
    lines[index : index + 3] = replacement
    return lines


def move_stack_allocation_before_global_load(lines: list[str]) -> list[str]:
    matches: list[int] = []
    for index in range(len(lines) - 1):
        load = lines[index].strip()
        allocation = lines[index + 1].strip().replace(" ", "")
        if (
            re.fullmatch(r"lw\s+\$2,[A-Za-z_][A-Za-z0-9_]*", load)
            and allocation == "subu\t$sp,$sp,24".replace(" ", "")
        ):
            matches.append(index)

    if len(matches) != 1:
        raise ValueError(
            "expected exactly one adjacent global '$2' load / 24-byte stack allocation; "
            f"found {len(matches)}"
        )

    index = matches[0]
    lines[index], lines[index + 1] = lines[index + 1], lines[index]
    return lines


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--move-first-address-before-ra-save", action="store_true")
    parser.add_argument("--move-stack-allocation-before-global-load", action="store_true")
    args = parser.parse_args()

    lines = args.input.read_text().splitlines(keepends=True)
    selected = sum(
        (
            args.move_first_address_before_ra_save,
            args.move_stack_allocation_before_global_load,
        )
    )
    if selected != 1:
        raise ValueError(f"expected exactly one normalization rule; selected {selected}")
    if args.move_first_address_before_ra_save:
        lines = move_first_address_before_ra_save(lines)
    if args.move_stack_allocation_before_global_load:
        lines = move_stack_allocation_before_global_load(lines)
    args.output.write_text("".join(lines))


if __name__ == "__main__":
    main()
