#!/usr/bin/env python3
"""Compose verified source and extracted-asset artifacts into a preservation ROM.

The composer never reads the original ROM unless --verify-rom is requested. It
accepts frozen source pieces, typed initialized data, symbolic RSP microcode,
reconstructed archive metadata, and separately extracted/hash-checked archive
assets. Ownership is independent of byte value: unowned zero fill receives no
credit. --verify-rom compares owned bytes only after composition.
"""
from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[1]
ROM_SIZE = 0x2000000
ROM_SHA1 = '711c79790a713e65cc2ecb4857f35898b8e92985'
RESIDENT_START, RESIDENT_END, RESIDENT_DELTA = 0x1000, 0x69070, 0x7FFFF400
RUNTIME_START, RUNTIME_END, RUNTIME_DELTA = 0x127640, 0x1A3AB0, 0x7FF5C710
DIRECTORY_START, DIRECTORY_END, DIRECTORY_RECORDS = 0x1A3AB0, 0x224B78, 6955
PAYLOAD_START, PAYLOAD_END = 0x224B78, 0x1DC1CE2
TARGET = {'architecture': 'mips', 'byte_order': 'big', 'pointer_bits': 32, 'abi': 'o32'}
REGIONS = ((0, 0x40, 'header'), (0x40, 0x1000, 'IPL3 executable'),
           (0x1000, 0x69070, 'resident code and initialized data'),
           (0x69070, 0x127640, 'executable overlay banks'),
           (0x127640, 0x1A3AB0, 'startup runtime code and catalog'),
           (0x1A3AB0, 0x224B78, 'archive directory metadata'),
           (0x224B78, 0x2596A0, 'texture catalog'),
           (0x2596A0, 0x55D554, 'texture payload and alignment'),
           (0x55D554, 0x1DC1CE2, 'named asset payload and alignment'),
           (0x1DC1CE2, ROM_SIZE, 'cartridge capacity fill'))


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def safe_path(base: Path, name: str) -> Path:
    path = Path(name)
    if path.is_absolute() or '..' in path.parts:
        raise ValueError(f'unsafe relative artifact/input path: {name}')
    target = base / path
    if not target.resolve().is_relative_to(base.resolve()):
        raise ValueError(f'artifact/input path escapes its root: {name}')
    return target


def toolkit_root():
    # Resolve the installed SDK location only; importing build/relocation code is
    # unnecessary during composition and cannot silently perform ROM inference.
    spec = importlib.util.find_spec('n64dk')
    if spec is None or spec.origin is None:
        raise ValueError('n64dk hashes require the project PYTHONPATH used by make source-pieces')
    return Path(spec.origin).resolve().parent


class Evidence:
    def __init__(self, project, sdk_root=None):
        self.project = project.resolve()
        self.sdk_root = sdk_root
        self.files = {}
        self.names = {}
        self.external_tools = []

    def read(self, path: Path, expected=None):
        path = path.absolute()
        try:
            data = path.read_bytes()
        except FileNotFoundError as error:
            raise ValueError(f'missing reconstruction input: {path}') from error
        actual = sha256(data)
        if expected is not None and actual != expected:
            raise ValueError(f'stale or corrupt reconstruction input: {path}')
        if path in self.files and self.files[path] != actual:
            raise ValueError(f'reconstruction input changed while composing: {path}')
        self.files[path] = actual
        return data

    def repo(self, name, expected=None):
        path = safe_path(self.project, name)
        data = self.read(path, expected)
        self.names[path.absolute()] = name
        return data

    def json(self, path, expected=None):
        return json.loads(self.read(path, expected))

    def check_inputs(self, inputs):
        if isinstance(inputs, dict):
            inputs = [{'path': path, 'sha256': value} for path, value in inputs.items()]
        names = set()
        toolkit_names = set()
        for item in inputs:
            name = item['path']
            if name in names:
                raise ValueError(f'duplicate provenance input: {name}')
            names.add(name)
            if name.startswith('@n64dk/'):
                root = self.sdk_root or toolkit_root()
                relative = name.removeprefix('@n64dk/')
                path = safe_path(root, relative)
                self.read(path, item['sha256'])
                self.names[path.absolute()] = name
                toolkit_names.add(relative)
            else:
                self.repo(name, item['sha256'])
        if toolkit_names:
            root = self.sdk_root or toolkit_root()
            actual = {str(path.relative_to(root)) for path in root.rglob('*.py')}
            if actual != toolkit_names:
                raise ValueError('stale n64dk provenance file set; rediscover/rebuild source providers')
        return names

    def fresh(self):
        if self.external_tools:
            import build_rsp
            build_rsp.check_tools(self.external_tools)
        for path, expected in list(self.files.items()):
            self.read(path, expected)

    def metadata(self):
        repo, toolkit = [], []
        for path, value in sorted(self.files.items()):
            name = self.names.get(path)
            if name is None:
                if not path.resolve().is_relative_to(self.project):
                    raise ValueError('component artifact lies outside the project')
                name = str(path.relative_to(self.project))
            target = toolkit if name.startswith('@n64dk/') else repo
            target.append({'path': name, 'sha256': value})
        return repo, toolkit


class RomImage:
    def __init__(self, size=ROM_SIZE):
        self.data = bytearray(size)
        self.owned = bytearray(size)
        self.equal_overlap_bytes = 0

    def add(self, start, payload, owner):
        if type(start) is not int or start < 0 or start + len(payload) > len(self.data):
            raise ValueError(f'{owner}: component escapes ROM bounds')
        for offset, value in enumerate(payload, start):
            if self.owned[offset]:
                if self.data[offset] != value:
                    raise ValueError(f'{owner}: conflicting overlap at ROM {offset:#x}')
                self.equal_overlap_bytes += 1
            else:
                self.data[offset] = value
                self.owned[offset] = 1

    def gaps(self):
        gaps, index = [], 0
        while index < len(self.owned):
            if self.owned[index]:
                index += 1
                continue
            start = index
            while index < len(self.owned) and not self.owned[index]:
                index += 1
            gaps.append({'rom_start': start, 'rom_end': index, 'size': index - start})
        return gaps


def require_region(start, size, left, right, label):
    if type(start) is not int or type(size) is not int or size < 0 or not left <= start <= start + size <= right:
        raise ValueError(f'{label}: component outside its approved region')


def classified_data(evidence):
    rows = evidence.repo('config/survey/ledger.tsv').decode().splitlines()[1:]
    return [(int(fields[0], 0), int(fields[1], 0))
            for row in rows if (fields := row.split('\t'))[3] == 'data']


def require_data(start, size, intervals):
    covered = sum(max(0, min(start + size, end) - max(start, begin)) for begin, end in intervals)
    if covered != size:
        raise ValueError('initialized-data piece escapes classified data')


def piece_bytes(evidence, artifact, item, size, expected):
    data = evidence.read(safe_path(artifact.parent, item['file']), expected)
    if len(data) != size:
        raise ValueError('source/component piece size differs from declared ownership')
    return data


def resident_input_names(project, units):
    names = {unit['source'] for unit in units} | {unit['manifest'] for unit in units}
    names.update(('config/segments.toml', 'config/survey/symbol_addrs.txt',
                  'tools/build_source_image.py', 'tools/normalize_kmc_wrappers.py',
                  'tools/verify_ido_normalized.py', 'tools/verify_sn_normalized.py'))
    for root in {name for unit in units for name in unit['includes']}:
        names.update(str(path.relative_to(project)) for path in safe_path(project, root).rglob('*')
                     if path.is_file() and '__pycache__' not in path.parts)
    return names


def load_resident(evidence, artifact, data_intervals):
    if not artifact.is_file():
        raise ValueError('resident source artifacts missing; run make source-pieces')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or metadata.get('complete_rom') is not False or
            metadata.get('artifact_kind') != 'source-relocated resident partial image'):
        raise ValueError('unsupported resident reconstruction artifact kind')
    if (metadata.get('rom_start'), metadata.get('rom_end')) != (RESIDENT_START, RESIDENT_END):
        raise ValueError('resident artifact uses an unsupported address map')
    plan = json.loads(evidence.repo('config/link_units.json', metadata['link_plan_sha256']))
    if plan.get('version') != 1 or plan.get('rom_sha1') != ROM_SHA1:
        raise ValueError('unsupported resident link plan or ROM identity')
    if (plan['resident_rom_start'], plan['resident_rom_end']) != (RESIDENT_START, RESIDENT_END):
        raise ValueError('resident link plan address map changed')
    inputs = evidence.check_inputs(plan['inputs'])
    repository_inputs = {name for name in inputs if not name.startswith('@n64dk/')}
    if repository_inputs != resident_input_names(evidence.project, plan['units']):
        raise ValueError('resident source/header input set changed; rediscover and rebuild source providers')
    if 'tools/build_source_image.py' not in inputs:
        raise ValueError('resident producer tool is not pinned by its link plan')
    manifest_paths = {name for name in inputs if name.startswith('config/matching') and name.endswith('.tsv')}
    current = {str(path.relative_to(evidence.project)) for path in (evidence.project / 'config').glob('matching*.tsv')}
    if manifest_paths != current:
        raise ValueError('resident manifest set changed; run make source-link-plan then make source-pieces')
    rows = {}
    for path in manifest_paths:
        for line in evidence.repo(path).decode().splitlines():
            if not line or line.startswith('#'):
                continue
            key = Path(path).name + ':' + sha256(line.encode())[:16]
            if key in rows:
                raise ValueError('duplicate resident manifest row')
            rows[key] = line.split('\t')
    units = {unit['id']: unit for unit in plan['units']}
    if len(units) != len(plan['units']) or set(units) != set(rows):
        raise ValueError('resident plan does not cover the current manifest rows')
    expected = {}
    for unit in units.values():
        row = rows[unit['id']]
        if row[2] != unit['source'] or sha256(evidence.repo(unit['source'])) != unit['source_sha256']:
            raise ValueError('resident source provenance changed')
        for section in unit['sections']:
            if section['name'] not in {'.text', '.data', '.rodata', '.rdata', '.sdata', '.lit4', '.lit8'}:
                raise ValueError('unknown resident initialized/code section')
            key = unit['id'], section['name']
            if key in expected:
                raise ValueError('duplicate resident section placement')
            if section['name'] == '.text' and (section['rom_start'], section['owned_size']) != (int(row[0], 0), int(row[1], 0)):
                raise ValueError('resident text placement differs from its manifest')
            expected[key] = unit, section
    produced, seen = [], set()
    provider_image = RomImage(RESIDENT_END)
    for piece in metadata['pieces']:
        key = piece['unit_id'], piece['name']
        if key not in expected or key in seen:
            raise ValueError('unexpected/duplicate resident source piece')
        seen.add(key)
        unit, section = expected[key]
        for field in ('rom_start', 'vram', 'owned_size', 'emitted_size', 'unowned_zero_tail', 'sha256'):
            if piece[field] != section[field]:
                raise ValueError(f'resident piece differs from frozen section: {field}')
        if piece['source'] != unit['source'] or piece['source_sha256'] != unit['source_sha256']:
            raise ValueError('resident piece source attribution differs from frozen plan')
        start, size = piece['rom_start'], piece['owned_size']
        require_region(start, size, RESIDENT_START, RESIDENT_END, 'resident source')
        if piece['vram'] != start + RESIDENT_DELTA:
            raise ValueError('resident piece ROM/VRAM mapping changed')
        if piece['name'] != '.text':
            require_data(start, size, data_intervals)
        data = piece_bytes(evidence, artifact, piece, size, section['sha256'])
        owner = 'resident-source:' + piece['unit_id'] + ':' + piece['name']
        provider_image.add(start, data, owner)
        produced.append((start, data, {'owner': owner, 'kind': 'resident source section',
                                      'source': unit['source'], 'section': piece['name']}))
    if seen != set(expected) or sum(provider_image.owned) != metadata['covered_bytes']:
        raise ValueError('resident artifact is missing source pieces or has incorrect coverage')
    return produced


def data_input_names(project, config):
    paths = {'config/data/units.json', 'tools/build_initialized_data.py'}
    for unit in config['units']:
        paths.update(unit['inputs'])
        for name in unit.get('include_dirs', []):
            paths.update(str(path.relative_to(project)) for path in safe_path(project, name).rglob('*') if path.is_file())
        directory = safe_path(project, unit['source']).parent
        paths.update(str(path.relative_to(project)) for path in directory.rglob('*')
                     if path.is_file() and path.suffix.lower() in ('.h', '.inc'))
    return paths


def load_initialized(evidence, artifact, data_intervals):
    if not artifact.is_file():
        raise ValueError('typed data artifacts missing; run tools/build_initialized_data.py with the project toolchain environment')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or metadata.get('complete_rom') is not False or
            metadata.get('artifact_kind') != 'source-built initialized data only'):
        raise ValueError('unsupported initialized-data artifact kind')
    if metadata.get('target') != TARGET or metadata.get('rom_sha1') != ROM_SHA1 or metadata.get('new_function_bodies') != 0:
        raise ValueError('initialized-data ABI/identity/code classification changed')
    if metadata['config_path'] != 'config/data/units.json':
        raise ValueError('unsupported initialized-data manifest path')
    names = evidence.check_inputs(metadata['inputs'])
    evidence.check_inputs(metadata['toolkit_inputs'])
    config = json.loads(evidence.repo('config/data/units.json'))
    if config.get('version') != 1 or config.get('target') != TARGET or config.get('rom_sha1') != ROM_SHA1:
        raise ValueError('unsupported typed-data configuration')
    segment_maps = {item['id']: item for item in config['segments']}
    approved_maps = {
        'resident': {'id': 'resident', 'rom_start': RESIDENT_START,
                     'rom_end': RESIDENT_END, 'vram_delta': RESIDENT_DELTA},
        'closing': {'id': 'closing', 'rom_start': 0x6DF40,
                    'rom_end': 0x70800, 'vram_delta': 0x80002554},
    }
    if segment_maps != approved_maps:
        raise ValueError('typed-data segment maps changed')
    if names != data_input_names(evidence.project, config):
        raise ValueError('typed-data input set changed; rebuild initialized-data artifacts')
    expected = {}
    unit_ids = {unit['id'] for unit in config['units']}
    if len(unit_ids) != len(config['units']):
        raise ValueError('duplicate typed-data compilation unit')
    producers = {unit['unit_id']: unit for unit in metadata['units']}
    if set(producers) != unit_ids or len(producers) != len(metadata['units']):
        raise ValueError('typed-data compilation provenance is incomplete')
    for unit in config['units']:
        producer = producers[unit['id']]
        for field, expected_value in (('pipeline', unit['pipeline']), ('compiler_flags', unit['flags']),
                                      ('source', unit['source']), ('symbols', unit.get('symbols', {}))):
            if producer[field] != expected_value:
                raise ValueError('typed-data producer differs from its reviewed compilation recipe')
        for path, digest in unit['inputs'].items():
            evidence.repo(path, digest)
        for section in unit['sections']:
            initialized = {'.data', '.rodata', '.rdata', '.sdata', '.lit4', '.lit8'}
            if (section['name'] not in initialized and
                    not any(section['name'].startswith(name + '.') for name in initialized)):
                raise ValueError('typed-data artifact cannot own executable or unknown sections')
            key = unit['id'], section['name']
            if key in expected:
                raise ValueError('duplicate initialized-data declaration')
            expected[key] = unit, section
    seen, produced, provider_image = set(), [], RomImage(ROM_SIZE)
    for piece in metadata['pieces']:
        key = piece['unit_id'], piece['section']
        if key not in expected or key in seen:
            raise ValueError('unexpected/duplicate initialized-data source piece')
        seen.add(key)
        unit, section = expected[key]
        for field in ('rom_start', 'vram', 'size', 'sha256', 'segment'):
            if piece[field] != section[field]:
                raise ValueError(f'initialized-data piece differs from its declaration: {field}')
        if piece['source'] != unit['source'] or piece['segment'] not in segment_maps:
            raise ValueError('unsupported initialized-data source/segment attribution')
        start, size = piece['rom_start'], piece['size']
        segment = segment_maps[piece['segment']]
        require_region(start, size, segment['rom_start'], segment['rom_end'], 'typed data')
        if piece['segment'] == 'resident':
            require_data(start, size, data_intervals)
        if piece['vram'] != start + segment['vram_delta']:
            raise ValueError('initialized-data ROM/VRAM map changed')
        data = piece_bytes(evidence, artifact, piece, size, section['sha256'])
        owner = 'typed-data:' + piece['unit_id'] + ':' + piece['section']
        provider_image.add(start, data, owner)
        produced.append((start, data, {'owner': owner, 'kind': 'typed initialized data',
                                      'source': piece['source'], 'section': piece['section']}))
    if seen != set(expected) or sum(provider_image.owned) != metadata['unique_initialized_bytes']:
        raise ValueError('typed-data source artifact is incomplete or has incorrect coverage')
    return produced


def load_mapped_segment(evidence, artifact, segment, plan_name, start_bound, end_bound, delta):
    if not artifact.is_file():
        raise ValueError(f'{segment} source artifacts missing; run make {segment}-pieces')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or metadata.get('complete_rom') is not False or
            metadata.get('artifact_kind') != f'source-relocated {segment} partial image' or
            metadata.get('segment') != segment):
        raise ValueError(f'unsupported {segment} reconstruction artifact kind')
    if (metadata.get('rom_start'), metadata.get('rom_end')) != (start_bound, end_bound):
        raise ValueError(f'{segment} artifact uses an unsupported address map')
    plan = evidence.json(evidence.project / plan_name,
                         metadata['link_plan_sha256'])
    if (plan.get('version') != 1 or plan.get('rom_sha1') != ROM_SHA1 or
            plan.get('segment') != segment or
            (plan.get('rom_start'), plan.get('rom_end')) != (start_bound, end_bound)):
        raise ValueError(f'unsupported {segment} link plan')
    evidence.check_inputs(plan['inputs'])
    units = {unit['id']: unit for unit in plan['units']}
    expected = {(unit['id'], section['name']): (unit, section)
                for unit in plan['units'] for section in unit['sections']}
    if len(units) != len(plan['units']) or len(expected) != sum(
            len(unit['sections']) for unit in plan['units']):
        raise ValueError('duplicate runtime source declarations')
    produced, seen, provider = [], set(), RomImage(RUNTIME_END)
    for piece in metadata['pieces']:
        key = piece['unit_id'], piece['name']
        if key not in expected or key in seen:
            raise ValueError('unexpected/duplicate runtime source piece')
        seen.add(key)
        unit, section = expected[key]
        for field in ('rom_start', 'vram', 'owned_size', 'emitted_size',
                      'unowned_zero_tail', 'sha256'):
            if piece[field] != section[field]:
                raise ValueError(f'runtime piece differs from frozen section: {field}')
        if piece['source'] != unit['source'] or piece['source_sha256'] != unit['source_sha256']:
            raise ValueError('runtime piece source attribution differs from frozen plan')
        start, size = piece['rom_start'], piece['owned_size']
        require_region(start, size, start_bound, end_bound, segment + ' source')
        if piece['vram'] != start + delta:
            raise ValueError(f'{segment} piece ROM/VRAM mapping changed')
        data = piece_bytes(evidence, artifact, piece, size, section['sha256'])
        owner = 'runtime-source:' + piece['unit_id'] + ':' + piece['name']
        provider.add(start, data, owner)
        produced.append((start, data, {'owner': owner, 'kind': 'runtime source section',
                                       'source': unit['source'], 'section': piece['name']}))
    if seen != set(expected) or sum(provider.owned) != metadata['covered_bytes']:
        raise ValueError('runtime artifact is missing source pieces or has incorrect coverage')
    return produced


def load_runtime(evidence, artifact):
    return load_mapped_segment(evidence, artifact, 'runtime',
                               'config/runtime_link_units.json',
                               RUNTIME_START, RUNTIME_END, RUNTIME_DELTA)


def load_ceremony(evidence, artifact):
    return load_mapped_segment(evidence, artifact, 'ceremony',
                               'config/overlay_link_units.json',
                               0x69070, 0x6DF40, 0x80007924)


def load_closing(evidence, artifact):
    return load_mapped_segment(evidence, artifact, 'closing',
                               'config/closing_link_units.json',
                               0x6DF40, 0x70800, 0x80002554)


def load_event_bank(evidence, artifact):
    return load_mapped_segment(evidence, artifact, 'event_bank',
                               'config/event_bank_link_units.json',
                               0x70800, 0x127640, 0x80000000)


def load_static_layout(evidence):
    """Serialize typed cartridge metadata and deterministic unused capacity."""
    config = json.loads(evidence.repo('config/rom_layout.json'))
    if (config.get('version') != 1 or config.get('byte_order') != 'big' or
            int(config['rom_size'], 0) != ROM_SIZE):
        raise ValueError('unsupported typed ROM layout')
    name = config['name'].encode('ascii')
    cartridge_id = bytes.fromhex(config['cartridge_id'])
    if len(name) > 20 or len(cartridge_id) != 2:
        raise ValueError('invalid N64 header text/identifier width')
    header = bytearray(0x40)
    struct.pack_into('>7I', header, 0,
                     int(config['pi_bsd_domain_1'], 0), int(config['clock_rate'], 0),
                     int(config['entry_point'], 0), int(config['release'], 0),
                     int(config['crc1'], 0), int(config['crc2'], 0), 0)
    header[0x20:0x34] = name.ljust(20, b' ')
    header[0x3B] = config['manufacturer_id']
    header[0x3C:0x3E] = cartridge_id
    header[0x3E] = config['country_code']
    header[0x3F] = config['version_byte']
    fill_start = int(config['capacity_fill_start'], 0)
    fill_value = config['capacity_fill_value']
    if not 0 <= fill_value <= 255 or not 0x1DC1CE2 <= fill_start <= ROM_SIZE:
        raise ValueError('invalid cartridge capacity-fill declaration')
    return [(0, bytes(header), {'owner': 'typed-rom-header', 'kind': 'typed N64 header',
                                'source': 'config/rom_layout.json'}),
            (fill_start, bytes([fill_value]) * (ROM_SIZE - fill_start),
             {'owner': 'capacity-fill', 'kind': 'deterministic cartridge capacity fill',
              'source': 'config/rom_layout.json'})]



def load_rsp(evidence, artifact, data_intervals):
    if not artifact.is_file():
        raise ValueError('RSP source artifacts missing; run make rsp-pieces')
    import build_rsp
    metadata = evidence.json(artifact)
    # The producer's strict checker binds every piece to the reviewed config,
    # complete source-input set, actual tools, and pinned dependency revision.
    build_rsp.check_artifact(artifact, evidence.project)
    evidence.repo('tools/build_rsp.py', sha256(Path(build_rsp.__file__).read_bytes()))
    evidence.check_inputs(metadata['inputs'])
    evidence.external_tools.extend(metadata['tools'])
    if metadata['config_path'] != 'config/rsp/units.json':
        raise ValueError('unsupported RSP manifest path')
    produced = []
    for piece in metadata['pieces']:
        start, size = piece['rom_start'], piece['size']
        if piece['name'] == '.text':
            require_region(start, size, 0x2EC0, 0x4F80, 'RSP instruction image')
        elif piece['name'] == '.data':
            require_region(start, size, 0x39170, 0x39590, 'RSP initial DMEM data')
            require_data(start, size, data_intervals)
        else:
            raise ValueError('unsupported RSP initialized section')
        if piece['storage_vram'] != start + RESIDENT_DELTA:
            raise ValueError('RSP CPU storage map changed')
        data = piece_bytes(evidence, artifact, piece, size, piece['sha256'])
        owner = 'rsp-source:' + piece['unit_id'] + ':' + piece['name']
        produced.append((start, data, {'owner': owner, 'kind': 'symbolic RSP source',
                                      'source': piece['source'], 'section': piece['name'],
                                      'logical_mappings': piece['logical_mappings']}))
    return produced


def load_directory(evidence, artifact):
    if not artifact.is_file():
        raise ValueError('archive-directory artifact missing; run make archive-directory')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or metadata.get('complete_rom') is not False or
            metadata.get('kind') != 'reconstructed archive-directory metadata'):
        raise ValueError('unsupported ROM component artifact kind')
    if not metadata.get('complete_component') or metadata.get('payload_included') is not False or metadata.get('decompiled_code_bytes') != 0:
        raise ValueError('archive-directory artifact contains unsupported payload/code claims')
    if (metadata['rom_start'], metadata['rom_end'], metadata['size'], metadata['records']) != (
            DIRECTORY_START, DIRECTORY_END, DIRECTORY_END - DIRECTORY_START, DIRECTORY_RECORDS):
        raise ValueError('archive directory escapes its exact approved metadata region')
    if metadata['source'] != 'config/inventory/archive_records.tsv':
        raise ValueError('unsupported archive-directory source path')
    evidence.repo(metadata['source'], metadata['source_sha256'])
    evidence.repo('tools/build_archive_directory.py', metadata['generator_sha256'])
    # The producer is pure serialization; reconstruct again from its checked
    # typed records rather than trusting a self-declared binary hash alone.
    import build_archive_directory as directory
    if sha256(Path(directory.__file__).read_bytes()) != metadata['generator_sha256']:
        raise ValueError('directory serializer differs from its pinned producer tool')
    source = safe_path(evidence.project, metadata['source'])
    expected = directory.build_directory(directory.read_records(source))
    data = piece_bytes(evidence, artifact, metadata, metadata['size'], metadata['sha256'])
    if data != expected:
        raise ValueError('archive-directory bytes differ from typed source serialization')
    return [(DIRECTORY_START, data, {'owner': 'archive-directory',
                                    'kind': 'reconstructed archive-directory metadata',
                                    'source': metadata['source']})]


def load_archive_payload(evidence, artifact):
    if not artifact.is_file():
        raise ValueError('archive payload artifact missing; run make archive-assets')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or metadata.get('kind') != 'extracted named archive assets' or
            not metadata.get('complete_component') or metadata.get('complete_rom') is not False):
        raise ValueError('unsupported archive payload artifact kind')
    if (metadata['rom_start'], metadata['rom_end'], metadata['size']) != (
            PAYLOAD_START, PAYLOAD_END, PAYLOAD_END - PAYLOAD_START):
        raise ValueError('archive payload escapes its assigned extent')
    evidence.repo(metadata['inventory'], metadata['inventory_sha256'])
    evidence.repo('tools/build_archive_payload.py', metadata['generator_sha256'])
    asset_dir = evidence.project / 'build/archive_assets/files'
    if metadata['asset_count'] != len(metadata['inputs']):
        raise ValueError('archive payload asset count changed')
    for item in metadata['inputs']:
        path = safe_path(asset_dir, item['file'])
        data = evidence.read(path, item['sha256'])
        if len(data) != item['size'] or hashlib.sha1(data).hexdigest() != item['sha1']:
            raise ValueError(f'archive asset failed validation: {item["file"]}')
    import build_archive_payload as payload
    rebuilt, expected_inputs = payload.assemble(
        safe_path(evidence.project, metadata['inventory']), asset_dir)
    if expected_inputs != metadata['inputs']:
        raise ValueError('archive payload input manifest differs from inventory/assets')
    data = piece_bytes(evidence, artifact, metadata, metadata['size'], metadata['sha256'])
    if data != rebuilt:
        raise ValueError('archive payload artifact differs from its named assets')
    return [(PAYLOAD_START, data, {'owner': 'archive-assets',
                                  'kind': 'extracted named archive assets',
                                  'source': metadata['inventory']})]


def load_residual_literals(evidence, artifact):
    if not artifact.is_file():
        raise ValueError('residual literal artifact missing; run make residual-literals')
    metadata = evidence.json(artifact)
    if (metadata.get('version') != 1 or
            metadata.get('kind') != 'reviewed source-literal residual data' or
            not metadata.get('complete_component') or metadata.get('complete_rom') is not False):
        raise ValueError('unsupported residual literal artifact')
    config = json.loads(evidence.repo(metadata['config'], metadata['config_sha256']))
    evidence.repo('tools/build_residual_literals.py', metadata['generator_sha256'])
    if len(config['ranges']) != len(metadata['pieces']):
        raise ValueError('residual literal piece set changed')
    produced = []
    for source, piece in zip(config['ranges'], metadata['pieces']):
        if any(source[key] != piece[key] for key in ('id', 'rom_start', 'size', 'sha256')):
            raise ValueError('residual literal metadata differs from source')
        expected = bytes.fromhex(source['data_hex'])
        data = piece_bytes(evidence, artifact, piece, source['size'], source['sha256'])
        if data != expected:
            raise ValueError(f'residual literal bytes differ: {source["id"]}')
        produced.append((source['rom_start'], data,
                         {'owner': 'residual-literal:' + source['id'],
                          'kind': metadata['kind'], 'source': metadata['config']}))
    return produced


def compose(project, resident, initialized, directory, output, verify_rom=None,
            require_complete=False, rsp=None, runtime=None, ceremony=None, closing=None,
            payload=None, event_bank=None):
    evidence = Evidence(project)
    evidence.repo('tools/compose_reconstruction.py', sha256(Path(__file__).read_bytes()))
    rsp = rsp or project / 'build/rsp/rsp.json'
    runtime = runtime or project / 'build/runtime_image/source_image.json'
    ceremony = ceremony or project / 'build/overlay_ceremony/source_image.json'
    closing = closing or project / 'build/overlay_closing/source_image.json'
    payload = payload or project / 'build/rom_components/archive_payload.json'
    event_bank = event_bank or project / 'build/overlay_event_bank/source_image.json'
    residual = project / 'build/residual_literals/residual_literals.json'
    for path in (resident, initialized, directory, rsp, runtime, ceremony, closing, payload,
                 event_bank, residual):
        if not path.resolve().is_relative_to(project.resolve()):
            raise ValueError('component metadata must be inside the project')
    data_intervals = classified_data(evidence)
    pieces = (load_resident(evidence, resident, data_intervals) +
              load_initialized(evidence, initialized, data_intervals) +
              load_rsp(evidence, rsp, data_intervals) +
              load_runtime(evidence, runtime) +
              load_ceremony(evidence, ceremony) +
              load_closing(evidence, closing) +
              load_event_bank(evidence, event_bank) +
              load_directory(evidence, directory) +
              load_archive_payload(evidence, payload) +
              load_residual_literals(evidence, residual) +
              load_static_layout(evidence))
    image, provenance = RomImage(ROM_SIZE), []
    for start, data, source in pieces:
        image.add(start, data, source['owner'])
        provenance.append(dict(source, rom_start=start, rom_end=start + len(data),
                               size=len(data), sha256=sha256(data)))
    evidence.fresh()
    gaps = image.gaps()
    actual_sha1 = hashlib.sha1(image.data).hexdigest()
    complete = not gaps and actual_sha1 == ROM_SHA1
    if not gaps and not complete:
        raise ValueError('fully owned ROM does not have the preservation SHA-1')
    if verify_rom is not None:
        original = verify_rom.read_bytes()
        if len(original) != ROM_SIZE or hashlib.sha1(original).hexdigest() != ROM_SHA1:
            raise ValueError('unsupported verification ROM identity')
        for start, data, source in pieces:
            if original[start:start + len(data)] != data:
                raise ValueError(f'{source["owner"]}: owned bytes differ from verification ROM')
    evidence.fresh()
    inputs, toolkit = evidence.metadata()
    summary = {'version': 1, 'artifact_kind': 'source reconstruction whole-ROM partial image',
               'complete_rom': complete, 'expected_rom_sha1': ROM_SHA1, 'rom_size': ROM_SIZE,
               'partial_image_sha1': actual_sha1, 'partial_sha1_is_completion_gate': False,
               'owned_bytes': sum(image.owned), 'unowned_bytes': ROM_SIZE - sum(image.owned),
               'equal_overlap_bytes': image.equal_overlap_bytes,
               'post_composition_rom_comparison': verify_rom is not None,
               'inputs': inputs, 'toolkit_inputs': toolkit, 'build_tools': evidence.external_tools,
               'pieces': provenance, 'gaps': gaps,
               'regions': [dict(rom_start=start, rom_end=end, name=name,
                                owned_bytes=sum(image.owned[start:end]),
                                unowned_bytes=end - start - sum(image.owned[start:end]))
                           for start, end, name in REGIONS],
               'composer_path': 'tools/compose_reconstruction.py',
               'composer_sha256': sha256(Path(__file__).read_bytes())}
    output.mkdir(parents=True, exist_ok=True)
    (output / 'rom.partial.bin').write_bytes(image.data)
    (output / 'rom.ownership.bin').write_bytes(image.owned)
    (output / 'reconstruction.json').write_text(json.dumps(summary, indent=2) + '\n')
    full = output / 'rom.z64'
    if complete:
        full.write_bytes(image.data)
    elif full.exists():
        full.unlink()
    if require_complete and not complete:
        first = ', '.join(f'{gap["rom_start"]:#x}..{gap["rom_end"]:#x}' for gap in gaps[:5])
        raise ValueError(f'complete ROM refused: {summary["unowned_bytes"]} unowned bytes in '
                         f'{len(gaps)} gaps; first gaps: {first}; see {output / "reconstruction.json"}')
    print(f'composed {summary["owned_bytes"]} owned ROM bytes; '
          f'{summary["unowned_bytes"]} remain unowned; complete_rom={complete}')
    return summary


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=ROOT)
    parser.add_argument('--resident', type=Path, default=ROOT / 'build/source_image/source_image.json')
    parser.add_argument('--initialized', type=Path, default=ROOT / 'build/initialized_data/initialized_data.json')
    parser.add_argument('--rsp', type=Path, default=ROOT / 'build/rsp/rsp.json')
    parser.add_argument('--runtime', type=Path, default=ROOT / 'build/runtime_image/source_image.json')
    parser.add_argument('--ceremony', type=Path, default=ROOT / 'build/overlay_ceremony/source_image.json')
    parser.add_argument('--closing', type=Path, default=ROOT / 'build/overlay_closing/source_image.json')
    parser.add_argument('--directory', type=Path, default=ROOT / 'build/rom_components/file_directory.json')
    parser.add_argument('--payload', type=Path, default=ROOT / 'build/rom_components/archive_payload.json')
    parser.add_argument('--event-bank', type=Path, default=ROOT / 'build/overlay_event_bank/source_image.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/reconstruction')
    parser.add_argument('--verify-rom', type=Path)
    parser.add_argument('--require-complete', action='store_true')
    args = parser.parse_args()
    compose(args.project.resolve(), args.resident.resolve(), args.initialized.resolve(),
            args.directory.resolve(), args.output.resolve(),
            args.verify_rom.resolve() if args.verify_rom else None, args.require_complete,
            args.rsp.resolve(), args.runtime.resolve(), args.ceremony.resolve(),
            args.closing.resolve(), args.payload.resolve(), args.event_bank.resolve())


if __name__ == '__main__':
    main()
