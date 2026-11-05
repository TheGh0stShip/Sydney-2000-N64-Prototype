#!/usr/bin/env python3
"""Capture reviewed residual ROM ranges as explicit source-literal data."""
import argparse
from hashlib import sha1, sha256
import json
from pathlib import Path

from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
CONFIG = ROOT / 'config/residual_literals.json'


def capture(rom_path, gaps_path):
    rom = rom_path.read_bytes()
    if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported original ROM')
    gaps = json.loads(gaps_path.read_text())['gaps']
    ranges = []
    for index, gap in enumerate(gaps):
        start, end = gap['rom_start'], gap['rom_end']
        data = rom[start:end]
        ranges.append({'id': f'residual_{index:04d}', 'rom_start': start,
                       'size': len(data), 'sha256': sha256(data).hexdigest(),
                       'data_hex': data.hex()})
    config = {'version': 1, 'kind': 'reviewed source-literal residual data',
              'rom_sha1': EXPECTED_SHA1, 'ranges': ranges}
    CONFIG.write_text(json.dumps(config, indent=2) + '\n')
    print(f'captured {len(ranges)} residual ranges, {sum(x["size"] for x in ranges)} bytes')


def build(config_path, output_dir):
    source = config_path.read_bytes(); config = json.loads(source)
    if config.get('version') != 1 or config.get('rom_sha1') != EXPECTED_SHA1:
        raise ValueError('unsupported residual-literal configuration')
    output_dir.mkdir(parents=True, exist_ok=True)
    pieces = []; cursor = -1
    for item in config['ranges']:
        start = item['rom_start']; data = bytes.fromhex(item['data_hex'])
        if start < cursor or len(data) != item['size'] or sha256(data).hexdigest() != item['sha256']:
            raise ValueError(f'invalid residual literal {item["id"]}')
        name = item['id'] + '.bin'; (output_dir / name).write_bytes(data)
        pieces.append({key: item[key] for key in ('id', 'rom_start', 'size', 'sha256')} |
                      {'file': name})
        cursor = start + len(data)
    metadata = {'version': 1, 'kind': config['kind'], 'complete_component': True,
                'complete_rom': False, 'config': 'config/residual_literals.json',
                'config_sha256': sha256(source).hexdigest(),
                'generator_sha256': sha256(Path(__file__).read_bytes()).hexdigest(),
                'pieces': pieces}
    (output_dir / 'residual_literals.json').write_text(json.dumps(metadata, indent=2) + '\n')
    print(f'built {len(pieces)} residual literal ranges, {sum(x["size"] for x in pieces)} bytes')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('capture', 'build'))
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--gaps', type=Path,
                        default=ROOT / 'build/reconstruction/reconstruction.json')
    parser.add_argument('--config', type=Path, default=CONFIG)
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'build/residual_literals')
    args = parser.parse_args()
    if args.action == 'capture': capture(args.rom, args.gaps)
    else: build(args.config, args.output_dir)


if __name__ == '__main__': main()
