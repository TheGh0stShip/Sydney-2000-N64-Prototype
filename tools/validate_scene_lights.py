#!/usr/bin/env python3
"""Compare sampled lighting-command behavior with the original MIPS code.

This validates return-side memory effects; it does not establish byte matching.
Use the PYTHONPATH and N64DK_TOOLCHAIN settings from make verify-matching.
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
ENTRY = 0x800064D0
STATE = 0x43D48
LISTS = 0x100000
OUTPUT = 0x200000
POINTER = 0x300000


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    config = load_config(ROOT)
    spec = BuildSpec('sn', ['-O2', '-G0', '-mcpu=vr4300', '-mips3',
                            '-mhard-float', '-meb'])
    with tempfile.TemporaryDirectory(prefix='sydney-scene-lights-') as tmp:
        obj = build(ROOT / 'src/game/build_scene_light_commands.c',
                    spec, config, Path(tmp))
        code = Elf.load(obj).relocate('.text', {'.text': ENTRY},
                                     {'sceneLightState': 0x80043D48,
                                      'defaultSceneLight': 0x80043D28})
    original, rebuilt = Machine(rom), Machine(rom)
    rebuilt.ram[ENTRY & 0x1FFFFFFF:(ENTRY & 0x1FFFFFFF) + len(code)] = code
    rng = random.Random(2000)
    cases = 0
    # Exercise empty lists, disabled lights, view filtering, and multiple groups.
    for mode in ('empty', 'disabled', 'filtered', 'active', 'mixed'):
        for view in range(4):
            for trial in range(20):
                state = bytearray(0xC0)
                for offset in range(8, 20):
                    state[offset] = rng.randrange(256)
                # View 3's ambient storage overlaps group counts 0 and 1.
                # A zero color exercises that original layout without creating
                # counts beyond the allocated records.
                if view == 3:
                    state[20:24] = bytes(4)
                lists = bytearray(0x8000)
                for group in range(8):
                    count = 0 if mode == 'empty' else rng.randrange(1, 7)
                    pointer = 0 if not count else 0x80100000 + group * 0x1000
                    struct.pack_into('>I', state, 0x48 + 4 * group, count)
                    struct.pack_into('>I', state, 0x88 + 4 * group, pointer)
                    for index in range(count):
                        offset = group * 0x1000 + index * 32
                        flags = 0 if mode == 'disabled' else 1
                        mask = 1 << view
                        if mode == 'filtered':
                            mask = 1 << ((view + 1) % 4)
                        if mode == 'mixed':
                            flags = rng.randrange(4)
                            mask = rng.randrange(16)
                        struct.pack_into('>II16sII', lists, offset, flags, 0,
                                         rng.randbytes(16), mask, 0)
                results = []
                for machine in (original, rebuilt):
                    machine.ram[STATE:STATE + len(state)] = state
                    machine.ram[LISTS:LISTS + len(lists)] = lists
                    machine.ram[OUTPUT:OUTPUT + 0x1000] = b'\xA5' * 0x1000
                    struct.pack_into('>I', machine.ram, POINTER, 0x80200000)
                    reason = machine.call(ENTRY, (0x80300000, view), max_steps=10000)
                    if reason != 'returned':
                        raise AssertionError(f'{mode}/{view}/{trial}: {reason}')
                    results.append((bytes(machine.ram[STATE:STATE + len(state)]),
                                    bytes(machine.ram[OUTPUT:OUTPUT + 0x1000]),
                                    bytes(machine.ram[POINTER:POINTER + 4]),
                                    bytes(machine.ram[LISTS:LISTS + len(lists)])))
                if results[0] != results[1]:
                    differing = [name for name, a, b in zip(
                        ('state', 'commands', 'cursor', 'light records'), *results) if a != b]
                    raise AssertionError(f'{mode}/{view}/{trial}: differs: {differing}')
                cases += 1
    print(f'{cases} lighting cases agree on state, commands, cursor, and light records')


if __name__ == '__main__':
    main()
