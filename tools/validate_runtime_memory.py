#!/usr/bin/env python3
"""Check original MIPS copy/fill semantics; exact C matching is a separate gate."""
import argparse
from hashlib import sha1
from pathlib import Path
import random
import struct
from n64dk.emu import Machine
from n64dk.rom import Rom
from survey_runtime_image import loader_mapping
from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x80200000
STATISTICS = 0x101040


def copy_model(image, destination, source, length):
    def transfer(width, count=1):
        nonlocal destination, source, length
        # The unrolled path reads all four elements before any store.
        values = bytes(image[source:source + width * count])
        image[destination:destination + width * count] = values
        destination += width * count
        source += width * count
        length -= width * count
    if length < 8:
        while length:
            transfer(1)
        return
    alignment = destination ^ source
    width = 4 if not alignment & 3 else 2 if not alignment & 1 else 1
    while destination % width:
        transfer(1)
    threshold = {4: 256, 2: 64, 1: 17}[width]
    if length >= threshold:
        while length >= width * 4:
            transfer(width, 4)
    while length >= width:
        transfer(width)
    while length:
        transfer(1)


def fill_model(image, destination, value, length):
    if length < 8:
        image[destination:destination + length] = bytes([value & 255]) * length
        return
    while destination % 4:
        image[destination] = value & 255
        destination += 1
        length -= 1
    words, tail = divmod(length, 4)
    image[destination:destination + words * 4] = value.to_bytes(4, 'big') * words
    image[destination + words * 4:destination + length] = bytes([value & 255]) * tail


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    args = parser.parse_args()
    rom = Rom.load(args.rom)
    assert len(rom.data) == EXPECTED_SIZE and sha1(rom.data).hexdigest() == EXPECTED_SHA1
    source, destination, length, _, _ = loader_mapping(rom)
    machine = Machine(rom)
    machine.ram[destination & 0x1fffffff:(destination & 0x1fffffff) + length] = rom.data[source:source + length]
    rng = random.Random(2000)
    initial = bytes(rng.randrange(256) for _ in range(4096))
    lengths = (0, 1, 2, 3, 4, 7, 8, 9, 15, 16, 17, 31, 63, 64, 65, 255, 256, 257, 271, 512)
    copies = [(1024 + d, 128 + s, n) for d in range(4) for s in range(4) for n in lengths]
    copies += [(512 + shift, 512, n) for shift in (-16, -3, -1, 0, 1, 2, 3, 4, 16) for n in lengths]
    fills = [(1024 + d, value, n) for d in range(4) for value in (0, 0x89abcdef, 0xffffffff) for n in lengths]
    count = 0
    for kind, cases, entry, model in [('copy', copies, 0x800B3870, copy_model), ('fill', fills, 0x800B3AFC, fill_model)]:
        for destination, operand, length in cases:
            expected = bytearray(initial)
            model(expected, destination, operand, length)
            start = BASE & 0x1fffffff
            machine.ram[start:start + len(initial)] = initial
            counters = [0xfffffffe, 0xfffffffe, 0xfffffff0, 0xfffffff0]
            struct.pack_into('>4I', machine.ram, STATISTICS, *counters)
            args = (BASE + destination, BASE + operand if kind == 'copy' else operand, length)
            reason = machine.call(entry, args, max_steps=20000)
            assert reason == 'returned', (kind, destination, operand, length, reason)
            assert machine.ram[start:start + len(initial)] == expected, (kind, destination, operand, length, 'memory')
            index = kind == 'fill'
            counters[index] = (counters[index] + 1) & 0xffffffff
            counters[index + 2] = (counters[index + 2] + length) & 0xffffffff
            assert struct.unpack_from('>4I', machine.ram, STATISTICS) == tuple(counters), (kind, 'counters')
            count += 1
    print(f'{count} original-MIPS copy/fill cases agree with the independent model, including overlap and counter wrap')


if __name__ == '__main__':
    main()
