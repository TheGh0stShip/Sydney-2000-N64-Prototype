#!/usr/bin/env python3
"""Generate exact symbolic sources for the complete startup-runtime survey."""
import argparse
from hashlib import sha256
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SURVEY = ROOT / 'config/survey/overlay_ceremony_candidates.json'
MANIFEST = ROOT / 'config/runtime/matching_sweep_sn.tsv'
FLAGS = '-O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb'


def manifest_starts(path):
    if not path.exists():
        return set()
    return {int(line.split('\t')[0], 0) for line in path.read_text().splitlines()
            if line and not line.startswith('#')}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--objdump', type=Path, required=True)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    args = parser.parse_args()
    survey = json.loads(SURVEY.read_text())
    unit = next(item for item in survey['units'] if item['name'] == 'startup_runtime')
    existing = MANIFEST.read_text().splitlines() if MANIFEST.exists() else []
    owned = manifest_starts(MANIFEST)
    owned |= manifest_starts(ROOT / 'config/runtime/matching_sn.tsv')
    owned |= manifest_starts(ROOT / 'config/runtime/matching_kmc.tsv')
    rom = args.rom.read_bytes()
    rows = list(existing)
    candidates = [item for item in unit['functions'] if item['size'] > 0 and
                  item['rom_start'] not in owned]
    for item in candidates:
        start, size, name = item['rom_start'], item['size'], item['name']
        relative = f'src/runtime/sweep_{name}.c'
        text = subprocess.check_output([
            'python3', str(ROOT / 'tools/generate_symbolic_overlay_asm.py'),
            str(args.rom), hex(start), hex(size), name, '--delta', '0x7ff5c710',
            '--objdump', str(args.objdump),
        ], text=True)
        (ROOT / relative).write_text(text)
        symbols = sorted(set(re.findall(r'(?:func|branch)_[0-9A-F]{8}', text)) - {name})
        symbol_flags = ' '.join(
            f'--symbol={symbol}:0x{symbol.split("_", 1)[1]}' for symbol in symbols)
        options = (symbol_flags + ' ' if symbol_flags else '') + FLAGS
        digest = sha256(rom[start:start + size]).hexdigest()
        rows.append(f'{start:#x}\t{size:#x}\t{relative}\t{options}\t{digest}')
    header = [line for line in rows if line.startswith('#')]
    if not header:
        header = ['# Complete startup-runtime sweep; ROM-to-VRAM delta 0x7FF5C710.']
    body = sorted((line for line in rows if line and not line.startswith('#')),
                  key=lambda line: int(line.split('\t')[0], 0))
    MANIFEST.write_text('\n'.join(header + body) + '\n')
    print(f'generated {len(candidates)} startup-runtime functions, '
          f'{sum(item["size"] for item in candidates)} bytes')


if __name__ == '__main__':
    main()
