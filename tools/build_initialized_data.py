#!/usr/bin/env python3
"""Build typed initialized-data units without executable text or ROM input.

The checked-in manifest fixes every owned initialized section and digest. Build
uses explicit symbols and placements only. --verify-rom reads the preservation
image after compilation and relocation, solely for a final comparison.
"""
from __future__ import annotations

import argparse
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import struct
import tempfile

ROOT = Path(__file__).resolve().parents[1]
TARGET = {'architecture': 'mips', 'byte_order': 'big', 'pointer_bits': 32, 'abi': 'o32'}
INITIALIZED_NAMES = {'.data', '.rodata', '.rdata', '.sdata', '.lit4', '.lit8'}


def initialized_name(name: str) -> bool:
    return name in INITIALIZED_NAMES or any(
        name.startswith(prefix + '.') for prefix in INITIALIZED_NAMES
    )


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def local_path(project: Path, name: str) -> Path:
    path = Path(name)
    if path.is_absolute() or '..' in path.parts:
        raise ValueError(f'expected repository-relative input path: {name}')
    candidate = project / path
    if not candidate.resolve().is_relative_to(project.resolve()):
        raise ValueError(f'input escapes project: {name}')
    return candidate


def snapshot(project: Path, paths) -> list[dict]:
    return [{'path': str(path.relative_to(project)), 'sha256': sha256(path.read_bytes())}
            for path in sorted(set(paths))]


def check_inputs(project: Path, inputs: list[dict]) -> None:
    if not inputs:
        raise ValueError('initialized-data artifact has no input provenance')
    for item in inputs:
        path = local_path(project, item['path'])
        if not path.is_file() or sha256(path.read_bytes()) != item['sha256']:
            raise ValueError(f'stale initialized-data input: {item["path"]}')


def validate_manifest(config: dict, project: Path) -> None:
    if config.get('version') != 1 or config.get('target') != TARGET:
        raise ValueError('expected big-endian MIPS/o32, 32-bit data manifest')
    maps = {item['id']: item for item in config['segments']}
    if len(maps) != len(config['segments']):
        raise ValueError('duplicate data segment id')
    ids = set()
    for unit in config['units']:
        if unit['id'] in ids:
            raise ValueError('duplicate initialized-data unit id')
        ids.add(unit['id'])
        if unit['pipeline'] not in ('sn', 'kmc+as', 'kmc+asn64', 'kmc+builtin'):
            raise ValueError('unreviewed initialized-data compiler pipeline')
        if Path(unit['source']).suffix != '.c':
            raise ValueError('initialized-data units must be C sources')
        if unit['source'] not in unit['inputs']:
            raise ValueError('data source is absent from frozen unit inputs')
        for name, expected in unit['inputs'].items():
            path = local_path(project, name)
            if not path.is_file() or sha256(path.read_bytes()) != expected:
                raise ValueError(f'stale initialized-data unit input: {name}')
        for value in unit.get('symbols', {}).values():
            if not isinstance(value, int) or not 0 <= value <= 0xFFFFFFFF:
                raise ValueError('symbol does not fit a 32-bit N64 address')
        names = set()
        for section in unit['sections']:
            if not initialized_name(section['name']) or section['name'] in names:
                raise ValueError('unexpected or duplicate initialized section declaration')
            names.add(section['name'])
            segment = maps[section['segment']]
            start, size, vram = section['rom_start'], section['size'], section['vram']
            if any(type(value) is not int for value in (start, size, vram)):
                raise ValueError('initialized-data placements require explicit integer widths')
            if size <= 0:
                raise ValueError('initialized-data section must own a positive extent')
            if not (segment['rom_start'] <= start < start + size <= segment['rom_end']):
                raise ValueError('initialized-data section escapes its segment')
            if vram != start + segment['vram_delta'] or not (0 <= vram < vram + size <= 0x100000000):
                raise ValueError('inconsistent ROM/VRAM placement or 32-bit overflow')
            if len(section['sha256']) != 64:
                raise ValueError('initialized-data section has no reviewed digest')
        if not names:
            raise ValueError('initialized-data unit has no owned sections')


@dataclass
class Piece:
    unit_id: str
    source: str
    section: str
    segment: str
    rom_start: int
    vram: int
    data: bytes

    def metadata(self):
        return {'unit_id': self.unit_id, 'source': self.source, 'section': self.section,
                'segment': self.segment, 'rom_start': self.rom_start, 'vram': self.vram,
                'size': len(self.data), 'sha256': sha256(self.data)}


def elf_section_flags(elf) -> dict[str, int]:
    raw = elf.data
    if raw[:7] != b'\x7fELF\x01\x02\x01' or struct.unpack_from('>HH', raw, 16) != (1, 8):
        raise ValueError('expected an ELF32 big-endian relocatable MIPS object')
    abi_flags, = struct.unpack_from('>I', raw, 0x24)
    if abi_flags & 0x20 or abi_flags & 0xF000 not in (0, 0x1000):
        raise ValueError('expected o32-compatible MIPS object ABI flags')
    table, = struct.unpack_from('>I', raw, 0x20)
    stride, = struct.unpack_from('>H', raw, 0x2E)
    return {section.name: struct.unpack_from('>I', raw, table + section.index * stride + 8)[0]
            for section in elf.sections}


def extract_pieces(elf, flags: dict[str, int], unit: dict) -> list[Piece]:
    declarations = {section['name']: section for section in unit['sections']}
    bases = {name: section['vram'] for name, section in declarations.items()}
    found, result = set(), []
    for section in elf.sections:
        if section.name in ('.reginfo', '.MIPS.abiflags'):
            continue
        if section.size and (section.name == '.text' or flags.get(section.name, 0) & 4):
            raise ValueError(f'{unit["id"]}: executable text is forbidden in data-only units')
        if not section.size or section.type == 8:
            continue
        if not flags.get(section.name, 0) & 2:
            continue
        if section.name not in declarations:
            raise ValueError(f'{unit["id"]}: unexpected/unplaced initialized section {section.name}')
        declaration = declarations[section.name]
        # Elf.relocate defaults unspecified defined-section bases to zero;
        # reject such references instead of letting that implicit default link.
        for _, _, symbol_index, _ in elf.relocations(section):
            symbol = elf.symbols[symbol_index]
            if 0 < symbol.section < len(elf.sections):
                name = elf.sections[symbol.section].name
                if name not in bases:
                    raise ValueError(f'{unit["id"]}: reference to unplaced {name}')
        # Plain dict provides no address-name inference or ROM lookup fallback.
        data = elf.relocate(section.name, bases, dict(unit.get('symbols', {})))
        if len(data) != declaration['size'] or section.size != declaration['size']:
            raise ValueError(f'{unit["id"]}: initialized section extent changed')
        if sha256(data) != declaration['sha256']:
            raise ValueError(f'{unit["id"]}: initialized section digest changed')
        found.add(section.name)
        result.append(Piece(unit['id'], unit['source'], section.name, declaration['segment'],
                            declaration['rom_start'], declaration['vram'], data))
    if found != set(declarations):
        raise ValueError(f'{unit["id"]}: declared initialized section missing from compiler output')
    return result


def merge_pieces(pieces: list[Piece]) -> dict[int, int]:
    owned = {}
    for piece in pieces:
        for offset, value in enumerate(piece.data, piece.rom_start):
            if offset in owned and owned[offset] != value:
                raise ValueError(f'conflicting initialized-data overlap at ROM {offset:#x}')
            owned[offset] = value
    return owned


def ranges_of(owned: dict[int, int]) -> list[dict]:
    ranges = []
    for address in sorted(owned):
        if ranges and ranges[-1]['rom_end'] == address:
            ranges[-1]['rom_end'] += 1
        else:
            ranges.append({'rom_start': address, 'rom_end': address + 1})
    for extent in ranges:
        data = bytes(owned[address] for address in range(extent['rom_start'], extent['rom_end']))
        extent.update(size=len(data), sha256=sha256(data))
    return ranges


def build_data(config_path: Path, output: Path, project: Path = ROOT,
               verify_rom: Path | None = None) -> dict:
    from n64dk.elf import Elf
    from n64dk.match.pipeline import BuildSpec, build
    from n64dk.match.toolchain import load_config
    config = json.loads(config_path.read_text())
    validate_manifest(config, project)
    paths = {config_path, project / 'tools/build_initialized_data.py'}
    for unit in config['units']:
        paths.update(local_path(project, name) for name in unit['inputs'])
        for name in unit.get('include_dirs', []):
            directory = local_path(project, name)
            if not directory.is_dir():
                raise ValueError(f'missing initialized-data include directory: {name}')
            paths.update(path for path in directory.rglob('*') if path.is_file())
        # Local quoted headers can be found before explicitly supplied -I roots.
        source_directory = local_path(project, unit['source']).parent
        paths.update(path for path in source_directory.rglob('*')
                     if path.is_file() and path.suffix.lower() in ('.h', '.inc'))
    inputs = snapshot(project, paths)
    cfg = load_config(project)
    pieces, provenance = [], []
    with tempfile.TemporaryDirectory(prefix='sydney-initialized-data-') as tmp:
        for number, unit in enumerate(config['units']):
            work = Path(tmp) / str(number)
            work.mkdir()
            spec = BuildSpec(unit['pipeline'], list(unit['flags']))
            obj = build(local_path(project, unit['source']), spec, cfg, work,
                        includes=[local_path(project, root) for root in unit.get('include_dirs', [])])
            elf = Elf.load(obj)
            produced = extract_pieces(elf, elf_section_flags(elf), unit)
            pieces.extend(produced)
            provenance.append({'unit_id': unit['id'], 'pipeline': unit['pipeline'],
                               'compiler_flags': unit['flags'], 'source': unit['source'],
                               'object_sha256': sha256(obj.read_bytes()),
                               'symbols': unit.get('symbols', {})})
    owned = merge_pieces(pieces)
    check_inputs(project, inputs)
    if verify_rom is not None:
        # This is the first and only point at which the builder can read ROM.
        rom = verify_rom.read_bytes()
        if hashlib.sha1(rom).hexdigest() != config['rom_sha1']:
            raise ValueError('initialized-data verification ROM identity differs')
        for piece in pieces:
            if rom[piece.rom_start:piece.rom_start + len(piece.data)] != piece.data:
                raise ValueError(f'{piece.unit_id}: source-built initialized data differs from ROM')
    output.mkdir(parents=True, exist_ok=True)
    metadata = []
    for number, piece in enumerate(pieces):
        filename = f'{number:04d}_{piece.unit_id}_{piece.section.lstrip(".")}.bin'
        (output / filename).write_bytes(piece.data)
        metadata.append(dict(piece.metadata(), file=filename))
    # Keep toolkit implementation hashes distinct from ROM-free repo inputs.
    import n64dk.elf
    toolkit = Path(n64dk.elf.__file__).parent
    tool_inputs = [{'path': '@n64dk/' + str(path.relative_to(toolkit)),
                    'sha256': sha256(path.read_bytes())}
                   for path in sorted(toolkit.rglob('*.py'))]
    result = {'version': 1, 'artifact_kind': 'source-built initialized data only',
              'complete_rom': False, 'new_function_bodies': 0,
              'rom_sha1': config['rom_sha1'], 'target': config['target'],
              'config_path': str(config_path.relative_to(project)),
              'inputs': inputs, 'toolkit_inputs': tool_inputs,
              'unique_initialized_bytes': len(owned), 'ranges': ranges_of(owned),
              'pieces': metadata, 'units': provenance,
              'placement_inference': False, 'post_build_rom_comparison': verify_rom is not None}
    temporary = output / 'initialized_data.json.tmp'
    temporary.write_text(json.dumps(result, indent=2) + '\n')
    temporary.replace(output / 'initialized_data.json')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=('build', 'check'), nargs='?', default='build')
    parser.add_argument('--config', type=Path, default=ROOT / 'config/data/units.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/initialized_data')
    parser.add_argument('--project', type=Path, default=ROOT)
    parser.add_argument('--verify-rom', type=Path)
    args = parser.parse_args()
    project, output = args.project.resolve(), args.output.resolve()
    if args.command == 'check':
        metadata = json.loads((output / 'initialized_data.json').read_text())
        check_inputs(project, metadata['inputs'])
        for piece in metadata['pieces']:
            if sha256((output / piece['file']).read_bytes()) != piece['sha256']:
                raise ValueError('initialized-data piece artifact changed')
        print('initialized-data inputs and source-built piece hashes are fresh')
    else:
        result = build_data(args.config.resolve(), output, project,
                            args.verify_rom.resolve() if args.verify_rom else None)
        print(f'built {len(result["pieces"])} initialized-data pieces, '
              f'{result["unique_initialized_bytes"]} unique bytes; no executable text')


if __name__ == '__main__':
    main()
