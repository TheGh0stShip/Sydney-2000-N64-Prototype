#!/usr/bin/env python3
"""Differential MIPS execution for the aligned allocator.

This checks sampled behavior against the ROM; it gives no matching credit.
Run with the same PYTHONPATH and N64DK_TOOLCHAIN as make verify-matching.
"""
from pathlib import Path
import random
import struct
import tempfile

from n64dk.elf import Elf
from n64dk.emu import Machine
from n64dk.match.pipeline import BuildSpec, build
from n64dk.match.toolchain import load_config
from n64dk.rom import Rom

ROOT = Path(__file__).resolve().parents[1]
ENTRY = 0x80037B30
HEAP = 0x80100000
HEAP_SIZE = 0x10000
GLOBAL = 0x68460


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    config = load_config(ROOT)
    spec = BuildSpec('kmc+as', ['-O1', '-G0', '-mips3', '-mgp32', '-mfp32'])
    with tempfile.TemporaryDirectory(prefix='sydney-aligned-heap-') as tmp:
        obj = build(ROOT / 'src/game/allocate_aligned_heap_block.c',
                    spec, config, Path(tmp))
        code = Elf.load(obj).relocate('.text', {'.text': ENTRY},
                                     {'alignedHeap': 0x80068460,
                                      'func_80037D10': 0x80037D10})
    original = Machine(rom)
    rebuilt = Machine(rom)
    start = ENTRY & 0x1FFFFFFF
    rebuilt.ram[start:start + len(code)] = code
    rng = random.Random(2000)
    cases = []
    # Include the sentinel and zero-size exits, plus ordinary allocator fallback.
    for alignment in (1, 4, 16, 32, 64, 128, 256, 1024):
        for size in (0, 1, 16, 31, 32, 128, 4096):
            cases.append((alignment, size, False))
    cases += [(64, 128, True), (16, 1, True)]
    cases += [(rng.choice((32, 64, 128, 256, 512)), rng.randrange(1, 2048), False)
              for _ in range(200)]
    for index, (alignment, size, sentinel) in enumerate(cases):
        image = bytearray(HEAP_SIZE)
        position = rng.randrange(0, 8) * 16
        head = HEAP + position
        blocks = rng.randrange(1, 9)
        for block in range(blocks):
            capacity = rng.randrange(1, 160) * 16
            next_position = position + capacity + 16
            next_pointer = HEAP + next_position if block + 1 < blocks else 0
            struct.pack_into('>4I', image, position, next_pointer, capacity,
                             rng.randrange(2), 0x12345678)
            position = next_position
        results = []
        for machine in (original, rebuilt):
            machine.ram[HEAP & 0x1FFFFFFF:(HEAP & 0x1FFFFFFF) + HEAP_SIZE] = image
            struct.pack_into('>I', machine.ram, GLOBAL, 0xFFFFFFFF if sentinel else head)
            reason = machine.call(ENTRY, (alignment, size), max_steps=10000)
            if reason != 'returned':
                raise AssertionError(f'case {index}: stopped: {reason}')
            results.append((machine.gpr[2] & 0xFFFFFFFF,
                            bytes(machine.ram[HEAP & 0x1FFFFFFF:
                                              (HEAP & 0x1FFFFFFF) + HEAP_SIZE])))
        if results[0] != results[1]:
            raise AssertionError(f'case {index}: alignment={alignment}, size={size}: '
                                 f'returns {results[0][0]:#x}, {results[1][0]:#x}; heap differs')
    print(f'{len(cases)} allocator cases agree on return value and heap bytes')


if __name__ == '__main__':
    main()
