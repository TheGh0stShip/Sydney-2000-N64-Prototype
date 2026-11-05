#!/usr/bin/env python3
"""Reproducibly map and survey executable images in the event-overlay bank."""
import argparse
from hashlib import sha1, sha256
import json
from pathlib import Path
import struct

import n64dk.analysis.functions as function_analysis
from n64dk.analysis.functions import Analyser, Image
from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
MAPPINGS = (
    ('ceremony', 0x69070, 0x6DF40, 0x80070994),
    ('closing', 0x6DF40, 0x70800, 0x80070494),
    # Direct j/jal targets and absolute tables in this image use the same low
    # 24-bit offset as their ROM location (for example ROM 0x70F20 is called as
    # 0x80070F20), establishing this relocation independently of heuristics.
    ('event_bank', 0x70800, 0x127640, 0x80070800),
)
POINTER_AT = 0x69070
POINTEE_AT = 0x6908C
POINTEE = b'GRAPHICS__CEREMONY__CREDITS_BGP\0'


def render(rom: bytes) -> dict:
    if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported original ROM')
    pointer, = struct.unpack_from('>I', rom, POINTER_AT)
    if pointer != MAPPINGS[0][3] + POINTEE_AT - MAPPINGS[0][1] or rom[
            POINTEE_AT:POINTEE_AT + len(POINTEE)] != POINTEE:
        raise ValueError('ceremony overlay relocation evidence changed')
    units = []
    for unit_name, rom_start, rom_end, vram_start in MAPPINGS:
        image = Image(rom[rom_start:rom_end], vram_start)
        seeds = []
        for offset in range(0, rom_end - rom_start, 4):
            word, = struct.unpack_from('>I', rom, rom_start + offset)
            if word >> 16 == 0x27BD and word & 0x8000:
                seeds.append(vram_start + offset)
        if not seeds:
            raise ValueError(f'{unit_name} overlay has no MIPS stack-frame seeds')
        analyser = Analyser(image, min(seeds), text_lo=vram_start)
        for address in seeds:
            analyser.add(address, 'stack_frame')
        if unit_name == 'event_bank':
            # The large bank makes recursive split-point discovery quadratic.
            # Seed direct calls in one linear pass; stack-frame seeds cover the
            # remaining non-leaf routines while avoiding speculative j targets.
            for offset in range(0, rom_end - rom_start, 4):
                word, = struct.unpack_from('>I', rom, rom_start + offset)
                if word >> 26 == 3:
                    target = 0x80000000 | ((word & 0x03FFFFFF) << 2)
                    if image.valid(target):
                        analyser.add(target, 'call')
        else:
            analyser.grow()
        starts = analyser.sorted_starts()
        functions = []
        for index, address in enumerate(starts):
            limit = starts[index + 1] if index + 1 < len(starts) else image.end
            body = analyser.walk(address, limit)
            functions.append({
                'name': f'func_{address:08X}', 'vram': address,
                'rom_start': rom_start + address - vram_start,
                'size': body.end - address, 'walk_ok': body.ok,
                'walk_reason': body.reason, 'falls_through': body.fell_through,
                'seed': 'stack_frame' if address in seeds else analyser.starts[address],
                'calls': sorted(body.calls), 'tails': sorted(body.tails),
            })
        units.append({
            'name': unit_name,
            'mapping': {'rom_start': rom_start, 'rom_end': rom_end,
                        'vram_start': vram_start, 'vram_end': image.end,
                        'delta': vram_start - rom_start, 'size': rom_end - rom_start},
            'summary': {'stack_frame_seeds': len(seeds), 'candidates': len(functions),
                        'valid_walks': sum(function['walk_ok'] for function in functions),
                        'candidate_bytes': sum(function['size'] for function in functions)},
            'functions': functions,
        })
    return {
        'version': 1, 'provisional': True, 'matching_credit': 0,
        'rom_sha1': EXPECTED_SHA1,
        'units': units,
        'evidence': {
            'pointer_at': POINTER_AT, 'pointer_value': pointer,
            'pointee_rom': POINTEE_AT, 'pointee_text': POINTEE[:-1].decode(),
            'analysis_module_sha256': sha256(Path(function_analysis.__file__).read_bytes()).hexdigest(),
            'generator_sha256': sha256(Path(__file__).read_bytes()).hexdigest(),
        },
        'summary': {'candidates': sum(unit['summary']['candidates'] for unit in units),
                    'valid_walks': sum(unit['summary']['valid_walks'] for unit in units)},
    }


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--output', type=Path,
                        default=ROOT / 'config/survey/overlay_ceremony_candidates.json')
    parser.add_argument('--check', action='store_true')
    args = parser.parse_args()
    text = json.dumps(render(args.rom.read_bytes()), indent=2) + '\n'
    if args.check:
        if not args.output.is_file() or args.output.read_text() != text:
            raise ValueError('overlay survey differs; regenerate with make overlay-survey')
    else:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text)
    result = json.loads(text)
    print(f"{result['summary']['candidates']} overlay candidates; "
          f"{result['summary']['valid_walks']} valid walks; no matching credit")


if __name__ == '__main__':
    main()
