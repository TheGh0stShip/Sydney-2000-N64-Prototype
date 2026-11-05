#!/usr/bin/env python3
"""Assemble reviewed symbolic RSP programs; ROM is optional post-build verification only."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
TARGET = {'architecture': 'rsp', 'scalar_bits': 32, 'byte_order': 'big',
          'vector_coprocessor': 'RSP COP2', 'cpu_abi': None}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def local(project, name):
    p = Path(name)
    if p.is_absolute() or '..' in p.parts or not p.parts:
        raise ValueError(f'expected repository-relative path: {name}')
    result = project / p
    if not result.resolve().is_relative_to(project.resolve()):
        raise ValueError(f'path escapes repository: {name}')
    return result


def check_inputs(project, inputs):
    if not inputs:
        raise ValueError('RSP provenance has no frozen inputs')
    for item in inputs:
        path = local(project, item['path'])
        if not path.is_file() or digest(path.read_bytes()) != item['sha256']:
            raise ValueError(f'stale RSP input: {item["path"]}')


def validate(config, project):
    if config.get('version') != 1 or config.get('target') != TARGET:
        raise ValueError('expected explicitly big-endian RSP target, without CPU ABI')
    if type(config.get('rom_size')) is not int or config['rom_size'] != 0x2000000:
        raise ValueError('expected reviewed 32 MiB ROM envelope')
    check_inputs(project, [{'path': p, 'sha256': h} for p, h in config['inputs'].items()])
    ids = set()
    for unit in config['units']:
        if unit['id'] in ids or not unit['id'].replace('_', '').isalnum():
            raise ValueError('duplicate or invalid RSP unit id')
        ids.add(unit['id'])
        if unit['recipe'] not in ('f3dex2_make', 'armips', 'rspboot_align16'):
            raise ValueError('unsupported RSP assembly recipe')
        if unit['source'] not in config['inputs']:
            raise ValueError('RSP source is not frozen')
        names = set()
        for section in unit['sections']:
            name = section['name']
            if name not in ('.text', '.data') or name in names:
                raise ValueError('unsupported or duplicate RSP section')
            names.add(name)
            start, size, storage = (section[k] for k in ('rom_start', 'size', 'storage_vram'))
            if any(type(v) is not int for v in (start, size, storage)) or size <= 0:
                raise ValueError('RSP placement requires positive integer size and addresses')
            if not 0x1000 <= start < start + size <= config['rom_size']:
                raise ValueError('RSP section outside ROM bounds')
            if storage != start + 0x7FFFF400 or storage + size > 0x100000000:
                raise ValueError('RSP CPU storage address differs from explicit resident mapping')
            if start + size > 0x69070:
                raise ValueError('RSP source section escapes resident image')
            if len(section['sha256']) != 64:
                raise ValueError('RSP output has no reviewed digest')
            if not section['logical_mappings']:
                raise ValueError('RSP output lacks IMEM/DMEM mapping')
            mapped = set()
            for mapping in section['logical_mappings']:
                offset, count, address = (mapping[k] for k in ('file_offset', 'size', 'rsp_address'))
                memory = mapping['memory']
                if any(type(v) is not int for v in (offset, count, address)) or count <= 0:
                    raise ValueError('RSP mapping requires integer address and positive size')
                if offset < 0 or offset + count > size:
                    raise ValueError('logical RSP mapping escapes emitted section')
                base = 0x1000 if memory == 'IMEM' else 0 if memory == 'DMEM' else -1
                if base < 0 or not base <= address < address + count <= base + 0x1000:
                    raise ValueError('RSP mapping escapes its 4 KiB memory bank')
                mapped.update(range(offset, offset + count))
                if (name == '.text') != (memory == 'IMEM'):
                    raise ValueError('RSP code/data mapped to wrong memory bank')
            if len(mapped) != size:
                raise ValueError('RSP logical mappings leave emitted bytes unspecified')
            if name == '.text' and size % 4:
                raise ValueError('RSP instruction storage must contain whole 32-bit words')
            if 'instruction_bytes' in section and section['instruction_bytes'] + section.get('alignment_bytes', 0) != size:
                raise ValueError('RSP instruction and padding lengths differ from output size')
            if unit['recipe'] == 'rspboot_align16':
                if section.get('instruction_bytes') != 204 or section.get('alignment_bytes') != 4:
                    raise ValueError('boot must separate 204 instruction bytes and four alignment bytes')
        if not names or (unit['recipe'] == 'f3dex2_make' and names != {'.text', '.data'}):
            raise ValueError('missing owned RSP assembler output')
    for dependency in config.get('dependencies', []):
        path = local(project, dependency['path'])
        result = subprocess.run(['git', '-C', str(path), 'rev-parse', 'HEAD'],
                                capture_output=True, text=True)
        if result.returncode or result.stdout.strip() != dependency['commit']:
            raise ValueError(f'RSP source dependency is not pinned: {dependency["path"]}')


def merge(pieces):
    owned = {}
    for metadata, data in pieces:
        if len(data) != metadata['size'] or digest(data) != metadata['sha256']:
            raise ValueError('RSP emitted section size/digest differs from reviewed declaration')
        for offset, value in enumerate(data, metadata['rom_start']):
            if offset in owned and owned[offset] != value:
                raise ValueError(f'conflicting RSP overlap at ROM {offset:#x}')
            owned[offset] = value
    return owned


def tool_identity(path):
    resolved = Path(path).resolve()
    return {'path': str(resolved), 'sha256': digest(resolved.read_bytes())}


def check_tools(tools):
    for item in tools:
        path = Path(item['path'])
        if not path.is_file() or digest(path.read_bytes()) != item['sha256']:
            raise ValueError(f'stale RSP build tool: {path}')


def run(argv, cwd):
    result = subprocess.run([str(x) for x in argv], cwd=cwd, capture_output=True, text=True)
    if result.returncode:
        raise ValueError(f'RSP assembler failed: {argv!r}\n{result.stdout}\n{result.stderr}')
    return result.stdout + result.stderr


def assemble(config, project, work, armips):
    pieces, recipes = [], []
    for unit in config['units']:
        directory = work / unit['id']
        directory.mkdir()
        source = local(project, unit['source'])
        if unit['recipe'] == 'f3dex2_make':
            command = ['make', '-s', '-C', source.parent, f'ARMIPS={armips}',
                       f'BUILD_DIR={directory}', 'F3DEX2_2.08']
            log = run(command, project)
            outputs = {'.text': directory / 'F3DEX2_2.08/F3DEX2_2.08.code',
                       '.data': directory / 'F3DEX2_2.08/F3DEX2_2.08.data'}
        else:
            assembled_source = source
            if unit['recipe'] == 'rspboot_align16':
                text = source.read_text()
                if text.count('.close') != 1 or '.incbin' in text:
                    raise ValueError('boot alignment recipe requires one symbolic source output')
                # This is a declared source-level alignment directive, never ROM padding input.
                text = text.replace('.close', '.align 16\n.close')
                assembled_source = directory / 'rspboot_aligned.s'
                assembled_source.write_text(text)
            outputs = {'.text': directory / 'code.bin'}
            command = [armips, '-strequ', 'CODE_FILE', outputs['.text'],
                       '-sym2', directory / 'symbols.txt', assembled_source]
            log = run(command, project / 'tools/battletanx_ga')
        if set(outputs) != {s['name'] for s in unit['sections']}:
            raise ValueError('assembler outputs are not fully declared')
        recipes.append({'unit_id': unit['id'], 'source': unit['source'], 'recipe': unit['recipe'],
                        'argv': [str(x) for x in command], 'assembler_log': log,
                        'alignment_transform': '.close -> .align 16; .close'
                        if unit['recipe'] == 'rspboot_align16' else None})
        for section in unit['sections']:
            data = outputs[section['name']].read_bytes()
            pieces.append((dict(section, unit_id=unit['id'], source=unit['source']), data))
    return pieces, recipes


def verify(pieces, rom_path, config):
    # Called only after all source compilation, digest and overlap checks succeed.
    rom = rom_path.read_bytes()
    if len(rom) != config['rom_size'] or hashlib.sha1(rom).hexdigest() != config['rom_sha1']:
        raise ValueError('RSP verification ROM identity differs')
    for metadata, data in pieces:
        start = metadata['rom_start']
        if rom[start:start + len(data)] != data:
            raise ValueError(f'{metadata["unit_id"]}: source-built RSP output differs from ROM')


def build_rsp(config_path, output, project=ROOT, armips=None, verify_rom=None):
    config_path, output, project = map(lambda p: Path(p).resolve(), (config_path, output, project))
    config = json.loads(config_path.read_text())
    validate(config, project)
    cache = project / '.toolchain/armips/armips'
    executable = (armips or os.environ.get('ARMIPS') or
                  (str(cache) if cache.is_file() else None) or shutil.which('armips'))
    if not executable:
        raise ValueError('RSP assembler missing; set ARMIPS to pinned armips (see config/rsp/units.json)')
    executable = str(Path(executable).resolve())
    tools = [dict(tool_identity(executable), role='armips')]
    for command in ('make', 'cpp'):
        path = shutil.which(command)
        if not path:
            raise ValueError(f'RSP build requires {command}')
        tools.append(dict(tool_identity(path), role=command))
    inputs = [{'path': name, 'sha256': value} for name, value in config['inputs'].items()]
    for path in (config_path, project / 'tools/build_rsp.py'):
        inputs.append({'path': str(path.relative_to(project)), 'sha256': digest(path.read_bytes())})
    with tempfile.TemporaryDirectory(prefix='sydney-rsp-') as temp:
        pieces, recipes = assemble(config, project, Path(temp), executable)
        owned = merge(pieces)
        check_inputs(project, inputs)
        check_tools(tools)
        if verify_rom is not None:
            verify(pieces, Path(verify_rom), config)
        output.mkdir(parents=True, exist_ok=True)
        metadata = []
        for number, (piece, data) in enumerate(pieces):
            filename = f'{number:02d}_{piece["unit_id"]}_{piece["name"][1:]}.bin'
            (output / filename).write_bytes(data)
            metadata.append(dict(piece, file=filename))
    result = {'version': 1, 'artifact_kind': 'source-built RSP microcode', 'target': TARGET,
              'complete_rom': False, 'new_cpu_function_bodies': 0,
              'rom_sha1': config['rom_sha1'], 'rom_size': config['rom_size'],
              'config_path': str(config_path.relative_to(project)), 'inputs': inputs,
              'tools': tools, 'assembler_source_recipe': config['assembler'],
              'dependencies': config.get('dependencies', []), 'units': recipes,
              'pieces': metadata, 'unique_owned_bytes': len(owned),
              'placement_inference': False, 'post_build_rom_comparison': verify_rom is not None}
    temporary = output / 'rsp.json.tmp'
    temporary.write_text(json.dumps(result, indent=2) + '\n')
    temporary.replace(output / 'rsp.json')
    return result


def check_artifact(path, project=ROOT):
    artifact = json.loads(path.read_text())
    if artifact.get('artifact_kind') != 'source-built RSP microcode' or artifact.get('target') != TARGET:
        raise ValueError('unsupported RSP artifact')
    check_inputs(project, artifact['inputs'])
    if sorted(item.get('role', '') for item in artifact['tools']) != ['armips', 'cpp', 'make']:
        raise ValueError('RSP artifact lacks complete build-tool provenance')
    check_tools(artifact['tools'])
    config = json.loads(local(project, artifact['config_path']).read_text())
    validate(config, project)
    expected_inputs = dict(config['inputs'])
    for input_path in (local(project, artifact['config_path']), project / 'tools/build_rsp.py'):
        expected_inputs[str(input_path.relative_to(project))] = digest(input_path.read_bytes())
    actual_inputs = {item['path']: item['sha256'] for item in artifact['inputs']}
    if actual_inputs != expected_inputs or len(actual_inputs) != len(artifact['inputs']):
        raise ValueError('RSP artifact input provenance differs from producer/config/source set')
    if (artifact.get('complete_rom') is not False or artifact.get('placement_inference') is not False
            or artifact.get('rom_sha1') != config['rom_sha1']
            or artifact.get('rom_size') != config['rom_size']
            or artifact.get('assembler_source_recipe') != config['assembler']
            or artifact.get('dependencies') != config.get('dependencies', [])):
        raise ValueError('RSP artifact identity or provenance differs from configuration')
    declarations = {(u['id'], s['name']): dict(s, unit_id=u['id'], source=u['source'])
                    for u in config['units'] for s in u['sections']}
    pieces = []
    for piece in artifact['pieces']:
        key = (piece['unit_id'], piece['name'])
        if key not in declarations or {k: v for k, v in piece.items() if k != 'file'} != declarations.pop(key):
            raise ValueError('RSP artifact placement/provenance changed')
        pieces.append((piece, local(path.parent, piece['file']).read_bytes()))
    if declarations or len(merge(pieces)) != artifact['unique_owned_bytes']:
        raise ValueError('RSP artifact coverage differs from reviewed declarations')
    return artifact


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=('build', 'check'), nargs='?', default='build')
    parser.add_argument('--config', type=Path, default=ROOT / 'config/rsp/units.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/rsp')
    parser.add_argument('--project', type=Path, default=ROOT)
    parser.add_argument('--armips', type=Path)
    parser.add_argument('--verify-rom', type=Path)
    args = parser.parse_args()
    if args.command == 'check':
        artifact = check_artifact(args.output.resolve() / 'rsp.json', args.project.resolve())
    else:
        artifact = build_rsp(args.config, args.output, args.project, args.armips, args.verify_rom)
    print(f'{len(artifact["pieces"])} source-built RSP sections; '
          f'{artifact["unique_owned_bytes"]} unique bytes; complete_rom=false')


if __name__ == '__main__':
    main()
