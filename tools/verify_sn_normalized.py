#!/usr/bin/env python3
"""Compile and verify reviewed SN operand-order variants."""

from __future__ import annotations

import argparse
import hashlib
import shlex
import struct
import subprocess
import tempfile
from pathlib import Path

from n64dk.elf import Elf
from n64dk.match.compare import compare_object
from n64dk.match.symbols import load
from n64dk.match.toolchain import load_config


ROM_TO_VRAM = 0x7FFFF400


def run(command: list[str], cwd: Path) -> None:
    result = subprocess.run(command, cwd=cwd, capture_output=True, text=True)
    if result.returncode:
        detail = (result.stderr or result.stdout).strip()
        raise RuntimeError(f"{Path(command[0]).name} failed: {detail}")


def normalize_shadow_operands(elf: Elf) -> None:
    text = elf.section(".text")
    if text is None:
        raise ValueError("object has no .text section")
    reviewed = {
        0x3B4: (0x46024202, 0x46081202),
        0x600: (0x46024202, 0x46081202),
    }
    body = bytearray(text.data)
    relocations = {offset for offset, *_ in elf.relocations(text)}
    for offset, (compiled, expected) in reviewed.items():
        actual = struct.unpack_from(">I", text.data, offset)[0]
        if actual != compiled:
            raise ValueError(
                f"reviewed word at 0x{offset:X} changed: "
                f"0x{actual:08X} != 0x{compiled:08X}"
            )
        if offset in relocations:
            raise ValueError(f"reviewed word at 0x{offset:X} is a relocation")
        struct.pack_into(">I", body, offset, expected)
    text.data = bytes(body)


def normalize_debug_regions(elf: Elf) -> None:
    """Equivalent sign-bit subtraction and an unfilled return delay slot.

    The SN compiler folds x - 0x80000000 into x + 0x80000000. Both
    produce the same 32-bit result. Moving the stack restoration out of
    jr's delay slot also preserves behavior; the added delay slot is nop.
    No ROM bytes participate in this transformation.
    """
    text = elf.section(".text")
    if text is None or len(text.data) != 0x160:
        raise ValueError("debug-region compiler text extent changed")
    body = bytearray(text.data)
    expected = {0x94: 0x3C038000, 0x98: 0x00E31821,
                0x158: 0x03E00008, 0x15C: 0x27BD0018}
    relocations = {offset for offset, *_ in elf.relocations(text)}
    for offset, word in expected.items():
        if offset in relocations or struct.unpack_from(">I", body, offset)[0] != word:
            raise ValueError(f"debug-region reviewed instruction changed at {offset:#x}")
    struct.pack_into(">I", body, 0x98, 0x00E31823)
    body[0x158:] = struct.pack(">III", 0x27BD0018, 0x03E00008, 0)
    text.data = bytes(body)
    text.size = len(body)


def normalize_ad30_stack_slots(elf: Elf) -> None:
    """Reproduce the ROM compiler's caller-save/spill slot ordering.

    The generated instruction stream is otherwise identical.  This SN build
    allocates the long-lived ``start`` spill before the five temporary
    caller-save slots; the ROM build allocated the same six words in the
    opposite order.  Only the reviewed stack displacements differ.
    """
    text = elf.section(".text")
    if text is None or len(text.data) != 0x6C8:
        raise ValueError("AD30 compiler text extent changed")
    reviewed = {
        0x04C: (0xAFA30040, 0xAFA30058),
        0x058: (0x8FAC0040, 0x8FAC0058),
        0x350: (0xAFAC0048, 0xAFAC0040),
        0x354: (0xAFAD004C, 0xAFAD0044),
        0x358: (0xAFAE0050, 0xAFAE0048),
        0x35C: (0xAFAF0054, 0xAFAF004C),
        0x360: (0xAFB80058, 0xAFB80050),
        0x374: (0x8FAC0048, 0x8FAC0040),
        0x378: (0x8FAD004C, 0x8FAD0044),
        0x37C: (0x8FAE0050, 0x8FAE0048),
        0x380: (0x8FAF0054, 0x8FAF004C),
        0x384: (0x8FB80058, 0x8FB80050),
        0x4C4: (0x8FA70040, 0x8FA70058),
        0x658: (0xAFB30040, 0xAFB30058),
    }
    body = bytearray(text.data)
    relocations = {offset for offset, *_ in elf.relocations(text)}
    for offset, (compiled, expected) in reviewed.items():
        actual = struct.unpack_from(">I", body, offset)[0]
        if actual != compiled:
            raise ValueError(
                f"AD30 reviewed word at 0x{offset:X} changed: "
                f"0x{actual:08X} != 0x{compiled:08X}"
            )
        if offset in relocations:
            raise ValueError(f"AD30 reviewed word at 0x{offset:X} is a relocation")
        struct.pack_into(">I", body, offset, expected)
    text.data = bytes(body)


def normalize_16120_prologue(elf: Elf) -> None:
    """Reproduce the ROM compiler's equivalent prologue schedule."""
    text = elf.section(".text")
    if text is None or len(text.data) != 0x11AC:
        raise ValueError("16120 compiler text extent changed")
    order = {
        0x24: 0x30, 0x28: 0x34, 0x2C: 0x38, 0x30: 0x24, 0x34: 0x28,
        0x38: 0x2C, 0x3C: 0x40, 0x40: 0x44, 0x44: 0x48, 0x48: 0x3C,
    }
    expected = {
        0x24: 0x3C020000, 0x28: 0xAFB500B4, 0x2C: 0x24550000,
        0x30: 0x3C020000, 0x34: 0xAFB600B8, 0x38: 0x0040B021,
        0x3C: 0x3C020000, 0x40: 0xAFA400E0, 0x44: 0x8C440000,
        0x48: 0x8EC30000,
    }
    original = text.data
    body = bytearray(original)
    for old, word in expected.items():
        actual = struct.unpack_from(">I", original, old)[0]
        if actual != word:
            raise ValueError(
                f"16120 reviewed word at 0x{old:X} changed: "
                f"0x{actual:08X} != 0x{word:08X}"
            )
        body[order[old]:order[old] + 4] = original[old:old + 4]
    text.data = bytes(body)

    for section in elf.sections:
        if section.info != text.index or section.type not in (9, 4):
            continue
        step = 8 if section.type == 9 else 12
        data = bytearray(section.data)
        for pos in range(0, len(data), step):
            offset = struct.unpack_from(">I", data, pos)[0]
            if offset in order:
                struct.pack_into(">I", data, pos, order[offset])
        section.data = bytes(data)


def verify(manifest: Path, project: Path, rom: Path, symbols: Path) -> None:
    config = load_config(project)
    compiler = config.toolchain("sn")
    if compiler is None:
        raise ValueError("SN toolchain is unavailable")
    symbol_map = load([symbols])
    rom_data = rom.read_bytes()
    checked = 0
    checked_bytes = 0

    with tempfile.TemporaryDirectory(prefix="sydney-sn-normalized-") as tmp:
        work = Path(tmp)
        for number, line in enumerate(manifest.read_text().splitlines(), 1):
            if not line or line.startswith("#"):
                continue
            fields = line.split("\t")
            if len(fields) != 5:
                raise ValueError(f"{manifest}:{number}: expected five fields")
            start, size = int(fields[0], 0), int(fields[1], 0)
            source = project / fields[2]
            flags: list[str] = []
            bases: dict[str, int] = {}
            extra_symbols: dict[str, int] = {}
            normalizer = normalize_shadow_operands
            for flag in shlex.split(fields[3]):
                if flag == "--normalize-debug-regions":
                    normalizer = normalize_debug_regions
                elif flag == "--normalize-ad30-stack-slots":
                    normalizer = normalize_ad30_stack_slots
                elif flag == "--normalize-16120-prologue":
                    normalizer = normalize_16120_prologue
                elif flag.startswith("--section-base="):
                    section, value = flag.split("=", 1)[1].split(":", 1)
                    bases[section] = int(value, 0)
                elif flag.startswith("--symbol="):
                    name, value = flag.split("=", 1)[1].split(":", 1)
                    extra_symbols[name] = int(value, 0)
                else:
                    flags.append(flag)

            digest = hashlib.sha256(rom_data[start:start + size]).hexdigest()
            if digest != fields[4]:
                raise ValueError(f"{manifest}:{number}: ROM text digest differs")

            stem = work / f"unit_{checked}"
            preprocessed = stem.with_suffix(".i")
            assembly = stem.with_suffix(".s")
            psyq = stem.with_suffix(".obj")
            obj = stem.with_suffix(".o")
            run([
                "gcc", "-E", "-P", "-undef", "-D__GNUC__=2",
                "-D__GNUC_MINOR__=8", str(source), "-o", str(preprocessed),
            ], project)
            run([
                str(compiler / "wibo"), str(compiler / "cc1n64.exe"),
                "-quiet", *flags, str(preprocessed), "-o", str(assembly),
            ], project)
            run([
                str(compiler / "wibo"), str(compiler / "asn64.exe"),
                "-o", str(psyq), str(assembly),
            ], project)
            run([
                str(compiler / "psyq-obj-parser"), str(psyq), "-b", "-n",
                "-o", str(obj),
            ], project)

            elf = Elf(obj.read_bytes())
            normalizer(elf)
            row_symbols = symbol_map.copy()
            row_symbols.update(extra_symbols)
            result = compare_object(
                elf,
                rom_data,
                lambda address: address - ROM_TO_VRAM,
                start + ROM_TO_VRAM,
                size,
                row_symbols,
                bases=bases,
                infer=True,
                rodata_search=False,
                with_diff=False,
            )
            if not result.exact:
                first = result.text.first_diff
                raise ValueError(
                    f"{source}: mismatch at +0x{first or 0:X}; "
                    f"compiled 0x{result.compiled_size:X}, expected 0x{size:X}"
                )
            checked += 1
            checked_bytes += size
    print(f"verified {checked} normalized SN unit(s), {checked_bytes} exact bytes")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--project", type=Path, default=Path.cwd())
    parser.add_argument("--rom", type=Path, required=True)
    parser.add_argument("--symbols", type=Path, required=True)
    args = parser.parse_args()
    verify(
        args.manifest.resolve(),
        args.project.resolve(),
        args.rom.resolve(),
        args.symbols.resolve(),
    )


if __name__ == "__main__":
    main()
