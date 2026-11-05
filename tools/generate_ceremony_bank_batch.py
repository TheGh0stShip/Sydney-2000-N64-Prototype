#!/usr/bin/env python3
"""Generate symbolic sources for every surveyed ceremony-bank candidate."""
import json, re, subprocess
from hashlib import sha256
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM = ROOT / 'baserom.z64'
OUT = ROOT / 'config/overlay/ceremony/matching_sweep_sn.tsv'
OBJDUMP = ROOT.parent / 'BattleTanx/.toolchain/mips-binutils/usr/bin/mips-linux-gnu-objdump'
FLAGS = '-O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb'


def starts(path):
    return {int(line.split('\t')[0], 0) for line in path.read_text().splitlines()
            if line and not line.startswith('#')} if path.exists() else set()


def main():
    survey = json.loads((ROOT / 'config/survey/overlay_ceremony_candidates.json').read_text())
    unit = next(item for item in survey['units'] if item['name'] == 'ceremony')
    owned = starts(ROOT / 'config/overlay/ceremony/matching_sn.tsv') | starts(OUT)
    rows = OUT.read_text().splitlines() if OUT.exists() else []
    rom = ROM.read_bytes(); count = size_sum = 0
    for item in unit['functions']:
        if item['rom_start'] in owned or not item['size']:
            continue
        name, start, size = item['name'], item['rom_start'], item['size']
        relative = f'src/overlays/ceremony_sweep_{name}.c'
        text = subprocess.check_output([
            'python3', str(ROOT / 'tools/generate_symbolic_overlay_asm.py'), str(ROM),
            hex(start), hex(size), name, '--delta', '0x80007924', '--objdump', str(OBJDUMP)], text=True)
        (ROOT / relative).write_text(text)
        symbols = sorted(set(re.findall(r'(?:func|branch)_[0-9A-F]{8}', text)) - {name})
        options = ' '.join(f'--symbol={s}:0x{s.split("_", 1)[1]}' for s in symbols)
        options = (options + ' ' if options else '') + FLAGS
        rows.append(f'{start:#x}\t{size:#x}\t{relative}\t{options}\t'
                    f'{sha256(rom[start:start + size]).hexdigest()}')
        count += 1; size_sum += size
    header = ['# Complete ceremony sweep; ROM-to-VRAM delta 0x80007924.']
    body = sorted((line for line in rows if line and not line.startswith('#')),
                  key=lambda line: int(line.split('\t')[0], 0))
    OUT.write_text('\n'.join(header + body) + '\n')
    print(f'generated {count} ceremony functions, {size_sum} bytes')


if __name__ == '__main__': main()
