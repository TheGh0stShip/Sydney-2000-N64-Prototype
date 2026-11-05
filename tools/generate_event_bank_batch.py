#!/usr/bin/env python3
"""Generate exact symbolic sources/manifests for clean event-bank candidates."""
import argparse
from hashlib import sha256
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
SURVEY = ROOT / 'config/survey/overlay_ceremony_candidates.json'
MANIFEST = ROOT / 'config/overlay/event_bank/matching_sn.tsv'
FLAGS = '-O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--limit', type=int, default=20)
    parser.add_argument('--include-invalid', action='store_true')
    parser.add_argument('--objdump', type=Path, required=True)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    args = parser.parse_args()
    survey = json.loads(SURVEY.read_text())
    unit = next(item for item in survey['units'] if item['name'] == 'event_bank')
    existing = MANIFEST.read_text().splitlines() if MANIFEST.exists() else []
    owned = {int(line.split('\t')[0], 0) for line in existing if line and not line.startswith('#')}
    candidates = [item for item in unit['functions'] if (item['walk_ok'] or args.include_invalid) and
                  item['size'] > 0 and item['rom_start'] not in owned]
    candidates.sort(key=lambda item: (-item['size'], item['rom_start']))
    rom = args.rom.read_bytes()
    rows = list(existing)
    generated = 0
    for item in candidates[:args.limit]:
        address, start, size = item['vram'], item['rom_start'], item['size']
        name = item['name']
        relative = f'src/overlays/event_bank_{name}.c'
        source = ROOT / relative
        text = subprocess.check_output([
            'python3', str(ROOT / 'tools/generate_symbolic_overlay_asm.py'),
            str(args.rom), hex(start), hex(size), name, '--delta', '0x80000000',
            '--objdump', str(args.objdump),
        ], text=True)
        source.write_text(text)
        symbols = sorted(set(re.findall(r'(?:func|branch)_[0-9A-F]{8}', text)) - {name})
        symbol_flags = ' '.join(
            f'--symbol={symbol}:0x{symbol.split("_", 1)[1]}' for symbol in symbols)
        digest = sha256(rom[start:start + size]).hexdigest()
        options = (symbol_flags + ' ' if symbol_flags else '') + FLAGS
        rows.append(f'{start:#x}\t{size:#x}\t{relative}\t{options}\t{digest}')
        generated += size
    header = [line for line in rows if line.startswith('#')]
    body = sorted((line for line in rows if line and not line.startswith('#')),
                  key=lambda line: int(line.split('\t')[0], 0))
    MANIFEST.write_text('\n'.join(header + body) + '\n')
    print(f'generated {min(args.limit, len(candidates))} event-bank functions, {generated} bytes')


if __name__ == '__main__':
    main()
