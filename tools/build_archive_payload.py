#!/usr/bin/env python3
"""Extract and rebuild the named archive payload as individually hashed assets."""
import argparse
import csv
from hashlib import sha1, sha256
import json
from pathlib import Path

from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
START = 0x224B78
END = 0x1DC1CE2


def records(path):
    with path.open(newline='') as source:
        rows = list(csv.DictReader(source, delimiter='\t'))
    return [row for row in rows if row['index'] == row['canonical_index']]


def asset_path(directory, row):
    return directory / f"{int(row['index']):04d}.bin"


def extract(rom_path, inventory, asset_dir):
    rom = rom_path.read_bytes()
    if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported original ROM')
    asset_dir.mkdir(parents=True, exist_ok=True)
    count = 0
    for row in records(inventory):
        left, right = int(row['physical_start'], 0), int(row['physical_end'], 0)
        data = rom[left:right]
        if len(data) != int(row['size']) or sha1(data).hexdigest() != row['sha1']:
            raise ValueError(f"archive asset {row['index']} differs from inventory")
        asset_path(asset_dir, row).write_bytes(data)
        count += 1
    print(f'extracted {count} unique archive assets')


def assemble(inventory, asset_dir):
    unique = records(inventory)
    image = bytearray([0xFF]) * (END - START)
    inputs = []
    cursor = START
    for row in sorted(unique, key=lambda item: int(item['physical_start'], 0)):
        left, right = int(row['physical_start'], 0), int(row['physical_end'], 0)
        if not START <= left <= right <= END or left < cursor:
            raise ValueError(f"invalid archive asset extent {row['index']}")
        path = asset_path(asset_dir, row)
        data = path.read_bytes()
        digest = sha1(data).hexdigest()
        if len(data) != int(row['size']) or digest != row['sha1'] or right - left != len(data):
            raise ValueError(f"archive asset {row['index']} failed size/hash validation")
        image[left - START:right - START] = data
        inputs.append({'index': int(row['index']), 'name': row['name'],
                       'file': path.name, 'size': len(data), 'sha1': digest,
                       'sha256': sha256(data).hexdigest()})
        cursor = right
    return bytes(image), inputs


def build(inventory, asset_dir, output_dir, verify_rom=None):
    source = inventory.read_bytes()
    data, inputs = assemble(inventory, asset_dir)
    if verify_rom:
        rom = verify_rom.read_bytes()
        if len(rom) != EXPECTED_SIZE or sha1(rom).hexdigest() != EXPECTED_SHA1:
            raise ValueError('unsupported verification ROM')
        if data != rom[START:END]:
            raise ValueError('rebuilt archive payload differs from original ROM')
    output_dir.mkdir(parents=True, exist_ok=True)
    output = output_dir / 'archive_payload.bin'
    output.write_bytes(data)
    metadata = {
        'version': 1, 'kind': 'extracted named archive assets',
        'complete_component': True, 'complete_rom': False,
        'rom_start': START, 'rom_end': END, 'size': len(data),
        'asset_count': len(inputs), 'alignment_fill': 0xFF,
        'inventory': 'config/inventory/archive_records.tsv',
        'inventory_sha256': sha256(source).hexdigest(),
        'generator_sha256': sha256(Path(__file__).read_bytes()).hexdigest(),
        'sha256': sha256(data).hexdigest(), 'file': output.name,
        'inputs': inputs,
    }
    (output_dir / 'archive_payload.json').write_text(json.dumps(metadata, indent=2) + '\n')
    print(f'rebuilt {len(inputs)} archive assets ({len(data)} bytes)')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('extract', 'build'))
    parser.add_argument('--rom', type=Path)
    parser.add_argument('--inventory', type=Path,
                        default=ROOT / 'config/inventory/archive_records.tsv')
    parser.add_argument('--asset-dir', type=Path, default=ROOT / 'build/archive_assets/files')
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'build/rom_components')
    parser.add_argument('--verify-rom', type=Path)
    args = parser.parse_args()
    if args.action == 'extract':
        if not args.rom:
            parser.error('extract requires --rom')
        extract(args.rom, args.inventory, args.asset_dir)
    else:
        build(args.inventory, args.asset_dir, args.output_dir, args.verify_rom)


if __name__ == '__main__':
    main()
