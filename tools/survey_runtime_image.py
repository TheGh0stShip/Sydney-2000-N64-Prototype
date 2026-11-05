#!/usr/bin/env python3
"""Discover provisional functions in the startup-loaded runtime image.

The original startup runs under the integer MIPS interpreter with external calls
stubbed. Its read arguments establish the mapping; its initializer-range calls
supply additional entry-point evidence. No discovered byte receives match credit.
"""
import argparse
from pathlib import Path
from hashlib import sha1, sha256
import json
import struct
import tomllib

import n64dk.analysis.functions as function_analysis
from n64dk.analysis.functions import Analyser, Image
from n64dk.emu import Machine
from n64dk.mips import instructions
from n64dk.rom import Rom
from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
DELTA = 0x7FFFF400
TRACE = 0x310000


def loader_mapping(rom):
    manifest = ROOT / 'config/matching_kmc_hook.tsv'
    row = next(line for line in manifest.read_text().splitlines()
               if '\tsrc/game/run_pi_worker_startup.c\t' in line)
    fields = row.split('\t')
    start, size = int(fields[0], 0), int(fields[1], 0)
    body = rom.data[start:start + size]
    if sha256(body).hexdigest() != fields[4]:
        raise ValueError('original startup no longer matches its manifest identity')
    definitions = {part[2:].split('=', 1)[0]: part.split('=', 1)[1]
                   for part in fields[3].split() if part.startswith('-D') and '=' in part}
    reader = int(definitions['READ_NAME'].removeprefix('func_'), 16)
    range_call = int(definitions['CALL_RANGE_NAME'].removeprefix('func_'), 16)
    machine = Machine(rom)
    # External calls have no effects except the initializer-range trace. This
    # preserves o32 caller/callee register ownership and does not execute them.
    for ins in instructions(body, start + DELTA):
        if ins.isJumpWithAddress() and ins.doesLink():
            offset = ins.getInstrIndexAsVram() & 0x1FFFFFFF
            machine.ram[offset:offset + 8] = struct.pack('>II', 0x03E00008, 0)
    trace_stub = (0x3C088031, 0x8D090000, 0x000950C0, 0x01485021,
                  0xAD440004, 0xAD450008, 0x25290001, 0xAD090000,
                  0x03E00008, 0)
    offset = range_call & 0x1FFFFFFF
    machine.ram[offset:offset + 4 * len(trace_stub)] = struct.pack('>10I', *trace_stub)
    if machine.call(start + DELTA, max_steps=2000) != 'returned':
        raise ValueError('startup mapping probe did not return')
    source, destination, length = [value & 0xFFFFFFFF
                                   for value in machine.first_args[reader][:3]]
    if source & 0xF0000000 != 0xB0000000:
        raise ValueError('startup read is not from cartridge ROM')
    source &= 0x0FFFFFFF
    if not (0 <= source < source + length <= len(rom.data)):
        raise ValueError('startup image escapes original ROM')
    count, = struct.unpack_from('>I', machine.ram, TRACE)
    if count > 16:
        raise ValueError('unexpected initializer trace size')
    initializers = [struct.unpack_from('>II', machine.ram, TRACE + 4 + index * 8)
                    for index in range(count)]
    return source, destination, length, initializers, row


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--output', type=Path, default=ROOT / 'config/survey/runtime_candidates.json')
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    rom = Rom.load(args.rom)
    if len(rom.data) != EXPECTED_SIZE or sha1(rom.data).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported original ROM')
    source, destination, length, initializers, loader_row = loader_mapping(rom)
    image = Image(rom.data[source:source + length], destination)
    seeds = {}
    resident = ROOT / 'config/survey/functions.toml'
    section = tomllib.loads(resident.read_text())['section'][0]
    for function in section['functions']:
        start = function['vram'] - DELTA
        body = rom.data[start:start + function['size']]
        for ins in instructions(body, function['vram']):
            if ins.isJumpWithAddress() and ins.doesLink():
                target = ins.getInstrIndexAsVram()
                if target in image and target % 4 == 0:
                    seeds.setdefault(target, []).append({'kind': 'resident_call', 'site': ins.vram})
    for start, end in initializers:
        if start not in image or end <= start or end > image.end or (end - start) % 4:
            continue
        for address in range(start, end, 4):
            target = image.word(address)
            if target in image and target % 4 == 0:
                seeds.setdefault(target, []).append({'kind': 'initializer', 'site': address})
    if not seeds:
        raise ValueError('no runtime entry-point evidence found')
    analyser = Analyser(image, min(seeds), text_lo=destination)
    for target in sorted(seeds):
        analyser.add(target, 'call')
    analyser.grow()
    functions = []
    starts = analyser.sorted_starts()
    for index, address in enumerate(starts):
        limit = starts[index + 1] if index + 1 < len(starts) else image.end
        body = analyser.walk(address, limit)
        functions.append({'name': f'func_{address:08X}', 'vram': address,
                          'rom_start': source + address - destination,
                          'size': body.end - address, 'walk_ok': body.ok,
                          'walk_reason': body.reason, 'falls_through': body.fell_through,
                          'seed': seeds.get(address, [{'kind': analyser.starts[address]}]),
                          'calls': sorted(body.calls), 'tails': sorted(body.tails)})
    result = {
        'version': 1, 'provisional': True, 'matching_credit': 0,
        'rom_sha1': EXPECTED_SHA1,
        'mapping': {'rom_start': source, 'rom_end': source + length,
                    'vram_start': destination, 'vram_end': image.end, 'size': length},
        'evidence': {'loader_manifest_row_sha256': sha256(loader_row.encode()).hexdigest(),
                     'resident_catalogue_sha256': sha256(resident.read_bytes()).hexdigest(),
                     'analysis_module_sha256': sha256(Path(function_analysis.__file__).read_bytes()).hexdigest(),
                     'generator_sha256': sha256(Path(__file__).read_bytes()).hexdigest(),
                     'initializer_ranges': [{'vram_start': start, 'vram_end': end}
                                            for start, end in initializers],
                     'external_helpers': 'stubbed; only original startup argument computation executed'},
        'summary': {'seeded_starts': len(seeds), 'candidates': len(functions),
                    'valid_walks': sum(function['walk_ok'] for function in functions)},
        'functions': functions,
    }
    text = json.dumps(result, indent=2) + '\n'
    if args.check:
        if not args.output.is_file() or args.output.read_text() != text:
            raise ValueError('runtime survey differs; regenerate with make runtime-survey')
    else:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text)
    print(f'{len(functions)} provisional runtime candidates; mapping ROM {source:#x}..'
          f'{source + length:#x} to {destination:#x}..{image.end:#x}; no matching credit')


if __name__ == '__main__':
    main()
