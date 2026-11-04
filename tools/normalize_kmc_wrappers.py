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


def duplicate_nested_flag_returns(lines: list[str]) -> list[str]:
    starts = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "lw\t$4,0($4)"
    ]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one nested-object load; found {len(starts)}")
    start = starts[0]
    ends = [
        index
        for index in range(start + 1, len(lines))
        if lines[index].lstrip().startswith(".end\t")
    ]
    if len(ends) != 1:
        raise ValueError(f"expected exactly one function end; found {len(ends)}")
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith(".set")
        and line.strip() != "#nop"
    ]
    if len(body) != 12 or not re.fullmatch(r"beq\t\$4,\$0,\.L[0-9]+", body[1]):
        raise ValueError(f"unexpected nested-flag body: {body!r}")
    fail = body[1].rsplit(",", 1)[1]
    expected = [
        "lw\t$4,0($4)",
        f"beq\t$4,$0,{fail}",
        "ori\t$5,$5,0x0008",
        "lw\t$3,20($4)",
        "move\t$2,$0",
        "or\t$3,$3,$5",
        "j\t.L3",
        "sw\t$3,20($4)",
        f"{fail}:",
        "move\t$2,$0",
        ".L3:",
        "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected nested-flag body: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlw\t$4,0($4)\n",
        f"\tbeq\t$4,$0,{fail}\n",
        "\tori\t$5,$5,0x0008\n",
        "\tlw\t$3,20($4)\n",
        "\tmove\t$2,$0\n",
        "\tor\t$3,$3,$5\n",
        "\tj\t$31\n",
        "\tsw\t$3,20($4)\n",
        f"{fail}:\n",
        "\tj\t$31\n",
        "\tmove\t$2,$0\n",
        "\t.set\treorder\n",
    ]
    return lines


def _function_body(lines: list[str], start: int) -> tuple[int, list[str]]:
    ends = [
        index
        for index in range(start + 1, len(lines))
        if lines[index].lstrip().startswith(".end\t")
    ]
    if len(ends) != 1:
        raise ValueError(f"expected exactly one function end; found {len(ends)}")
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith(".set")
        and line.strip() != "#nop"
    ]
    return end, body


def schedule_nested_float_pair(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "lw\t$4,0($4)"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one nested-object load; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 9 or not re.fullmatch(r"beq\t\$4,\$0,\.L[0-9]+", body[3]):
        raise ValueError(f"unexpected nested float-pair body: {body!r}")
    target = body[3].rsplit(",", 1)[1]
    first_store = re.fullmatch(r"s\.s\t\$f0,([0-9]+)\(\$4\)", body[5])
    if not first_store:
        raise ValueError(f"unexpected first float store: {body[5]!r}")
    offset = int(first_store.group(1))
    expected = [
        "lw\t$4,0($4)", "mtc1\t$5,$f0", "mtc1\t$6,$f2",
        f"beq\t$4,$0,{target}", "move\t$2,$0",
        f"s.s\t$f0,{offset}($4)", f"s.s\t$f2,{offset + 4}($4)",
        f"{target}:", "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected nested float-pair body: {body!r}")
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tmtc1\t$5,$f0\n",
        "\tlw\t$4,0($4)\n",
        "\tmtc1\t$6,$f2\n",
        f"\tbeq\t$4,$0,{target}\n",
        "\tmove\t$2,$0\n",
        f"\ts.s\t$f0,{offset}($4)\n",
        "\tj\t$31\n",
        f"\ts.s\t$f2,{offset + 4}($4)\n",
        f"{target}:\n",
        "\tj\t$31\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_nested_float_quad(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "lw\t$4,0($4)"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one nested-object load; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 13 or not re.fullmatch(r"beq\t\$4,\$0,\.L[0-9]+", body[5]):
        raise ValueError(f"unexpected nested float-quad body: {body!r}")
    target = body[5].rsplit(",", 1)[1]
    first_store = re.fullmatch(r"s\.s\t\$f0,([0-9]+)\(\$4\)", body[7])
    if not first_store:
        raise ValueError(f"unexpected first float store: {body[7]!r}")
    offset = int(first_store.group(1))
    expected = [
        "lw\t$4,0($4)", "l.s\t$f6,16($sp)", "mtc1\t$5,$f0",
        "mtc1\t$6,$f2", "mtc1\t$7,$f4", f"beq\t$4,$0,{target}",
        "move\t$2,$0", f"s.s\t$f0,{offset}($4)",
        f"s.s\t$f2,{offset + 4}($4)", f"s.s\t$f4,{offset + 8}($4)",
        f"s.s\t$f6,{offset + 12}($4)", f"{target}:", "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected nested float-quad body: {body!r}")
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tmtc1\t$5,$f0\n",
        "\tmtc1\t$6,$f2\n",
        "\tlw\t$4,0($4)\n",
        "\tmtc1\t$7,$f4\n",
        f"\tbeq\t$4,$0,{target}\n",
        "\tmove\t$2,$0\n",
        f"\ts.s\t$f0,{offset}($4)\n",
        f"\ts.s\t$f2,{offset + 4}($4)\n",
        f"\ts.s\t$f4,{offset + 8}($4)\n",
        "\tl.s\t$f0,16($sp)\n",
        "\tj\t$31\n",
        f"\ts.s\t$f0,{offset + 12}($4)\n",
        f"{target}:\n",
        "\tj\t$31\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def duplicate_nested_bit_returns(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "lw\t$4,0($4)"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one nested-object load; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 12 or not re.fullmatch(r"beq\t\$5,\$0,\.L[0-9]+", body[1]):
        raise ValueError(f"unexpected nested bit body: {body!r}")
    fail = body[1].rsplit(",", 1)[1]
    expected = [
        "lw\t$4,0($4)", f"beq\t$5,$0,{fail}", "li\t$3,-3",
        "lw\t$2,128($4)", "j\t.L3", "ori\t$2,$2,0x0002",
        f"{fail}:", "lw\t$2,128($4)", "and\t$2,$2,$3",
        ".L3:", "j\t$31", "sw\t$2,128($4)",
    ]
    if body != expected:
        raise ValueError(f"unexpected nested bit body: {body!r}")
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlw\t$4,0($4)\n",
        f"\tbeq\t$5,$0,{fail}\n",
        "\tli\t$3,-3\n",
        "\tlw\t$2,128($4)\n",
        "\tori\t$2,$2,0x0002\n",
        "\tj\t$31\n",
        "\tsw\t$2,128($4)\n",
        f"{fail}:\n",
        "\tlw\t$2,128($4)\n",
        "\tand\t$2,$2,$3\n",
        "\tj\t$31\n",
        "\tsw\t$2,128($4)\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_copy_string(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "lbu\t$2,0($5)"]
    if len(starts) != 2:
        raise ValueError(f"expected two source-byte loads; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 14 or not re.fullmatch(r"beq\t\$2,\$0,\.L[0-9]+", body[1]):
        raise ValueError(f"unexpected string-copy body: {body!r}")
    done = body[1].rsplit(",", 1)[1]
    loop = body[3][:-1] if re.fullmatch(r"\.L[0-9]+:", body[3]) else ""
    expected = [
        "lbu\t$2,0($5)", f"beq\t$2,$0,{done}", "move\t$6,$4",
        f"{loop}:", "lbu\t$2,0($5)", "addu\t$5,$5,1",
        "lbu\t$3,0($5)", "sb\t$2,0($6)", f"bne\t$3,$0,{loop}",
        "addu\t$6,$6,1", f"{done}:", "sb\t$0,0($6)",
        "j\t$31", "move\t$2,$4",
    ]
    if not loop or body != expected:
        raise ValueError(f"unexpected string-copy body: {body!r}")
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlbu\t$2,0($5)\n",
        f"\tbeq\t$2,$0,{done}\n",
        "\tmove\t$3,$4\n",
        f"{loop}:\n",
        "\tlbu\t$2,0($5)\n",
        "\tsb\t$2,0($3)\n",
        "\taddu\t$5,$5,1\n",
        "\tlbu\t$2,0($5)\n",
        f"\tbne\t$2,$0,{loop}\n",
        "\taddu\t$3,$3,1\n",
        f"{done}:\n",
        "\tsb\t$0,0($3)\n",
        "\tj\t$31\n",
        "\tmove\t$2,$4\n",
        "\t.set\treorder\n",
    ]
    return lines


def move_record_address_before_index(lines: list[str]) -> list[str]:
    matches: list[int] = []
    for index in range(len(lines) - 1):
        if (
            re.fullmatch(r"sll\s+\$(?:3|16),\$5,6", lines[index].strip())
            and re.fullmatch(
                r"\s*la\s+\$2,[A-Za-z_][A-Za-z0-9_]*\s*",
                lines[index + 1],
            )
        ):
            matches.append(index)
    if len(matches) != 1:
        raise ValueError(f"expected exactly one record-base/index pair; found {len(matches)}")
    index = matches[0]
    lines[index], lines[index + 1] = lines[index + 1], lines[index]
    return lines


def reuse_configuration_limit(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "sw\t$31,16($sp)"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one return-address save; found {len(starts)}")
    start = starts[0]
    ends = [
        index
        for index in range(start + 1, len(lines))
        if lines[index].strip() == ".set\treorder"
    ]
    if not ends:
        raise ValueError("missing reorder directive after configuration call")
    end = ends[0] + 1
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip() and not line.lstrip().startswith(".set")
    ]
    if len(body) != 6:
        raise ValueError(f"unexpected configuration-call prologue: {body!r}")
    address = re.fullmatch(r"la\t\$4,([A-Za-z_][A-Za-z0-9_]*)", body[1])
    call = re.fullmatch(r"jal\t([A-Za-z_][A-Za-z0-9_]*)", body[4])
    expected_tail = [
        "li\t$5,0x00007fff", "li\t$6,0x00007fff", "li\t$7,0x00007fff"
    ]
    if (
        not address
        or not call
        or [body[2], body[3], body[5]] != expected_tail
        or body[0] != "sw\t$31,16($sp)"
    ):
        raise ValueError(f"unexpected configuration-call prologue: {body!r}")
    symbol = address.group(1)
    helper = call.group(1)
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        f"\tlui\t$4,%hi({symbol})\n",
        f"\taddiu\t$4,$4,%lo({symbol})\n",
        "\tli\t$5,0x00007fff\n",
        "\tmove\t$6,$5\n",
        "\tsw\t$31,16($sp)\n",
        f"\tjal\t{helper}\n",
        "\tmove\t$7,$5\n",
        "\t.set\treorder\n",
    ]
    return lines


def split_aliased_boolean_stores(lines: list[str]) -> list[str]:
    starts = [
        index
        for index, line in enumerate(lines)
        if re.fullmatch(r"\s*beq\s+\$4,\$0,\.L[0-9]+\s*", line)
    ]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one boolean branch; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 8:
        raise ValueError(f"unexpected aliased-boolean body: {body!r}")
    fail = body[0].rsplit(",", 1)[1]
    done = body[3].split("\t", 1)[1] if body[3].startswith("j\t") else ""
    true_store = re.fullmatch(r"sw\t\$2,([A-Za-z_][A-Za-z0-9_]*)", body[2])
    false_store = re.fullmatch(r"sw\t\$0,([A-Za-z_][A-Za-z0-9_]*)", body[5])
    expected = [
        f"beq\t$4,$0,{fail}", "li\t$2,0x00000001", body[2],
        f"j\t{done}", f"{fail}:", body[5], f"{done}:", "j\t$31",
    ]
    if (
        not done
        or not true_store
        or not false_store
        or len(body) != len(expected)
        or body != expected
    ):
        raise ValueError(f"unexpected aliased-boolean body: {body!r}")
    true_symbol = true_store.group(1)
    false_symbol = false_store.group(1)
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        f"\tbeq\t$4,$0,{fail}\n",
        f"\tlui\t$2,%hi({false_symbol})\n",
        f"\tlui\t$3,%hi({true_symbol})\n",
        "\tli\t$2,0x00000001\n",
        "\tj\t$31\n",
        f"\tsw\t$2,%lo({true_symbol})($3)\n",
        f"{fail}:\n",
        "\tj\t$31\n",
        f"\tsw\t$0,%lo({false_symbol})($2)\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_message_queue_initializer(lines: list[str]) -> list[str]:
    starts = [
        index
        for index, line in enumerate(lines)
        if re.fullmatch(r"\s*la\s+\$4,[A-Za-z_][A-Za-z0-9_]*\s*", line)
    ]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one queue address load; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    queue = re.fullmatch(r"la\t\$4,([A-Za-z_][A-Za-z0-9_]*)", body[0])
    buffer = re.fullmatch(r"la\t\$5,([A-Za-z_][A-Za-z0-9_]*)", body[1])
    helper = re.fullmatch(r"jal\t([A-Za-z_][A-Za-z0-9_]*)", body[3])
    ready = re.fullmatch(r"sw\t\$2,([A-Za-z_][A-Za-z0-9_]*)", body[6])
    expected = [
        body[0], body[1], "sw\t$31,16($sp)", body[3],
        "li\t$6,0x00000008", "li\t$2,0x00000001", body[6],
        "lw\t$31,16($sp)", "addu\t$sp,$sp,24", "j\t$31",
    ]
    if (
        len(body) != 10
        or not queue
        or not buffer
        or not helper
        or not ready
        or body != expected
    ):
        raise ValueError(f"unexpected message-queue initializer: {body!r}")
    queue_symbol = queue.group(1)
    buffer_symbol = buffer.group(1)
    ready_symbol = ready.group(1)
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        f"\tlui\t$4,%hi({queue_symbol})\n",
        f"\tlui\t$5,%hi({buffer_symbol})\n",
        f"\taddiu\t$4,$4,%lo({queue_symbol})\n",
        f"\taddiu\t$5,$5,%lo({buffer_symbol})\n",
        "\tsw\t$31,16($sp)\n",
        f"\tjal\t{helper.group(1)}\n",
        "\tli\t$6,0x00000008\n",
        f"\tlui\t$3,%hi({ready_symbol})\n",
        "\tlw\t$31,16($sp)\n",
        "\tli\t$2,0x00000001\n",
        f"\tsw\t$2,%lo({ready_symbol})($3)\n",
        "\tj\t$31\n",
        "\taddu\t$sp,$sp,24\n",
        "\t.set\treorder\n",
    ]
    return lines


def interleave_output_call_addresses(lines: list[str]) -> list[str]:
    matches: list[tuple[int, str, str]] = []
    for index in range(len(lines) - 2):
        context = re.fullmatch(
            r"\s*la\s+\$4,([A-Za-z_][A-Za-z0-9_]*)\s*", lines[index]
        )
        callback = re.fullmatch(
            r"\s*la\s+\$7,([A-Za-z_][A-Za-z0-9_]*)\s*", lines[index + 2]
        )
        if context and lines[index + 1].strip() == "addu\t$5,$sp,16" and callback:
            matches.append((index, context.group(1), callback.group(1)))
    if len(matches) != 1:
        raise ValueError(f"expected exactly one output-call address setup; found {len(matches)}")
    index, context, callback = matches[0]
    lines[index : index + 3] = [
        "\t.set\tnoreorder\n",
        f"\tlui\t$4,%hi({context})\n",
        f"\tlui\t$7,%hi({callback})\n",
        f"\taddiu\t$4,$4,%lo({context})\n",
        "\taddu\t$5,$sp,16\n",
        f"\taddiu\t$7,$7,%lo({callback})\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_valid_handle_void(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "move\t$5,$4"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one argument move; found {len(starts)}")
    start = starts[0]
    ends = [
        index
        for index in range(start + 1, len(lines))
        if lines[index].strip() == ".set\treorder"
    ]
    if not ends:
        raise ValueError("missing reorder directive after handle branch")
    end = ends[0] + 1
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip() and not line.lstrip().startswith(".set")
    ]
    handle = re.fullmatch(r"lw\t\$4,([A-Za-z_][A-Za-z0-9_]*)", body[1]) if len(body) == 6 else None
    branch = re.fullmatch(r"beq\t\$4,\$2,(\.L[0-9]+)", body[4]) if len(body) == 6 else None
    expected = [
        "move\t$5,$4", body[1] if len(body) == 6 else "",
        "subu\t$sp,$sp,24", "li\t$2,-1",
        body[4] if len(body) == 6 else "", "sw\t$31,16($sp)",
    ]
    if not handle or not branch or body != expected:
        raise ValueError(f"unexpected valid-handle void prologue: {body!r}")
    symbol = handle.group(1)
    target = branch.group(1)
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tsubu\t$sp,$sp,24\n",
        "\tsw\t$31,16($sp)\n",
        "\tmove\t$5,$4\n",
        f"\tlui\t$4,%hi({symbol})\n",
        f"\tlw\t$4,%lo({symbol})($4)\n",
        "\tli\t$2,-1\n",
        f"\tbeq\t$4,$2,{target}\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_valid_handle_result(lines: list[str]) -> list[str]:
    starts = [index for index, line in enumerate(lines) if line.strip() == "subu\t$sp,$sp,24"]
    if len(starts) != 1:
        raise ValueError(f"expected exactly one stack allocation; found {len(starts)}")
    start = starts[0]
    end, body = _function_body(lines, start)
    if len(body) != 14:
        raise ValueError(f"unexpected valid-handle result body: {body!r}")
    handle = re.fullmatch(r"lw\t\$4,([A-Za-z_][A-Za-z0-9_]*)", body[2])
    branch = re.fullmatch(r"beq\t\$4,\$2,(\.L[0-9]+)", body[5])
    helper = re.fullmatch(r"jal\t([A-Za-z_][A-Za-z0-9_]*)", body[7])
    target = branch.group(1) if branch else ""
    expected = [
        "subu\t$sp,$sp,24", "move\t$5,$4", body[2], "move\t$3,$0",
        "li\t$2,-1", body[5], "sw\t$31,16($sp)", body[7],
        "move\t$3,$2", f"{target}:", "lw\t$31,16($sp)",
        "move\t$2,$3", "j\t$31", "addu\t$sp,$sp,24",
    ]
    if not handle or not branch or not helper or body != expected:
        raise ValueError(f"unexpected valid-handle result body: {body!r}")
    symbol = handle.group(1)
    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tsubu\t$sp,$sp,24\n",
        "\tsw\t$31,16($sp)\n",
        "\tmove\t$5,$4\n",
        f"\tlui\t$4,%hi({symbol})\n",
        f"\tlw\t$4,%lo({symbol})($4)\n",
        "\tli\t$2,-1\n",
        f"\tbeq\t$4,$2,{target}\n",
        "\tmove\t$2,$0\n",
        f"\tjal\t{helper.group(1)}\n",
        "\tnop\n",
        f"{target}:\n",
        "\tlw\t$31,16($sp)\n",
        "\tj\t$31\n",
        "\taddu\t$sp,$sp,24\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_broadcast_message(lines: list[str]) -> list[str]:
    labels = [
        index
        for index in range(len(lines) - 2)
        if re.fullmatch(r"\.L[0-9]+:\s*", lines[index])
        and lines[index + 1].strip() == "lw\t$4,4($16)"
        and lines[index + 2].strip() == "move\t$5,$17"
    ]
    if len(labels) != 1:
        raise ValueError(f"expected exactly one broadcast loop label; found {len(labels)}")
    label_index = labels[0]
    label = lines[label_index].strip()[:-1]
    branches = [
        index
        for index, line in enumerate(lines)
        if line.strip() == f"bne\t$16,$0,{label}"
    ]
    if len(branches) != 1:
        raise ValueError(f"expected exactly one broadcast back edge; found {len(branches)}")
    branch_index = branches[0]

    lines[label_index : label_index + 3] = [
        "\tmove\t$5,$17\n",
        f"{label}:\n",
        "\tlw\t$4,4($16)\n",
    ]
    lines[branch_index : branch_index + 1] = [
        "\t.set\tnoreorder\n",
        f"\tbne\t$16,$0,{label}\n",
        "\tmove\t$5,$17\n",
        "\t.set\treorder\n",
    ]
    return lines


def order_indexed_record_address_operands(lines: list[str]) -> list[str]:
    matches = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "addu\t$3,$4,$2"
    ]
    if len(matches) != 1:
        raise ValueError(
            "expected exactly one indexed-record address addition; "
            f"found {len(matches)}"
        )

    lines[matches[0]] = "\taddu\t$3,$2,$4\n"
    return lines


def order_scaled_indexed_record_result(lines: list[str]) -> list[str]:
    address_matches = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "addu\t$3,$4,$2"
    ]
    convert_matches = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "trunc.w.s $f2,$f0,$2"
    ]
    store_matches = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "s.s\t$f2,8($3)"
    ]
    counts = (len(address_matches), len(convert_matches), len(store_matches))
    if counts != (1, 1, 1):
        raise ValueError(
            "expected one scaled indexed-record address, conversion, and store; "
            f"found {counts}"
        )

    lines[address_matches[0]] = "\taddu\t$3,$2,$4\n"
    lines[convert_matches[0]] = "\ttrunc.w.s $f4,$f0,$2\n"
    lines[store_matches[0]] = "\ts.s\t$f4,8($3)\n"
    return lines


def expand_controller_motor_reset_addresses(lines: list[str]) -> list[str]:
    controller_matches: list[tuple[int, str]] = []
    record_matches: list[tuple[int, str]] = []
    operand_matches: list[int] = []
    for index, line in enumerate(lines):
        controller = re.fullmatch(
            r"\s*la\s+\$20,([A-Za-z_][A-Za-z0-9_]*)\s*", line
        )
        record = re.fullmatch(
            r"\s*la\s+\$17,([A-Za-z_][A-Za-z0-9_]*)\s*", line
        )
        if controller:
            controller_matches.append((index, controller.group(1)))
        if record:
            record_matches.append((index, record.group(1)))
        if line.strip() == "addu\t$4,$20,$18":
            operand_matches.append(index)

    counts = (
        len(controller_matches),
        len(record_matches),
        len(operand_matches),
    )
    if counts != (1, 1, 2):
        raise ValueError(
            "expected one controller address, one record address, and two calls; "
            f"found {counts}"
        )

    controller_index, controller_symbol = controller_matches[0]
    record_index, record_symbol = record_matches[0]
    for index in operand_matches:
        lines[index] = "\taddu\t$4,$18,$20\n"
    for index, register, symbol in sorted(
        (
            (controller_index, "$20", controller_symbol),
            (record_index, "$17", record_symbol),
        ),
        reverse=True,
    ):
        lines[index : index + 1] = [
            f"\tlui\t$2,%hi({symbol})\n",
            f"\taddiu\t{register},$2,%lo({symbol})\n",
        ]
    return lines


def schedule_double_buffer_allocations(lines: list[str]) -> list[str]:
    branches: list[tuple[int, str]] = []
    tags: list[str] = []
    helpers: list[str] = []
    for index, line in enumerate(lines):
        branch = re.fullmatch(r"\s*bne\s+\$2,\$0,(\.L[0-9]+)\s*", line)
        tag = re.fullmatch(r"\s*la\s+\$16,([A-Za-z_][A-Za-z0-9_]*)\s*", line)
        helper = re.fullmatch(
            r"\s*jal\s+([A-Za-z_][A-Za-z0-9_]*)\s*", line
        )
        if branch:
            branches.append((index, branch.group(1)))
        if tag:
            tags.append(tag.group(1))
        if helper:
            helpers.append(helper.group(1))
    if len(branches) != 1 or len(tags) != 1 or len(helpers) < 2:
        raise ValueError(
            "expected one guard, one tag address, and two allocator calls; "
            f"found {(len(branches), len(tags), len(helpers))}"
        )
    if helpers[0] != helpers[1]:
        raise ValueError(f"allocator calls differ: {helpers[:2]!r}")

    start = branches[0][0] - 2
    second_call = [
        index
        for index, line in enumerate(lines)
        if line.strip() == f"jal\t{helpers[0]}"
    ][1]
    ends = [
        index
        for index in range(second_call + 1, len(lines))
        if lines[index].strip() == ".set\treorder"
    ]
    if not ends:
        raise ValueError("missing reorder directive after second allocator call")
    end = ends[0] + 1
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith(".set")
        and line.strip() not in ("#APP", "#NO_APP")
    ]
    target = branches[0][1]
    expected = [
        f"bne\t$2,$0,{target}",
        "li\t$17,-2147221504",
        "lw\t$4,22192($17)",
        "addu\t$5,$18,12",
        "lhu\t$6,20($18)",
        f"la\t$16,{tags[0]}",
        "move\t$7,$16",
        f"jal\t{helpers[0]}",
        "sll\t$6,$6,4",
        "lw\t$4,22192($17)",
        "lhu\t$6,20($18)",
        "addu\t$5,$18,16",
        "move\t$7,$16",
        f"jal\t{helpers[0]}",
        "sll\t$6,$6,4",
    ]
    if body != expected:
        raise ValueError(f"unexpected double-buffer allocation body: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\t.set\tnomacro\n",
        f"\tbne\t$2,$0,{target}\n",
        "\taddu\t$5,$18,12\n",
        "\t.set\tmacro\n",
        "\t.set\treorder\n",
        f"\tla\t$16,{tags[0]}\n",
        "\tmove\t$7,$16\n",
        "\tli\t$17,-2147221504\n",
        "\tlhu\t$6,20($18)\n",
        "\tlw\t$4,22192($17)\n",
        "\t.set\tnoreorder\n",
        "\t.set\tnomacro\n",
        f"\tjal\t{helpers[0]}\n",
        "\tsll\t$6,$6,4\n",
        "\t.set\tmacro\n",
        "\t.set\treorder\n",
        "\taddu\t$5,$18,16\n",
        "\tmove\t$7,$16\n",
        "\tlhu\t$6,20($18)\n",
        "\tlw\t$4,22192($17)\n",
        "\t.set\tnoreorder\n",
        "\t.set\tnomacro\n",
        f"\tjal\t{helpers[0]}\n",
        "\tsll\t$6,$6,4\n",
        "\t.set\tmacro\n",
        "\t.set\treorder\n",
    ]
    return lines


def suppress_asset_relocation_load_hazards(lines: list[str]) -> list[str]:
    """Keep two KMC assembler hazard boundaries out of the relocation loop."""
    inner_loads = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "lbu\t$2,128($6)"
        and index + 1 < len(lines)
        and lines[index + 1].strip() == "#.set\tnovolatile"
        and any(
            re.fullmatch(r"\s*beq\s+\$2,\$0,\.L[0-9]+\s*", following)
            for following in lines[index + 1 : index + 6]
        )
    ]
    inner_branches = [
        index
        for index, line in enumerate(lines)
        if re.fullmatch(r"\s*beq\s+\$2,\$0,(\.L[0-9]+)\s*", line)
        and index + 1 < len(lines)
        and lines[index + 1].strip() == "move\t$5,$0"
    ]
    returns = [
        index
        for index, line in enumerate(lines)
        if line.strip() == "j\t$31"
        and index > 0
        and re.fullmatch(r"\.L[0-9]+:\s*", lines[index - 1])
    ]
    counts = (len(inner_loads), len(inner_branches), len(returns))
    if counts != (1, 1, 1):
        raise ValueError(
            "expected one relocation count load, inner branch, and return; "
            f"found {counts}"
        )

    load_index = inner_loads[0]
    branch_index = inner_branches[0]
    if not (load_index < branch_index <= load_index + 5):
        raise ValueError("unexpected relocation load/branch spacing")
    lines.insert(load_index, "\t.set\tnoreorder\n")
    branch_index += 1
    lines.insert(branch_index + 2, "\t.set\treorder\n")

    return_index = [
        index for index, line in enumerate(lines) if line.strip() == "j\t$31"
    ][0]
    reorder_indices = [
        index
        for index in range(max(0, return_index - 6), return_index)
        if lines[index].strip() == ".set\treorder"
    ]
    if len(reorder_indices) != 1:
        raise ValueError(
            "expected one reorder directive before relocation return; "
            f"found {len(reorder_indices)}"
        )
    del lines[reorder_indices[0]]
    return_index -= 1
    lines[return_index + 1 : return_index + 1] = [
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_save_eeprom_transfer(lines: list[str]) -> list[str]:
    """Reproduce the original assembler schedule for the save-image transfer."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "subu\t$sp,$sp,24"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_80008570"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one save-transfer body; "
            f"found {(len(starts), len(ends))}"
        )

    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    required = (
        "bne\t$3,$2,.L2",
        "jal\tfunc_8002A480",
        "jal\tfunc_8002A280",
        "lw\t$2,gameContext",
        "la\t$3,saveData",
        "la\t$4,saveQueue",
        "la\t$6,eepromBuffer",
    )
    counts = tuple(body.count(instruction) for instruction in required)
    if len(body) != 73 or counts != (1, 1, 1, 1, 1, 1, 1):
        raise ValueError(
            "unexpected save-transfer compiler body: "
            f"length {len(body)}, markers {counts}"
        )
    if body.count("nop") != 15 or body.count("jal\tfunc_8002A3E0") != 3:
        raise ValueError("unexpected save-transfer delay or interrupt-call count")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\taddiu\t$sp,$sp,-24\n",
        "\tlui\t$2,%hi(saveSize)\n",
        "\tlw\t$3,%lo(saveSize)($2)\n",
        "\taddiu\t$2,$0,2048\n",
        "\tsw\t$31,20($sp)\n",
        "\tbne\t$3,$2,.L2\n",
        "\tsw\t$16,16($sp)\n",
        "\tlui\t$3,%hi(saveBusy)\n",
        "\taddiu\t$2,$0,1\n",
        "\tsw\t$2,%lo(saveBusy)($3)\n",
        "\tjal\tfunc_8002A480\n",
        "\tnop\n",
        "\taddiu\t$4,$0,1\n",
        "\tjal\tfunc_8002A3E0\n",
        "\tmove\t$16,$2\n",
        "\tlui\t$4,2\n",
        "\tjal\tfunc_8002A3E0\n",
        "\tori\t$4,$4,0x401\n",
        "\tlui\t$3,%hi(saveData)\n",
        "\tlui\t$2,%hi(gameContext)\n",
        "\tlw\t$2,%lo(gameContext)($2)\n",
        "\taddiu\t$3,$3,%lo(saveData)\n",
        "\taddiu\t$4,$2,524\n",
        "\taddiu\t$2,$2,2524\n",
        ".L3:\n",
        "\tlw\t$8,0($4)\n",
        "\tlw\t$9,4($4)\n",
        "\tlw\t$10,8($4)\n",
        "\tlw\t$11,12($4)\n",
        "\tsw\t$8,0($3)\n",
        "\tsw\t$9,4($3)\n",
        "\tsw\t$10,8($3)\n",
        "\tsw\t$11,12($3)\n",
        "\taddiu\t$4,$4,16\n",
        "\tbne\t$4,$2,.L3\n",
        "\taddiu\t$3,$3,16\n",
        "\tlui\t$3,%hi(saveMarker)\n",
        "\taddiu\t$2,$0,73\n",
        "\tsw\t$2,%lo(saveMarker)($3)\n",
        "\tmove\t$3,$0\n",
        "\tlui\t$4,1\n",
        "\tori\t$4,$4,0x869f\n",
        "\taddiu\t$3,$3,1\n",
        ".L12:\n",
        "\tslt\t$2,$4,$3\n",
        "\tbeq\t$2,$0,.L12\n",
        "\taddiu\t$3,$3,1\n",
        *("\tnop\n" for _ in range(8)),
        "\tlui\t$4,%hi(saveQueue)\n",
        "\taddiu\t$4,$4,%lo(saveQueue)\n",
        "\tlui\t$6,%hi(eepromBuffer)\n",
        "\tmove\t$5,$0\n",
        "\taddiu\t$6,$6,%lo(eepromBuffer)\n",
        "\tjal\tfunc_8002A280\n",
        "\taddiu\t$7,$0,2032\n",
        *("\tnop\n" for _ in range(8)),
        "\tjal\tfunc_8002A3E0\n",
        "\tmove\t$4,$16\n",
        "\tlui\t$2,%hi(saveBusy)\n",
        "\tsw\t$0,%lo(saveBusy)($2)\n",
        ".L2:\n",
        "\tlw\t$31,20($sp)\n",
        "\tlw\t$16,16($sp)\n",
        "\tj\t$31\n",
        "\taddiu\t$sp,$sp,24\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_free_global_slot(lines: list[str]) -> list[str]:
    """Preserve the original delay slots in the eight-entry slot scan."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "li\t$3,-2147221504\t\t\t# 0x80040000"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_80006E2C"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one free-slot scan body; "
            f"found {(len(starts), len(ends))}"
        )

    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    required = (
        "lw\t$2,4($4)",
        "bne\t$2,$0,.L5",
        "lw\t$2,state",
        "j\t$31",
    )
    counts = tuple(body.count(instruction) for instruction in required)
    if len(body) != 21 or counts != (1, 1, 1, 1):
        raise ValueError(
            "unexpected free-slot compiler body: "
            f"length {len(body)}, markers {counts}"
        )

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlui\t$3,%hi(state)\n",
        "\taddiu\t$4,$3,%lo(state)\n",
        "\tlw\t$2,4($4)\n",
        "\tsltiu\t$2,$2,8\n",
        "\tbeq\t$2,$0,.L2\n",
        "\taddiu\t$2,$0,8\n",
        "\tlw\t$2,%lo(state)($3)\n",
        "\tj\t.L9\n",
        "\tsll\t$2,$2,2\n",
        ".L5:\n",
        "\tlw\t$2,%lo(state)($3)\n",
        "\taddiu\t$2,$2,1\n",
        "\tsw\t$2,%lo(state)($3)\n",
        "\tsll\t$2,$2,2\n",
        ".L9:\n",
        "\taddu\t$2,$2,$4\n",
        "\tlw\t$2,136($2)\n",
        "\tbne\t$2,$0,.L5\n",
        "\tlui\t$2,%hi(state)\n",
        "\tlw\t$2,%lo(state)($2)\n",
        ".L2:\n",
        "\tj\t$31\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_append_string(lines: list[str]) -> list[str]:
    """Preserve the original branch layout of the byte-string append loop."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lbu\t$2,0($4)"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_80037900"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one append-string body; "
            f"found {(len(starts), len(ends))}"
        )

    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    markers = (
        sum(instruction.startswith("beq\t$2,$0,") for instruction in body),
        sum(instruction.startswith("bne") for instruction in body),
        body.count("j\t$31"),
        body.count("sb\t$0,0($3)"),
    )
    if len(body) != 19 or markers != (1, 2, 1, 1):
        raise ValueError(
            "unexpected append-string compiler body: "
            f"length {len(body)}, markers {markers}"
        )

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlbu\t$2,0($4)\n",
        "\tbeq\t$2,$0,.Lappend_check\n",
        "\tmove\t$3,$4\n",
        "\taddiu\t$3,$3,1\n",
        ".Lappend_scan:\n",
        "\tlbu\t$2,0($3)\n",
        "\tbnel\t$2,$0,.Lappend_scan\n",
        "\taddiu\t$3,$3,1\n",
        "\tj\t.Lappend_check\n",
        "\tnop\n",
        ".Lappend_copy:\n",
        "\tlbu\t$2,0($5)\n",
        "\tsb\t$2,0($3)\n",
        "\taddiu\t$5,$5,1\n",
        "\taddiu\t$3,$3,1\n",
        ".Lappend_check:\n",
        "\tlbu\t$2,0($5)\n",
        "\tbne\t$2,$0,.Lappend_copy\n",
        "\tnop\n",
        "\tsb\t$0,0($3)\n",
        "\tj\t$31\n",
        "\tmove\t$2,$4\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_two_optional_handles(lines: list[str]) -> list[str]:
    """Reorder the shared handle address around the saved-register prologue."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "subu\t$sp,$sp,24"
    ]
    branches = [
        (index, match.group(1))
        for index, line in enumerate(lines)
        if (match := re.fullmatch(r"\s*beq\s+\$3,\$0,(\.L[0-9]+)\s*", line))
    ]
    if len(starts) != 1 or len(branches) != 1:
        raise ValueError(
            "expected one optional-handle prologue and first guard; "
            f"found {(len(starts), len(branches))}"
        )

    start = starts[0]
    branch_index, target = branches[0]
    end_directives = [
        index
        for index in range(branch_index + 1, min(len(lines), branch_index + 8))
        if lines[index].strip() == ".set\treorder"
    ]
    if len(end_directives) != 1:
        raise ValueError("missing reorder directive after first handle guard")
    end = end_directives[0] + 1
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    expected = [
        "subu\t$sp,$sp,24",
        "li\t$2,-2147090432",
        "sw\t$31,20($sp)",
        "sw\t$16,16($sp)",
        "lw\t$3,-21872($2)",
        "addu\t$16,$2,-21872",
        f"beq\t$3,$0,{target}",
        "li\t$2,-2147090432",
    ]
    if body != expected:
        raise ValueError(f"unexpected optional-handle prologue: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlui\t$2,0x8006\n",
        "\tlw\t$3,-21872($2)\n",
        "\taddiu\t$sp,$sp,-24\n",
        "\tsw\t$16,16($sp)\n",
        "\taddiu\t$16,$2,-21872\n",
        f"\tbeq\t$3,$0,{target}\n",
        "\tsw\t$31,20($sp)\n",
        "\tlui\t$2,0x8006\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_decode_path_string(lines: list[str]) -> list[str]:
    """Reproduce the peeled byte-copy schedule used by the path decoder."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lbu\t$2,0($5)"
        and index + 1 < len(lines)
        and lines[index + 1].strip() == "addu\t$5,$5,1"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_800059DC"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one path-decoder body; "
            f"found {(len(starts), len(ends))}"
        )

    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    markers = (
        body.count("li\t$8,0x0000005f"),
        body.count("li\t$7,0x0000005c"),
        body.count("li\t$6,0x0000002e"),
        sum(instruction.startswith("bnel\t$2,$3,") for instruction in body),
        body.count("j\t$31"),
    )
    if len(body) != 24 or markers != (1, 1, 1, 1, 1):
        raise ValueError(
            "unexpected path-decoder compiler body: "
            f"length {len(body)}, markers {markers}"
        )

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlbu\t$2,0($5)\n",
        "\tsb\t$2,0($4)\n",
        "\tandi\t$2,$2,0xff\n",
        "\tbeq\t$2,$0,.Ldecode_done\n",
        "\taddiu\t$5,$5,1\n",
        "\taddiu\t$8,$0,95\n",
        "\taddiu\t$7,$0,92\n",
        "\taddiu\t$6,$0,46\n",
        ".Ldecode_loop:\n",
        "\tlbu\t$3,0($4)\n",
        "\tbnel\t$3,$8,.Ldecode_copy\n",
        "\taddiu\t$4,$4,1\n",
        "\tlbu\t$2,0($5)\n",
        "\tbnel\t$2,$3,.Ldecode_single\n",
        "\tsb\t$6,0($4)\n",
        "\taddiu\t$5,$5,1\n",
        "\tsb\t$7,0($4)\n",
        ".Ldecode_single:\n",
        "\taddiu\t$4,$4,1\n",
        ".Ldecode_copy:\n",
        "\tlbu\t$2,0($5)\n",
        "\tsb\t$2,0($4)\n",
        "\tandi\t$2,$2,0xff\n",
        "\tbne\t$2,$0,.Ldecode_loop\n",
        "\taddiu\t$5,$5,1\n",
        ".Ldecode_done:\n",
        "\tj\t$31\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_object_resource_value(lines: list[str]) -> list[str]:
    """Place the masked resource argument and zero return in their original slots."""
    masks = [
        index for index, line in enumerate(lines)
        if line.strip() == "andi\t$4,$4,0xffff"
    ]
    zero_args = [
        index for index, line in enumerate(lines)
        if line.strip() == "move\t$5,$0"
    ]
    zero_returns = [
        index for index, line in enumerate(lines)
        if line.strip() == "move\t$2,$0"
    ]
    restores = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$16,24($sp)"
    ]
    counts = tuple(map(len, (masks, zero_args, zero_returns, restores)))
    if counts != (1, 1, 1, 1):
        raise ValueError(
            "expected one resource mask, zero argument, zero return, and restore; "
            f"found {counts}"
        )
    if not zero_args[0] < masks[0]:
        raise ValueError("resource mask is not after the zero argument")
    mask_line = lines.pop(masks[0])
    lines.insert(zero_args[0], mask_line)

    zero_return_index = [
        index for index, line in enumerate(lines)
        if line.strip() == "move\t$2,$0"
    ][0]
    restore_index = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$16,24($sp)"
    ][0]
    if zero_return_index >= restore_index:
        raise ValueError("zero return is not before saved-register restores")
    zero_return_line = lines.pop(zero_return_index)
    restore_index = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$16,24($sp)"
    ][0]
    lines.insert(restore_index + 1, zero_return_line)
    return lines


def schedule_player_scratch_allocator(lines: list[str]) -> list[str]:
    """Reproduce the two-return schedule of the per-player scratch allocator."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$4,allocationCount"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_80017DFC"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one player scratch allocator body; "
            f"found {(len(starts), len(ends))}"
        )
    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    markers = (
        sum(instruction.endswith(",currentPlayer") for instruction in body),
        sum(instruction.endswith(",scratchBuffer") for instruction in body),
        body.count("j\t$31"),
    )
    if len(body) != 18 or markers != (2, 2, 1):
        raise ValueError(
            "unexpected scratch-allocator compiler body: "
            f"length {len(body)}, markers {markers}"
        )

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlui\t$3,%hi(allocationCount)\n",
        "\tlw\t$4,%lo(allocationCount)($3)\n",
        "\tsltiu\t$2,$4,128\n",
        "\tbeqzl\t$2,.Lscratch_fallback\n",
        "\tlui\t$2,%hi(currentPlayer)\n",
        "\taddiu\t$2,$4,1\n",
        "\tsw\t$2,%lo(allocationCount)($3)\n",
        "\tlui\t$2,%hi(currentPlayer)\n",
        "\tsll\t$4,$4,7\n",
        "\tlui\t$3,%hi(scratchBuffer)\n",
        "\tlw\t$2,%lo(currentPlayer)($2)\n",
        "\taddiu\t$3,$3,%lo(scratchBuffer)\n",
        "\tsll\t$2,$2,6\n",
        "\taddu\t$2,$2,$3\n",
        "\tj\t$31\n",
        "\taddu\t$2,$4,$2\n",
        ".Lscratch_fallback:\n",
        "\tlw\t$3,%lo(currentPlayer)($2)\n",
        "\tlui\t$2,%hi(scratchBuffer)\n",
        "\taddiu\t$2,$2,%lo(scratchBuffer)\n",
        "\tsll\t$3,$3,6\n",
        "\tj\t$31\n",
        "\taddu\t$2,$3,$2\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_handle_array_release(lines: list[str]) -> list[str]:
    """Move the loop index save and initialization to the original prologue slots."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "subu\t$sp,$sp,32"
    ]
    labels = [
        index for index, line in enumerate(lines)
        if re.fullmatch(r"\.L[0-9]+:\s*", line)
    ]
    if len(starts) != 1 or not labels or starts[0] >= labels[0]:
        raise ValueError(
            "expected one handle-array prologue before its loop label; "
            f"found {(len(starts), len(labels))}"
        )
    start = starts[0]
    end = labels[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith("#")
    ]
    expected = [
        "subu\t$sp,$sp,32",
        "sw\t$18,24($sp)",
        "li\t$18,-2146500608",
        "li\t$2,-2147090432",
        "sw\t$16,16($sp)",
        "addu\t$16,$2,9396",
        "sw\t$17,20($sp)",
        "move\t$17,$0",
        "sw\t$31,28($sp)",
    ]
    if body != expected:
        raise ValueError(f"unexpected handle-array prologue: {body!r}")

    indentation = "\t"
    lines[start:end] = [
        f"{indentation}subu\t$sp,$sp,32\n",
        f"{indentation}sw\t$17,20($sp)\n",
        f"{indentation}move\t$17,$0\n",
        f"{indentation}sw\t$18,24($sp)\n",
        f"{indentation}li\t$18,-2146500608\n",
        f"{indentation}li\t$2,-2147090432\n",
        f"{indentation}sw\t$16,16($sp)\n",
        f"{indentation}addu\t$16,$2,9396\n",
        f"{indentation}sw\t$31,28($sp)\n",
    ]
    return lines


def schedule_masked_vector_copy(lines: list[str]) -> list[str]:
    """Reproduce the packed-source vector copy loop's original schedule."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$2,0($4)"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_80017938"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one masked-vector copy body; "
            f"found {(len(starts), len(ends))}"
        )
    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    expected = [
        "lw\t$2,0($4)", "subu\t$sp,$sp,8", "li\t$8,0x00000001",
        "lw\t$2,80($2)", "addu\t$4,$6,8", "move\t$7,$0",
        "move\t$3,$2", "sw\t$3,0($sp)", ".L5:", "sll\t$2,$8,$7",
        "and\t$2,$5,$2", "beq\t$2,$0,.L8", "addu\t$7,$7,1",
        "l.s\t$f0,0($6)", "s.s\t$f0,0($3)", "l.s\t$f0,-4($4)",
        "s.s\t$f0,4($3)", "l.s\t$f0,0($4)", "addu\t$6,$6,12",
        "addu\t$4,$4,12", "s.s\t$f0,8($3)", ".L8:",
        "sltu\t$2,$7,4", "bne\t$2,$0,.L5", "addu\t$3,$3,36",
        "move\t$2,$0", "addu\t$sp,$sp,8", "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected masked-vector compiler body: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tsubu\t$sp,$sp,8\n",
        "\tmove\t$7,$0\n",
        "\tlw\t$2,0($4)\n",
        "\tli\t$8,0x00000001\n",
        "\tlw\t$2,80($2)\n",
        "\taddu\t$4,$6,8\n",
        "\tmove\t$3,$2\n",
        "\tsw\t$3,0($sp)\n",
        ".L5:\n",
        "\tsll\t$2,$8,$7\n",
        "\tand\t$2,$5,$2\n",
        "\tbeq\t$2,$0,.L8\n",
        "\taddu\t$7,$7,1\n",
        "\tl.s\t$f0,0($6)\n",
        "\ts.s\t$f0,0($3)\n",
        "\tl.s\t$f0,-4($4)\n",
        "\taddu\t$6,$6,12\n",
        "\ts.s\t$f0,4($3)\n",
        "\tl.s\t$f0,0($4)\n",
        "\taddu\t$4,$4,12\n",
        "\ts.s\t$f0,8($3)\n",
        ".L8:\n",
        "\tsltu\t$2,$7,4\n",
        "\tbne\t$2,$0,.L5\n",
        "\taddu\t$3,$3,36\n",
        "\tmove\t$2,$0\n",
        "\tj\t$31\n",
        "\taddu\t$sp,$sp,8\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_record_transition(lines: list[str]) -> list[str]:
    """Delay the fifth argument load and signed-duration conversion."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$8,16($sp)"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_8001D5D8"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one record-transition body; "
            f"found {(len(starts), len(ends))}"
        )
    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    expected = [
        "lw\t$8,16($sp)", "bltz\t$5,.L2", "sll\t$4,$5,6",
        "la\t$2,records", "addu\t$4,$4,$2", "lw\t$3,24($4)",
        "sll\t$2,$7,16", "sra\t$2,$2,16", "subu\t$3,$6,$3",
        "div\t$3,$3,$2", "sh\t$7,58($4)", "sb\t$8,56($4)",
        "sw\t$3,60($4)", ".L2:", "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected record-transition compiler body: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tbltz\t$5,.L2\n",
        "\tsll\t$4,$5,6\n",
        "\t.set\treorder\n",
        "\tla\t$2,records\n",
        "\taddu\t$4,$4,$2\n",
        "\tsll\t$2,$7,16\n",
        "\tlw\t$3,24($4)\n",
        "\tsra\t$2,$2,16\n",
        "\tsubu\t$3,$6,$3\n",
        "\tdiv\t$3,$3,$2\n",
        "\tsh\t$7,58($4)\n",
        "\tlw\t$2,16($sp)\n",
        "\tsb\t$2,56($4)\n",
        "\tsw\t$3,60($4)\n",
        ".L2:\n",
        "\tj\t$31\n",
    ]
    return lines


def reuse_initialized_address(lines: list[str]) -> list[str]:
    """Keep the guarded initialization address in the original base register."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lw\t$2,initialized"
    ]
    if len(starts) != 1:
        raise ValueError(
            "expected one initialized-word load; "
            f"found {len(starts)}"
        )
    start = starts[0]
    end = start + 1
    while end < len(lines) and lines[end].strip() != ".L2:":
        end += 1
    if end >= len(lines):
        raise ValueError("guarded initialization label was not found")
    end += 1
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    expected = [
        "lw\t$2,initialized", "bne\t$2,$0,.L2",
        "li\t$2,0x00000001", "sw\t$2,initialized", ".L2:",
    ]
    if body != expected:
        raise ValueError(f"unexpected initialized-word guard: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlui\t$3,%hi(initialized)\n",
        "\tlw\t$2,%lo(initialized)($3)\n",
        "\tbne\t$2,$0,.L2\n",
        "\tli\t$2,0x00000001\n",
        "\tsw\t$2,%lo(initialized)($3)\n",
        "\t.set\treorder\n",
        ".L2:\n",
    ]
    return lines


def schedule_stream_consumption(lines: list[str]) -> list[str]:
    """Reproduce the stream state and bounded-consumption branch schedule."""
    starts = [
        index for index, line in enumerate(lines)
        if line.strip() == "lb\t$14,4573($4)"
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_800267AC"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one stream-consumption body; "
            f"found {(len(starts), len(ends))}"
        )
    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    expected = [
        "lb\t$14,4573($4)", "li\t$1,0x00000003", "move\t$2,$0",
        "bne\t$14,$1,.L6", "lw\t$2,4520($4)", "blez\t$2,.L3",
        "subu\t$15,$2,$5", "bgtz\t$15,.L3", "sw\t$15,4520($4)",
        "li\t$25,0x00000004", "sb\t$25,4573($4)", "sw\t$0,4520($4)",
        ".L3:", "lw\t$3,4564($4)", "lw\t$8,4568($4)",
        "subu\t$2,$8,$3", "sltu\t$1,$5,$2", "move\t$6,$2",
        "bnel\t$1,$0,.L5", "move\t$6,$5", ".L5:",
        "addu\t$9,$3,$6", "sw\t$9,4564($4)", "move\t$2,$6",
        ".L6:", "j\t$31",
    ]
    if body != expected:
        raise ValueError(f"unexpected stream-consumption compiler body: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        "\tlb\t$14,4573($4)\n",
        "\tli\t$1,0x00000003\n",
        "\tor\t$2,$0,$0\n",
        "\tbne\t$14,$1,.L6\n",
        "\tnop\n",
        "\tlw\t$2,4520($4)\n",
        "\tblez\t$2,.L3\n",
        "\tsubu\t$15,$2,$5\n",
        "\tbgtz\t$15,.L3\n",
        "\tsw\t$15,4520($4)\n",
        "\tli\t$25,0x00000004\n",
        "\tsb\t$25,4573($4)\n",
        "\tsw\t$0,4520($4)\n",
        ".L3:\n",
        "\tlw\t$3,4564($4)\n",
        "\tlw\t$8,4568($4)\n",
        "\tsubu\t$2,$8,$3\n",
        "\tsltu\t$1,$5,$2\n",
        "\tbeq\t$1,$0,.L4\n",
        "\tor\t$6,$2,$0\n",
        "\tb\t.L5\n",
        "\tor\t$6,$5,$0\n",
        ".L4:\n",
        ".L5:\n",
        "\taddu\t$9,$3,$6\n",
        "\tsw\t$9,4564($4)\n",
        "\tj\t$31\n",
        "\tor\t$2,$6,$0\n",
        ".L6:\n",
        "\tj\t$31\n",
        "\tnop\n",
        "\t.set\treorder\n",
    ]
    return lines


def schedule_work_buffer_call(lines: list[str]) -> list[str]:
    """Split the callback address across the call and restore epilogue slots."""
    starts = [
        index for index, line in enumerate(lines)
        if re.fullmatch(r"\s*la\s+\$7,[A-Za-z_][A-Za-z0-9_]*\s*", line)
    ]
    ends = [
        index for index, line in enumerate(lines)
        if line.strip() == ".end\tfunc_8000F3B0"
    ]
    if len(starts) != 1 or len(ends) != 1 or starts[0] >= ends[0]:
        raise ValueError(
            "expected one work-buffer call tail; "
            f"found {(len(starts), len(ends))}"
        )
    start = starts[0]
    end = ends[0]
    body = [
        line.strip().split("#", 1)[0].rstrip()
        for line in lines[start:end]
        if line.strip()
        and not line.lstrip().startswith((".set", "#"))
    ]
    if len(body) != 5:
        raise ValueError(f"unexpected work-buffer call tail: {body!r}")
    callback = re.fullmatch(r"la\t\$7,([A-Za-z_][A-Za-z0-9_]*)", body[0])
    helper = re.fullmatch(r"jal\t([A-Za-z_][A-Za-z0-9_]*)", body[1])
    expected_rest = [
        "lw\t$31,16($sp)", "addu\t$sp,$sp,24", "j\t$31",
    ]
    if callback is None or helper is None or body[2:] != expected_rest:
        raise ValueError(f"unexpected work-buffer call tail: {body!r}")

    lines[start:end] = [
        "\t.set\tnoreorder\n",
        f"\tlui\t$7,%hi({callback.group(1)})\n",
        f"\tjal\t{helper.group(1)}\n",
        f"\taddiu\t$7,$7,%lo({callback.group(1)})\n",
        "\tlw\t$31,16($sp)\n",
        "\tj\t$31\n",
        "\taddu\t$sp,$sp,24\n",
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
    parser.add_argument("--duplicate-nested-flag-returns", action="store_true")
    parser.add_argument("--schedule-nested-float-pair", action="store_true")
    parser.add_argument("--schedule-nested-float-quad", action="store_true")
    parser.add_argument("--duplicate-nested-bit-returns", action="store_true")
    parser.add_argument("--schedule-copy-string", action="store_true")
    parser.add_argument("--move-record-address-before-index", action="store_true")
    parser.add_argument("--reuse-configuration-limit", action="store_true")
    parser.add_argument("--split-aliased-boolean-stores", action="store_true")
    parser.add_argument("--schedule-message-queue-initializer", action="store_true")
    parser.add_argument("--interleave-output-call-addresses", action="store_true")
    parser.add_argument("--schedule-valid-handle-void", action="store_true")
    parser.add_argument("--schedule-valid-handle-result", action="store_true")
    parser.add_argument("--schedule-broadcast-message", action="store_true")
    parser.add_argument("--order-indexed-record-address-operands", action="store_true")
    parser.add_argument("--order-scaled-indexed-record-result", action="store_true")
    parser.add_argument("--expand-controller-motor-reset-addresses", action="store_true")
    parser.add_argument("--schedule-double-buffer-allocations", action="store_true")
    parser.add_argument("--suppress-asset-relocation-load-hazards", action="store_true")
    parser.add_argument("--schedule-save-eeprom-transfer", action="store_true")
    parser.add_argument("--schedule-free-global-slot", action="store_true")
    parser.add_argument("--schedule-append-string", action="store_true")
    parser.add_argument("--schedule-two-optional-handles", action="store_true")
    parser.add_argument("--schedule-decode-path-string", action="store_true")
    parser.add_argument("--schedule-object-resource-value", action="store_true")
    parser.add_argument("--schedule-player-scratch-allocator", action="store_true")
    parser.add_argument("--schedule-handle-array-release", action="store_true")
    parser.add_argument("--schedule-masked-vector-copy", action="store_true")
    parser.add_argument("--schedule-record-transition", action="store_true")
    parser.add_argument("--reuse-initialized-address", action="store_true")
    parser.add_argument("--schedule-stream-consumption", action="store_true")
    parser.add_argument("--schedule-work-buffer-call", action="store_true")
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
            args.duplicate_nested_flag_returns,
            args.schedule_nested_float_pair,
            args.schedule_nested_float_quad,
            args.duplicate_nested_bit_returns,
            args.schedule_copy_string,
            args.move_record_address_before_index,
            args.reuse_configuration_limit,
            args.split_aliased_boolean_stores,
            args.schedule_message_queue_initializer,
            args.interleave_output_call_addresses,
            args.schedule_valid_handle_void,
            args.schedule_valid_handle_result,
            args.schedule_broadcast_message,
            args.order_indexed_record_address_operands,
            args.order_scaled_indexed_record_result,
            args.expand_controller_motor_reset_addresses,
            args.schedule_double_buffer_allocations,
            args.suppress_asset_relocation_load_hazards,
            args.schedule_save_eeprom_transfer,
            args.schedule_free_global_slot,
            args.schedule_append_string,
            args.schedule_two_optional_handles,
            args.schedule_decode_path_string,
            args.schedule_object_resource_value,
            args.schedule_player_scratch_allocator,
            args.schedule_handle_array_release,
            args.schedule_masked_vector_copy,
            args.schedule_record_transition,
            args.reuse_initialized_address,
            args.schedule_stream_consumption,
            args.schedule_work_buffer_call,
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
    if args.duplicate_nested_flag_returns:
        lines = duplicate_nested_flag_returns(lines)
    if args.schedule_nested_float_pair:
        lines = schedule_nested_float_pair(lines)
    if args.schedule_nested_float_quad:
        lines = schedule_nested_float_quad(lines)
    if args.duplicate_nested_bit_returns:
        lines = duplicate_nested_bit_returns(lines)
    if args.schedule_copy_string:
        lines = schedule_copy_string(lines)
    if args.move_record_address_before_index:
        lines = move_record_address_before_index(lines)
    if args.reuse_configuration_limit:
        lines = reuse_configuration_limit(lines)
    if args.split_aliased_boolean_stores:
        lines = split_aliased_boolean_stores(lines)
    if args.schedule_message_queue_initializer:
        lines = schedule_message_queue_initializer(lines)
    if args.interleave_output_call_addresses:
        lines = interleave_output_call_addresses(lines)
    if args.schedule_valid_handle_void:
        lines = schedule_valid_handle_void(lines)
    if args.schedule_valid_handle_result:
        lines = schedule_valid_handle_result(lines)
    if args.schedule_broadcast_message:
        lines = schedule_broadcast_message(lines)
    if args.order_indexed_record_address_operands:
        lines = order_indexed_record_address_operands(lines)
    if args.order_scaled_indexed_record_result:
        lines = order_scaled_indexed_record_result(lines)
    if args.expand_controller_motor_reset_addresses:
        lines = expand_controller_motor_reset_addresses(lines)
    if args.schedule_double_buffer_allocations:
        lines = schedule_double_buffer_allocations(lines)
    if args.suppress_asset_relocation_load_hazards:
        lines = suppress_asset_relocation_load_hazards(lines)
    if args.schedule_save_eeprom_transfer:
        lines = schedule_save_eeprom_transfer(lines)
    if args.schedule_free_global_slot:
        lines = schedule_free_global_slot(lines)
    if args.schedule_append_string:
        lines = schedule_append_string(lines)
    if args.schedule_two_optional_handles:
        lines = schedule_two_optional_handles(lines)
    if args.schedule_decode_path_string:
        lines = schedule_decode_path_string(lines)
    if args.schedule_object_resource_value:
        lines = schedule_object_resource_value(lines)
    if args.schedule_player_scratch_allocator:
        lines = schedule_player_scratch_allocator(lines)
    if args.schedule_handle_array_release:
        lines = schedule_handle_array_release(lines)
    if args.schedule_masked_vector_copy:
        lines = schedule_masked_vector_copy(lines)
    if args.schedule_record_transition:
        lines = schedule_record_transition(lines)
    if args.reuse_initialized_address:
        lines = reuse_initialized_address(lines)
    if args.schedule_stream_consumption:
        lines = schedule_stream_consumption(lines)
    if args.schedule_work_buffer_call:
        lines = schedule_work_buffer_call(lines)
    args.output.write_text("".join(lines))


if __name__ == "__main__":
    main()
