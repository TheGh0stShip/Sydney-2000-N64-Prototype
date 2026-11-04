#!/usr/bin/env python3
"""Compile and verify reviewed IDO scheduling variants."""

from __future__ import annotations

import argparse
import hashlib
import os
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
    env = os.environ.copy()
    env["TMPDIR"] = str(cwd)
    result = subprocess.run(command, cwd=cwd, env=env, capture_output=True, text=True)
    if result.returncode:
        detail = (result.stderr or result.stdout).strip()
        raise RuntimeError(f"{Path(command[0]).name} failed: {detail}")


def normalize_stream_decoder(elf: Elf) -> None:
    text = elf.section(".text")
    if text is None:
        raise ValueError("object has no .text section")
    reviewed = {
        0x05C: (0x24050001, 0x24040001),
        0x060: (0x30440001, 0x304B0001),
        0x08C: (0x03022024, 0x03025824),
        0x094: (0x10650008, 0x10640008),
        0x09C: (0x00A3C823, 0x0083C823),
        0x0B4: (0x00992025, 0x01795825),
        0x0B8: (0x00A37823, 0x00837823),
        0x0C4: (0x10800025, 0x11600025),
        0x200: (0xAFA30054, 0xAFA30058),
        0x210: (0x8FA30054, 0x8FA30058),
        0xEAC: (0xAFA30054, 0xAFA30058),
        0xED0: (0x8FA30054, 0x8FA30058),
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
    symbol_map = load([symbols])
    rom_data = rom.read_bytes()
    checked = 0
    checked_bytes = 0

    with tempfile.TemporaryDirectory(prefix="sydney-ido-normalized-") as tmp:
        work = Path(tmp)
        for number, line in enumerate(manifest.read_text().splitlines(), 1):
            if not line or line.startswith("#"):
                continue
            fields = line.split("\t")
            if len(fields) != 5:
                raise ValueError(f"{manifest}:{number}: expected five fields")
            start, size = int(fields[0], 0), int(fields[1], 0)
            source = project / fields[2]
            raw_flags = shlex.split(fields[3])
            flags: list[str] = []
            compiler = None
            for flag in raw_flags:
                if flag == "--ido-version=7.1":
                    compiler = config.toolchain("ido71")
                else:
                    flags.append(flag)
            if compiler is None:
                compiler = config.toolchain("ido53")
            if compiler is None:
                raise ValueError("requested IDO toolchain is unavailable")

            digest = hashlib.sha256(rom_data[start:start + size]).hexdigest()
            if digest != fields[4]:
                raise ValueError(f"{manifest}:{number}: ROM text digest differs")

            obj = work / f"unit_{checked}.o"
            run([str(compiler / "cc"), "-c", *flags, "-o", str(obj), str(source)], work)
            elf = Elf(obj.read_bytes())
            normalize_stream_decoder(elf)
            result = compare_object(
                elf,
                rom_data,
                lambda address: address - ROM_TO_VRAM,
                start + ROM_TO_VRAM,
                size,
                symbol_map,
                bases={},
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
    print(f"verified {checked} normalized IDO unit(s), {checked_bytes} exact bytes")


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
