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


def move_full_address_before_ra_save(lines: list[str]) -> list[str]:
    matches: list[int] = []
    for index in range(len(lines) - 2):
        save = lines[index].strip().replace(" ", "")
        address = lines[index + 1].strip()
        directive = lines[index + 2].strip()
        if (
            save == "sw\t$31,16($sp)".replace(" ", "")
            and re.fullmatch(r"la\s+\$4,[A-Za-z_][A-Za-z0-9_]*", address)
            and directive == ".set\tnoreorder"
        ):
            matches.append(index)

    if len(matches) != 1:
        raise ValueError(
            "expected exactly one return-address save / full '$4' address pair; "
            f"found {len(matches)}"
        )

    index = matches[0]
    lines[index], lines[index + 1] = lines[index + 1], lines[index]
    return lines


def schedule_status_result_returns(lines: list[str]) -> list[str]:
    starts = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "andi\t$5,$5,0xffff"
    ]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one status mask; found {len(starts)}")
    start = starts[0]
    ends = [
        index
        for index in range(start + 1, len(lines))
        if lines[index].lstrip().startswith(".end\t")
    ]
    if len(ends) != 1:
        raise ValueError(f"expected exactly one function end after status mask; found {len(ends)}")
    end = ends[0]

    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith(".set")
    ]
    if len(body) < 2 or not re.fullmatch(r"bne\t\$5,\$0,\.L[0-9]+", body[1]):
        raise ValueError(f"unexpected status branch: {body[1:2]!r}")
    target = body[1].rsplit(",", 1)[1]
    expected = [
        "andi\t$5,$5,0xffff",
        f"bne\t$5,$0,{target}",
        "li\t$2,-1000",
        "lw\t$3,80($4)",
        "move\t$2,$0",
        "sw\t$3,0($6)",
        f"{target}:",
        "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected status-result body: {body!r}")

    lines[start:end] = [
        "\tandi\t$5,$5,0xffff\n",
        "\t.set\tnoreorder\n",
        f"\tbne\t$5,$0,{target}\n",
        "\tmove\t$2,$0\n",
        "\tlw\t$3,80($4)\n",
        "\tj\t$31\n",
        "\tsw\t$3,0($6)\n",
        f"{target}:\n",
        "\tj\t$31\n",
        "\tli\t$2,-1000\n",
        "\t.set\treorder\n",
    ]
    return lines


def load_global_halfword_through_v0(lines: list[str]) -> list[str]:
    matches: list[tuple[int, str]] = []
    for index, line in enumerate(lines):
        match = re.fullmatch(
            r"\s*lhu\s+\$4,([A-Za-z_][A-Za-z0-9_]*)\s*",
            line,
        )
        if match:
            matches.append((index, match.group(1)))

    if len(matches) != 1:
        raise ValueError(f"expected exactly one global halfword argument load; found {len(matches)}")

    index, symbol = matches[0]
    lines[index : index + 1] = [
        f"\tlui\t$2,%hi({symbol})\n",
        f"\tlhu\t$4,%lo({symbol})($2)\n",
    ]
    return lines


def reuse_global_base_after_load(lines: list[str]) -> list[str]:
    matches: list[tuple[int, str, str]] = []
    for index in range(len(lines) - 3):
        address = re.fullmatch(
            r"\s*la\s+\$5,([A-Za-z_][A-Za-z0-9_]*\+[0-9]+)\s*",
            lines[index],
        )
        branch = re.fullmatch(
            r"\s*beq\s+\$2,\$0,(\.L[0-9]+)\s*",
            lines[index + 3],
        )
        if (
            address
            and lines[index + 1].strip() == "lw\t$2,0($5)"
            and lines[index + 2].strip() == "#nop"
            and branch
        ):
            matches.append((index, address.group(1), branch.group(1)))

    if len(matches) != 1:
        raise ValueError(f"expected exactly one reusable global-base load; found {len(matches)}")

    index, expression, target = matches[0]
    lines[index : index + 4] = [
        "\t.set\tnoreorder\n",
        f"\tlui\t$2,%hi({expression})\n",
        f"\tlw\t$3,%lo({expression})($2)\n",
        f"\tbeq\t$3,$0,{target}\n",
        f"\taddiu\t$5,$2,%lo({expression})\n",
        "\t.set\treorder\n",
    ]
    return lines


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--move-first-address-before-ra-save", action="store_true")
    parser.add_argument("--move-stack-allocation-before-global-load", action="store_true")
    parser.add_argument("--move-full-address-before-ra-save", action="store_true")
    parser.add_argument("--schedule-status-result-returns", action="store_true")
    parser.add_argument("--load-global-halfword-through-v0", action="store_true")
    parser.add_argument("--reuse-global-base-after-load", action="store_true")
    args = parser.parse_args()

    lines = args.input.read_text().splitlines(keepends=True)
    selected = sum(
        (
            args.move_first_address_before_ra_save,
            args.move_stack_allocation_before_global_load,
            args.move_full_address_before_ra_save,
            args.schedule_status_result_returns,
            args.load_global_halfword_through_v0,
            args.reuse_global_base_after_load,
        )
    )
    if selected != 1:
        raise ValueError(f"expected exactly one normalization rule; selected {selected}")
    if args.move_first_address_before_ra_save:
        lines = move_first_address_before_ra_save(lines)
    if args.move_stack_allocation_before_global_load:
        lines = move_stack_allocation_before_global_load(lines)
    if args.move_full_address_before_ra_save:
        lines = move_full_address_before_ra_save(lines)
    if args.schedule_status_result_returns:
        lines = schedule_status_result_returns(lines)
    if args.load_global_halfword_through_v0:
        lines = load_global_halfword_through_v0(lines)
    if args.reuse_global_base_after_load:
        lines = reuse_global_base_after_load(lines)
    args.output.write_text("".join(lines))


if __name__ == "__main__":
    main()
