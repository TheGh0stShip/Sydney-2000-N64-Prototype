#!/usr/bin/env python3
"""Differential MIPS execution for the mapped display-input reconstruction.

External descriptor and virtual-input calls use identical deterministic MIPS
stubs. This isolates the mapper, controller consumption, masking and event
recording; it does not validate the helpers or establish byte matching.
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
ENTRY = 0x80007384
SYMBOLS = {
    'displayInputMaps': 0x800F2AD8,
    'displayConfigurationReady': 0x800F2728,
    'displayInputStates': 0x80043EFC,
    'displayInputRecords': 0x800688A0,
    'displayInputControllers': 0x800688D0,
    'displayInputEventIndex': 0x800F3882,
    'displayInputEvents': 0x800F2C80,
    'selectedDisplayConfiguration': 0x800F2778,
    'func_800BC408': 0x800BC408,
    'func_800AAC44': 0x800AAC44,
}
DESCRIPTORS = 0x80100000
OBJECTS = 0x80110000
VTABLE = 0x80120000
CALLBACK = 0x80130000
RANGES = (
    (0xF2AD8, 13 * 24), (0x43EFC, 2 * 216), (0x688A0, 4 * 12),
    (0x688D0, 4 * 6), (0xF2C80, 256 * 12), (0xF3882, 2),
    (0x100000, 30 * 8), (0x110000, 13 * 0x100), (0x120000, 0x58),
)


def write(machine, address, data):
    start = address & 0x1FFFFFFF
    machine.ram[start:start + len(data)] = data


def main():
    rom = Rom.load(ROOT / 'baserom.z64')
    spec = BuildSpec('sn', ['-O2', '-G0', '-mcpu=vr4300', '-mips3',
                            '-mhard-float', '-meb'])
    with tempfile.TemporaryDirectory(prefix='sydney-mapped-inputs-') as tmp:
        obj = build(ROOT / 'src/game/update_mapped_display_inputs.c',
                    spec, load_config(ROOT), Path(tmp))
        code = Elf.load(obj).relocate('.text', {'.text': ENTRY}, SYMBOLS)
    original, rebuilt = Machine(rom), Machine(rom)
    write(rebuilt, ENTRY, code)
    # descriptor(device): return DESCRIPTORS + device * 8
    stubs = {
        SYMBOLS['func_800BC408']: (0x000410C0, 0x3C038010, 0x03E00008, 0x00431021),
        SYMBOLS['func_800AAC44']: (0x240200A5, 0x03E00008, 0),
        CALLBACK: (0x2402005A, 0x03E00008, 0),
    }
    for machine in (original, rebuilt):
        for address, words in stubs.items():
            write(machine, address, struct.pack('>' + 'I' * len(words), *words))
    rng = random.Random(2000)
    tested = 0
    for mode in ('disabled', 'digital', 'analog', 'virtual', 'mixed'):
        for ready in (0, 1):
            for trial in range(40):
                maps = bytearray(13 * 24)
                descriptors = bytearray(30 * 8)
                objects = bytearray(13 * 0x100)
                states = bytearray(2 * 216)
                records = bytearray(4 * 12)
                controllers = bytearray(4 * 6)
                events = bytearray(b'\xA5' * (256 * 12))
                for device in range(30):
                    struct.pack_into('>hHI', descriptors, device * 8,
                                     device % 4, rng.randrange(256), device % 2)
                for index in range(4):
                    struct.pack_into('>IIhH', records, index * 12,
                                     0, 0, index, 0)
                    struct.pack_into('>HbbH', controllers, index * 6,
                                     rng.randrange(65536), rng.randrange(-128, 128),
                                     rng.randrange(-128, 128), 0)
                digital = (1, 2, 4, 8, 0x10, 0x20, 0x1000, 0x2000, 0x4000, 0x8000)
                analog = (0x100, 0x200, 0x400, 0x800)
                for index in range(2 * 9 * 6):
                    if mode == 'analog': flag = rng.choice(analog)
                    elif mode == 'digital': flag = rng.choice(digital)
                    else: flag = rng.choice((-1, 0x40, 0x80, 0x102) + analog + digital)
                    # Preserve signed short representation for high button bits.
                    signed = flag if flag < 32768 else flag - 65536
                    struct.pack_into('>hH', states, index * 4, signed,
                                     1 << (index % 6))
                for group in range(13):
                    object_address = OBJECTS + group * 0x100
                    struct.pack_into('>I', objects, group * 0x100 + 0xB4, VTABLE)
                    if mode == 'disabled': devices = (-1, -1)
                    elif mode == 'virtual': devices = (rng.choice((12, 20, 21, 28, 29)),
                                                       rng.choice((12, 20, 21, 28, 29)))
                    elif mode == 'mixed': devices = (rng.randrange(30), rng.randrange(30))
                    else: devices = (rng.randrange(12), rng.randrange(12))
                    first_object = 0 if rng.randrange(5) == 0 else object_address
                    second_object = 0 if rng.randrange(5) == 0 else object_address
                    struct.pack_into('>4I2b3H', maps, group * 24,
                                     first_object, second_object, rng.randrange(9), rng.randrange(9),
                                     *devices, rng.randrange(256), rng.randrange(256), 0)
                event_index = 255 if trial % 2 else 0
                results = []
                for machine in (original, rebuilt):
                    for address, data in (
                        (SYMBOLS['displayInputMaps'], maps),
                        (DESCRIPTORS, descriptors), (OBJECTS, objects),
                        (SYMBOLS['displayInputStates'], states),
                        (SYMBOLS['displayInputRecords'], records),
                        (SYMBOLS['displayInputControllers'], controllers),
                        (SYMBOLS['displayInputEvents'], events),
                        (SYMBOLS['displayInputEventIndex'], struct.pack('>H', event_index)),
                        (SYMBOLS['displayConfigurationReady'], struct.pack('>I', ready)),
                        (SYMBOLS['selectedDisplayConfiguration'], struct.pack('>I', 0x1200)),
                    ):
                        write(machine, address, data)
                    write(machine, VTABLE + 0x50, struct.pack('>hHI', -4, 0, CALLBACK))
                    machine.first_args.clear()
                    reason = machine.call(ENTRY, (0x1234,), max_steps=100000)
                    if reason != 'returned':
                        raise AssertionError(f'{mode}/{ready}/{trial}: stopped {reason}')
                    memory = tuple(bytes(machine.ram[start:start + size]) for start, size in RANGES)
                    calls = {address: machine.first_args[address][:(1 if address == SYMBOLS['func_800BC408'] else 2)] for address in stubs
                             if address in machine.first_args}
                    results.append((memory, calls))
                if results[0] != results[1]:
                    differing = [hex(start) for (start, size), left, right in zip(
                        RANGES, results[0][0], results[1][0]) if left != right]
                    raise AssertionError(f'{mode}/{ready}/{trial}: differing memory {differing}; '
                                         f'helper traces agree={results[0][1] == results[1][1]}')
                tested += 1
    print(f'{tested} mapped-input cases agree on controllers, masks, descriptors, events, and helper arguments')


if __name__ == '__main__':
    main()
