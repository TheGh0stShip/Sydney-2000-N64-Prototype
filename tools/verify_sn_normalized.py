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
            for flag in shlex.split(fields[3]):
                if flag.startswith("--section-base="):
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
            normalize_shadow_operands(elf)
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
