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
    args.output.write_text("".join(lines))


if __name__ == "__main__":
    main()
