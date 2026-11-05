#!/usr/bin/env python3
"""Validate original runtime priority semantics against an independent model.

This checks signed (deadline, kind) ordering and pool/index invariants in the
original MIPS routines. Exact C matching is verified separately by verify-runtime;
no source or coverage credit is created by this model test.
"""
import argparse
from pathlib import Path
from hashlib import sha1
import random
import struct

from n64dk.rom import Rom
from n64dk.emu import Machine
from survey_runtime_image import loader_mapping
from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]


def check(condition, context):
    if not condition:
        raise AssertionError(context)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--operations', type=int, default=600)
    args = parser.parse_args()
    if args.operations <= 0:
        parser.error('--operations must be positive')
    rom = Rom.load(args.rom)
    check(len(rom.data) == EXPECTED_SIZE and sha1(rom.data).hexdigest() == EXPECTED_SHA1,
          'unsupported original ROM')
    source, destination, length, _, _ = loader_mapping(rom)
    machine = Machine(rom)
    offset = destination & 0x1FFFFFFF
    machine.ram[offset:offset + length] = rom.data[source:source + length]
    heap, entries, free = 0x80102000, 0x80100000, 0x80101000
    nodes, out, capacity = 0x80110000, 0x80103000, 32

    def put(address, fmt, *values):
        struct.pack_into('>' + fmt, machine.ram, address & 0x1FFFFFFF, *values)

    def get(address, fmt):
        return struct.unpack_from('>' + fmt, machine.ram, address & 0x1FFFFFFF)

    put(heap, 'IIIHHHH', 0, entries, free, 0, capacity, 0, 0)
    for index in range(capacity):
        put(free + index * 4, 'I', nodes + index * 24)
    rng, reference, serial = random.Random(2000), {}, 0
    for operation in range(args.operations):
        if not reference or (rng.random() < 0.65 and len(reference) < capacity):
            deadline, kind = rng.randrange(-50, 51), rng.randrange(-4, 5)
            serial += 1
            # Fifth and sixth o32 arguments occupy the caller's argument area.
            put(0x803FFF10, 'I', serial)
            put(0x803FFF14, 'I', 0xC001CAFE)
            reason = machine.call(0x800AB2A4, (heap, deadline, kind, 0x12340000 + serial),
                                  max_steps=10000)
            check(reason == 'returned', (operation, reason))
            reference[serial] = deadline, kind
        else:
            root_pointer = get(entries + 4, 'I')[0]
            kind, deadline, _, identity, _, _, _ = get(root_pointer, 'iiIIIHH')
            check((deadline, kind) == min(reference.values()), (operation, 'minimum key'))
            put(out, 'I', 0)
            reason = machine.call(0x800AB038, (heap, out, 1), max_steps=10000)
            check(reason == 'returned', (operation, reason))
            check(get(out, 'I')[0] == root_pointer, (operation, 'removed pointer'))
            check(reference.pop(identity) == (deadline, kind), (operation, 'removed identity'))
        active, total, cursor = get(heap + 12, 'HHH')
        check(active == cursor == len(reference) and total == capacity, (operation, 'counters'))
        active_pointers, observed = set(), {}
        for index in range(1, active + 1):
            pointer = get(entries + index * 4, 'I')[0]
            active_pointers.add(pointer)
            kind, deadline, object_pointer, identity, tag, node_index, _ = get(pointer, 'iiIIIHH')
            check(node_index == index and tag == 0xC001CAFE, (operation, 'node index/tag'))
            check(object_pointer == 0x12340000 + identity, (operation, 'object token'))
            observed[identity] = deadline, kind
            if index > 1:
                parent = get(entries + (index // 2) * 4, 'I')[0]
                parent_kind, parent_deadline = get(parent, 'ii')
                check((parent_deadline, parent_kind) <= (deadline, kind), (operation, 'heap property'))
        check(observed == reference, (operation, 'reference multiset'))
        free_pointers = {get(free + index * 4, 'I')[0] for index in range(cursor, capacity)}
        all_nodes = {nodes + index * 24 for index in range(capacity)}
        check(len(active_pointers) == active and len(free_pointers) == capacity - cursor,
              (operation, 'pool cardinality'))
        check(not (active_pointers & free_pointers) and active_pointers | free_pointers == all_nodes,
              (operation, 'active/free pool partition'))
    print(f'{args.operations} original-runtime operations agree with the signed-key model and pool invariants')


if __name__ == '__main__':
    main()
