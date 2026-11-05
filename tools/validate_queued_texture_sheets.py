#!/usr/bin/env python3
"""Differential MIPS execution of the queued texture-sheet renderer.

Checks sampled memory effects against the preservation ROM, not byte matching.
Use the PYTHONPATH and N64DK_TOOLCHAIN environment used by make verify-matching.
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
ENTRY = 0x8001A660
SYMBOLS = {
    'displayListHead': 0x800663DC, 'displayListBuffers': 0x80039310,
    'displayListIndex': 0x80066490, 'maximumSpriteLayer': 0x800624C8,
    'spriteQueueCount': 0x800624C4, 'textureSheets': 0x800624B4,
    'sheetRecords': 0x800624D0, 'spriteQueue': 0x80062500,
    'halfWidthMode': 0x8005A83C,
}


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    config = load_config(ROOT)
    spec = BuildSpec('sn', ['-O2', '-G0', '-mcpu=vr4300', '-mips3',
                            '-mhard-float', '-meb'])
    bases = {'.text': ENTRY, '.rodata': 0x80001040, '.rdata': 0x80001040}
    with tempfile.TemporaryDirectory(prefix='sydney-queued-sheets-') as tmp:
        obj = build(ROOT / 'src/game/draw_queued_texture_sheets.c',
                    spec, config, Path(tmp))
        elf = Elf.load(obj)
        relocated = [(section.name, bases[section.name],
                      elf.relocate(section.name, bases, SYMBOLS))
                     for section in elf.sections
                     if section.name in bases and section.size]
    original, rebuilt = Machine(rom), Machine(rom)
    for name, address, data in relocated:
        start = address & 0x1FFFFFFF
        rebuilt.ram[start:start + len(data)] = data
    rng = random.Random(2000)
    cases = []
    for mode in (0, 1, 2):
        for maximum in (-1, 0, 1, 4, 9, 10):
            for capacity in (0, 6110, 6124, 6125):
                cases.append((mode, maximum, capacity, rng.randrange(0, 17)))
    cases += [(rng.randrange(3), rng.randrange(11), 0, rng.randrange(17))
              for _ in range(128)]
    for case, (mode, maximum, capacity, queued_count) in enumerate(cases):
        image = bytearray(0x30000)
        queue = bytearray(0x1000)
        metadata = bytearray(0x4C)
        for sheet in range(4):
            sheet_pointer = 0x80100000 + sheet * 0x4000
            present = rng.randrange(4) != 0
            struct.pack_into('>I', metadata, sheet * 4, sheet_pointer if present else 0)
            start = sheet * 0x4000
            struct.pack_into('>I', image, start, 0x400)
            struct.pack_into('>I', image, start + 0x10, 3)
            struct.pack_into('>H', metadata, 0x1C + sheet * 12 + 4, rng.randrange(3, 12))
            for entry in range(12):
                struct.pack_into('>HH4B2b10s', image, start + 0x20 + entry * 20,
                                 entry, rng.randrange(3), rng.randrange(256),
                                 rng.randrange(256), rng.randrange(1, 100),
                                 rng.randrange(1, 100), rng.randrange(-40, 40),
                                 rng.randrange(-40, 40), bytes(10))
        struct.pack_into('>I', metadata, 0x10, queued_count)
        struct.pack_into('>i', metadata, 0x14, maximum)
        for index in range(queued_count):
            obj = 0x80120000 + index * 0x100
            start = 0x20000 + index * 0x100
            struct.pack_into('>I', image, start + 0xC0,
                             0x80000 if rng.randrange(4) == 0 else 0)
            struct.pack_into('>I', image, start + 0xC4,
                             (rng.randrange(4) << 8) | (rng.randrange(12) + 3))
            image[start + 0xC9] = rng.randrange(11)
            image[start + 0xCB] = rng.choice((0, 64, 128, 254, 255))
            struct.pack_into('>Ihh', queue, index * 8, obj,
                             rng.randrange(-1000, 1000), rng.randrange(-1000, 1000))
        results = []
        for machine in (original, rebuilt):
            machine.ram[0x100000:0x130000] = image
            machine.ram[0x62500:0x63500] = queue
            machine.ram[0x624B4:0x62500] = metadata
            machine.ram[0x200000:0x220000] = b'\xA5' * 0x20000
            struct.pack_into('>II', machine.ram, 0x39310, 0x80200000, 0x80200000)
            struct.pack_into('>I', machine.ram, 0x66490, case % 2)
            struct.pack_into('>I', machine.ram, 0x663DC, 0x80200000 + capacity * 8)
            struct.pack_into('>I', machine.ram, 0x5A83C, mode)
            reason = machine.call(ENTRY, max_steps=250000)
            if reason != 'returned':
                raise AssertionError(f'case {case}: {reason}')
            results.append((bytes(machine.ram[0x200000:0x220000]),
                            bytes(machine.ram[0x663DC:0x663E0]),
                            bytes(machine.ram[0x62500:0x63500]),
                            bytes(machine.ram[0x100000:0x130000]),
                            bytes(machine.ram[0x624B4:0x62500])))
        if results[0] != results[1]:
            names = ('commands', 'cursor', 'queue', 'sheets/objects', 'metadata')
            differs = [name for name, a, b in zip(names, *results) if a != b]
            raise AssertionError(f'case {case} mode={mode} max={maximum} '
                                 f'capacity={capacity} count={queued_count}: {differs}')
    print(f'{len(cases)} queued-sheet cases agree on commands, cursor, and input side effects')


if __name__ == '__main__':
    main()
