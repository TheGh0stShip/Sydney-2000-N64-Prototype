#!/usr/bin/env python3
"""Rebuild fixed-width archive metadata without reading original ROM bytes.

Only the directory is reconstructed here. No payload, executable code, or
unknown binary is copied or credited as decompiled. Optional ROM comparison
occurs after the component has been built entirely from typed TSV fields.
"""
import argparse
import csv
from hashlib import sha1, sha256
import json
from pathlib import Path
import struct

from verify import EXPECTED_SHA1, EXPECTED_SIZE

ROOT = Path(__file__).resolve().parents[1]
DIRECTORY_START = 0x1A3AB0
DIRECTORY_END = 0x224B78
PAYLOAD_END = 0x1DC1CE2
RECORD_SIZE = 0x4C
FIELDS = ('index', 'record_at', 'logical_offset', 'physical_start', 'physical_end',
          'size', 'aux', 'role', 'kind', 'canonical_index', 'sha1', 'name')


def number(row, field):
    try:
        return int(row[field], 0)
    except (KeyError, TypeError, ValueError) as error:
        raise ValueError(f'invalid archive field {field}: {row.get(field)!r}') from error


def read_records(path):
    with path.open(newline='') as source:
        reader = csv.DictReader(source, delimiter='\t', quoting=csv.QUOTE_NONE)
        if tuple(reader.fieldnames or ()) != FIELDS:
            raise ValueError('archive inventory schema changed')
        rows = list(reader)
        if any(None in row or any(value is None for value in row.values()) for row in rows):
            raise ValueError('malformed archive inventory row')
        return rows


def build_directory(rows, start=DIRECTORY_START, end=DIRECTORY_END,
                    payload_end=PAYLOAD_END):
    if not rows or end - start != 4 + RECORD_SIZE * len(rows):
        raise ValueError('archive count does not fit its assigned directory extent')
    result = bytearray(struct.pack('>I', len(rows)))
    canonical = {}
    for index, row in enumerate(rows):
        if number(row, 'index') != index:
            raise ValueError(f'archive record indices are not contiguous at {index}')
        if number(row, 'record_at') != start + 4 + index * RECORD_SIZE:
            raise ValueError(f'archive record {index}: inconsistent record address')
        size, logical, aux = (number(row, field) for field in ('size', 'logical_offset', 'aux'))
        if any(not 0 <= value <= 0xFFFFFFFF for value in (size, logical, aux)):
            raise ValueError(f'archive record {index}: field exceeds unsigned 32-bit width')
        left, right = number(row, 'physical_start'), number(row, 'physical_end')
        if left != end + logical or right != left + size or not end <= left <= right <= payload_end:
            raise ValueError(f'archive record {index}: inconsistent payload extent')
        owner = canonical.setdefault((left, right), index)
        if number(row, 'canonical_index') != owner:
            raise ValueError(f'archive record {index}: inconsistent duplicate alias')
        try:
            name = row['name'].encode('ascii')
        except (KeyError, UnicodeError) as error:
            raise ValueError(f'archive record {index}: non-ASCII name') from error
        if not 0 < len(name) < 64 or any(value < 32 or value == 127 for value in name):
            raise ValueError(f'archive record {index}: name does not fit a terminated 64-byte field')
        result += struct.pack('>III64s', size, logical, aux, name)
    return bytes(result)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory', type=Path, default=ROOT / 'config/inventory/archive_records.tsv')
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'build/rom_components')
    parser.add_argument('--verify-rom', type=Path)
    args = parser.parse_args()
    source = args.inventory.read_bytes()
    component = build_directory(read_records(args.inventory))
    # Reading the ROM is optional and cannot influence any emitted field.
    if args.verify_rom:
        original = args.verify_rom.read_bytes()
        if len(original) != EXPECTED_SIZE or sha1(original).hexdigest() != EXPECTED_SHA1:
            raise ValueError('unsupported original ROM')
        if component != original[DIRECTORY_START:DIRECTORY_END]:
            raise ValueError('rebuilt archive directory differs from original ROM')
    if source != args.inventory.read_bytes():
        raise ValueError('archive inventory changed during reconstruction')
    args.output_dir.mkdir(parents=True, exist_ok=True)
    output = args.output_dir / 'file_directory.bin'
    output.write_bytes(component)
    metadata = {
        'version': 1, 'kind': 'reconstructed archive-directory metadata',
        'complete_component': True, 'complete_rom': False, 'decompiled_code_bytes': 0,
        'rom_start': DIRECTORY_START, 'rom_end': DIRECTORY_END, 'size': len(component),
        'records': (len(component) - 4) // RECORD_SIZE,
        'source': 'config/inventory/archive_records.tsv' if args.inventory.resolve() ==
                  (ROOT / 'config/inventory/archive_records.tsv').resolve() else args.inventory.name,
        'source_sha256': sha256(source).hexdigest(),
        'generator_sha256': sha256(Path(__file__).read_bytes()).hexdigest(),
        'sha256': sha256(component).hexdigest(), 'file': output.name,
        'payload_included': False,
    }
    (args.output_dir / 'file_directory.json').write_text(json.dumps(metadata, indent=2) + '\n')
    print(f'rebuilt {metadata["records"]} archive records ({len(component)} bytes); no payload included')


if __name__ == '__main__':
    main()
