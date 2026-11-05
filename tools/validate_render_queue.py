#!/usr/bin/env python3
"""Sampled differential MIPS validation of the resource-queue reconstruction.

Calls outside the queue routine use identical deterministic MIPS stubs. This
checks the queue logic and helper arguments, not those helpers' implementations.
No byte-matching credit follows from behavioral agreement.
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
ENTRY = 0x8000C68C
SYMBOLS = {
    'resourceRecordCount': 0x80047984,
    'resourceRecords': 0x80049A28,
    'currentResourceRecord': 0x800479A8,
    'resourceRangeBase': 0x80043688,
    'resourceRangeLimit': 0x8004367C,
    'resourceResolutionDisabled': 0x80039450,
    'resolvedResourceBytes': 0x800479AC,
    'func_8000C394': 0x8000C394,
    'func_8000CA34': 0x8000CA34,
    'func_8000F2E8': 0x8000F2E8,
}
SPECIAL = (0x14AF, 0x14B0, 0x14B2, 0x14B1, 0x101E, 0x101D,
           0x1020, 0x101F, 0x10B4, 0x10B3, 0x10B6, 0x10B5,
           0xEE0, 0xEDF, 0xEE2, 0xEE1)


def put_word(machine, address, value):
    struct.pack_into('>I', machine.ram, address & 0x1FFFFFFF, value)


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    spec = BuildSpec('sn', ['-O2', '-G0', '-mcpu=vr4300', '-mips3',
                            '-mhard-float', '-meb'])
    with tempfile.TemporaryDirectory(prefix='sydney-render-queue-') as tmp:
        obj = build(ROOT / 'src/game/queue_render_resource_record.c',
                    spec, load_config(ROOT), Path(tmp))
        code = Elf.load(obj).relocate('.text', {'.text': ENTRY}, SYMBOLS)
    original, rebuilt = Machine(rom), Machine(rom)
    start = ENTRY & 0x1FFFFFFF
    rebuilt.ram[start:start + len(code)] = code
    stubs = {
        0x8000C394: (0x3402C394, 0x03E00008, 0),
        0x8000CA34: (0x3402CA34, 0x03E00008, 0),
        # resolve(identifier, size_out): *size_out=52; return 0x1234
        0x8000F2E8: (0x24080034, 0xACA80000, 0x24021234, 0x03E00008, 0),
    }
    for machine in (original, rebuilt):
        for address, words in stubs.items():
            offset = address & 0x1FFFFFFF
            machine.ram[offset:offset + len(words) * 4] = struct.pack('>' + 'I' * len(words), *words)
    rng = random.Random(2000)
    cases = [(identifier, 1, 0, 4) for identifier in SPECIAL]
    cases += [(identifier, current, mode, count)
              for identifier in (0, 1, 2, 16, 33, 34, 0x80000000)
              for current in (0, 1) for mode in (0, 1) for count in (0, 1, 8)]
    cases += [(rng.randrange(35), 1, rng.randrange(2), rng.randrange(9))
              for _ in range(300)]
    for number, (identifier, current, mode, count) in enumerate(cases):
        records = bytearray(rng.randbytes(0xE0 * 16))
        for index in range(16):
            value = rng.choice((0xFFFE, rng.randrange(1, 17),
                                rng.randrange(1, 17) | 0x80000000))
            handle = rng.choice((0x1234, rng.randrange(0x1000, 0x2000)))
            struct.pack_into('>II', records, index * 0xE0, value, handle)
        results = []
        for machine in (original, rebuilt):
            machine.ram[0x49A28:0x49A28 + len(records)] = records
            for name, value in (('resourceRecordCount', count),
                                ('currentResourceRecord', current),
                                ('resourceRangeBase', 32),
                                ('resourceRangeLimit', 64),
                                ('resourceResolutionDisabled', mode),
                                ('resolvedResourceBytes', 100)):
                put_word(machine, SYMBOLS[name], value)
            machine.first_args.clear()
            # The fifth o32 argument is passed in the caller's argument area.
            put_word(machine, 0x803FFF10, 0x76543210)
            reason = machine.call(ENTRY, (identifier, 0x11223344, 0x55667788,
                                          0x12345678), max_steps=10000)
            if reason != 'returned':
                raise AssertionError(f'case {number}: stopped {reason}')
            calls = {}
            for address in stubs:
                if address not in machine.first_args:
                    continue
                args = machine.first_args[address]
                if address == 0x8000CA34:
                    # The forwarding helper takes six o32 arguments; checking
                    # just a0..a3 would miss swapped/dropped stack arguments.
                    helper_sp = args[4] & 0x1FFFFFFF
                    extra = struct.unpack_from('>II', machine.ram, helper_sp + 16)
                    calls[address] = tuple(value & 0xFFFFFFFF for value in args[:4]) + extra
                else:
                    # C394 consumes only the identifier. F2E8 also receives a
                    # temporary stack pointer whose writes are checked via the
                    # resulting records/counters, not by its chosen location.
                    calls[address] = (args[0] & 0xFFFFFFFF,)
            results.append((machine.gpr[2] & 0xFFFFFFFF,
                            bytes(machine.ram[0x49A28:0x49A28 + len(records)]),
                            bytes(machine.ram[0x47980:0x479B0]), calls))
        if results[0] != results[1]:
            raise AssertionError(f'case {number}: id={identifier:#x}, current={current}, '
                                 f'mode={mode}, count={count}; queue behavior differs')
    print(f'{len(cases)} queue cases agree on return, records, counters, and helper arguments')


if __name__ == '__main__':
    main()
