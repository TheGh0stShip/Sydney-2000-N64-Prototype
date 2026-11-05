#!/usr/bin/env python3
"""Discover a frozen resident link plan, then build source-only partial images.

Discovery may inspect the preservation ROM to resolve placements. Build never
loads it unless --verify-rom is explicitly supplied after source pieces exist.
Uncovered bytes are zero in the partial image but remain unowned in its bitmap;
this tool deliberately does not offer a complete-ROM target.
"""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
import hashlib
import importlib.util
import json
from pathlib import Path
import shlex
import tempfile

from n64dk.elf import Elf
from n64dk.match import compare, symbols as symmod
from n64dk.match.pipeline import BuildSpec, build, split_flags
from n64dk.match.toolchain import load_config

ROOT = Path(__file__).resolve().parents[1]
DELTA = 0x7FFFF400
START, END = 0x1000, 0x69070
SEGMENT = 'resident'
MANIFEST_DIR = 'config'
VERSION = 1
ROM_SECTIONS = ('.text', '.rodata', '.rdata', '.data', '.sdata', '.lit4', '.lit8')
PROFILES = {
    'matching_kmc.tsv': ('kmc+asn64', ['tools/ultralib/include']),
    'matching_kmc_hook.tsv': ('kmc+hook', ['tools/ultralib/include']),
    'matching_kmc_builtin.tsv': ('kmc+builtin', ['tools/ultralib/include', 'tools/ultralib/include/PR', 'tools/ultralib/src/audio', 'tools/ultralib/src/gu']),
    'matching_kmc_as.tsv': ('kmc+as', ['tools/ultralib/include', 'tools/ultralib/include/PR', 'tools/ultralib/include/compiler/gcc', 'tools/ultralib/src/audio', 'tools/ultralib/src/gu', 'tools/battletanx_ga/src/libmus', 'tools/battletanx_ga/src/n_audio', 'tools/battletanx_ga/include']),
    'matching_ido.tsv': ('ido5.3', []),
    'matching_ido_normalized.tsv': ('ido5.3', []),
    'matching_sn.tsv': ('sn', []),
    'matching_sn_normalized.tsv': ('sn', []),
    'matching_as.tsv': ('as', []),
}


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def file_hash(path: Path) -> str:
    return digest(path.read_bytes())


def load_json(path: Path):
    return json.loads(path.read_text())


def save_json(path: Path, value) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


@dataclass
class Unit:
    key: str
    manifest: str
    row_hash: str
    source: str
    rom_start: int
    text_size: int
    expected_hash: str
    spec: BuildSpec
    includes: list[str]
    normalization: str | None


def units(project: Path) -> list[Unit]:
    result = []
    manifest_root = project / MANIFEST_DIR
    actual = {p.name for p in manifest_root.glob('matching*.tsv')}
    if actual != set(PROFILES):
        raise ValueError(f'manifest profile set changed: {sorted(actual ^ set(PROFILES))}')
    for name, (pipeline, includes) in PROFILES.items():
        for line in (manifest_root / name).read_text().splitlines():
            if not line or line.startswith('#'):
                continue
            fields = line.split('\t')
            if len(fields) != 5:
                raise ValueError(f'{name}: expected five manifest fields')
            start, size, source, raw_flags, expected = fields
            flags, normalization = [], None
            row_pipeline = pipeline
            for flag in shlex.split(raw_flags):
                if flag == '--ido-version=7.1':
                    row_pipeline = 'ido7.1'
                elif flag.startswith('--normalizer-unit='):
                    normalization = flag.split('=', 1)[1]
                elif flag == '--normalize-debug-regions':
                    normalization = 'debug-regions'
                elif flag == '--normalize-ad30-stack-slots':
                    normalization = 'ad30-stack-slots'
                elif flag == '--normalize-16120-prologue':
                    normalization = '16120-prologue'
                elif flag == '--normalize-d880-registers':
                    normalization = 'd880-registers'
                else:
                    flags.append(flag)
            if name == 'matching_ido_normalized.tsv':
                normalization = normalization or 'stream-decoder'
            if name == 'matching_sn_normalized.tsv':
                normalization = normalization or 'shadow-operands'
            row_hash = digest(line.encode())
            key = f'{name}:{row_hash[:16]}'
            if any(u.key == key for u in result):
                raise ValueError(f'duplicate row: {key}')
            result.append(Unit(key, MANIFEST_DIR + '/' + name, row_hash, source,
                               int(start, 0), int(size, 0), expected,
                               split_flags(flags, row_pipeline), includes, normalization))
    return result


def module_from(path: Path):
    spec = importlib.util.spec_from_file_location(path.stem, path)
    module = importlib.util.module_from_spec(spec)
    assert spec.loader
    spec.loader.exec_module(module)
    return module


def compile_unit(unit: Unit, project: Path, cfg, work: Path) -> tuple[Elf, str]:
    obj = build(project / unit.source, unit.spec, cfg, work,
                includes=[project / p for p in unit.includes])
    raw_hash = file_hash(obj)
    elf = Elf.load(obj)
    if unit.normalization:
        if unit.normalization in ('stream-decoder', 'stream-channel-update'):
            mod = module_from(project / 'tools/verify_ido_normalized.py')
            function = {'stream-decoder': mod.normalize_stream_decoder,
                        'stream-channel-update': mod.normalize_stream_channel_update}[unit.normalization]
        else:
            mod = module_from(project / 'tools/verify_sn_normalized.py')
            function = {'shadow-operands': mod.normalize_shadow_operands,
                        'debug-regions': mod.normalize_debug_regions,
                        'ad30-stack-slots': mod.normalize_ad30_stack_slots,
                        '16120-prologue': mod.normalize_16120_prologue,
                        'd880-registers': mod.normalize_d880_registers}[unit.normalization]
        function(elf)
    return elf, raw_hash


def configuration(project: Path):
    cfg = load_config(project)
    cfg.normalizer = 'python3 tools/normalize_kmc_wrappers.py {extra} {input} {output}'
    return cfg


def inputs_snapshot(project: Path, items: list[Unit]) -> dict[str, str]:
    """Hash source, all declared include trees, symbol maps and tool code."""
    paths = {project / unit.source for unit in items}
    paths.update(project / unit.manifest for unit in items)
    paths.update(project / p for p in ('config/segments.toml', 'config/survey/symbol_addrs.txt',
                  'tools/build_source_image.py', 'tools/normalize_kmc_wrappers.py',
                  'tools/verify_ido_normalized.py', 'tools/verify_sn_normalized.py'))
    for root in {root for unit in items for root in unit.includes}:
        paths.update(p for p in (project / root).rglob('*') if p.is_file()
                     and '__pycache__' not in p.parts)
    result = {str(p.relative_to(project)): file_hash(p) for p in sorted(paths)}
    # n64dk is outside this checkout; track its implementation rather than
    # treating a moved checkout path as a changed input.
    import n64dk.elf
    toolkit = Path(n64dk.elf.__file__).parent
    for p in sorted(toolkit.rglob('*.py')):
        result['@n64dk/' + str(p.relative_to(toolkit))] = file_hash(p)
    return result


def check_fresh(expected: dict[str, str], actual: dict[str, str]) -> None:
    changed = sorted(key for key in expected.keys() | actual.keys()
                     if expected.get(key) != actual.get(key))
    if changed:
        raise ValueError('stale link plan; rediscover after input changes: ' + ', '.join(changed[:8]))


class FrozenSymbols(dict):
    """Only explicitly frozen names resolve; no address-name fallback."""
    def resolve(self, name):
        return self.get(name)


class CoverageImage:
    def __init__(self, start: int, end: int):
        if end <= start:
            raise ValueError('invalid image extent')
        self.start, self.end = start, end
        self.data = bytearray(end - start)
        self.owned = bytearray(end - start)
        self.overlap_bytes = 0

    def add(self, start: int, data: bytes, owner: str) -> None:
        if start < self.start or start + len(data) > self.end:
            raise ValueError(f'{owner}: piece escapes resident segment')
        offset = start - self.start
        for index, value in enumerate(data):
            at = offset + index
            if self.owned[at]:
                if self.data[at] != value:
                    raise ValueError(f'{owner}: conflicting overlap at ROM {self.start + at:#x}')
                self.overlap_bytes += 1
            else:
                self.data[at] = value
                self.owned[at] = 1

    def gaps(self) -> list[dict[str, int]]:
        result, index = [], 0
        while index < len(self.owned):
            if self.owned[index]:
                index += 1
                continue
            start = index
            while index < len(self.owned) and not self.owned[index]:
                index += 1
            result.append({'rom_start': self.start + start,
                           'rom_end': self.start + index, 'size': index - start})
        return result


def freeze_symbols(elf: Elf, known: symmod.SymbolMap) -> dict[str, int]:
    needed = {}
    for symbol in elf.symbols:
        if symbol.name and symbol.section in (0, 0xFFF2) and symbol.name in known:
            needed[symbol.name] = known[symbol.name]
    return needed


def owned_references(elf: Elf, target: str, owned: dict[str, int]):
    """Relocations into target from bytes that this link plan actually owns."""
    return [(source, rel.offset) for source, size in owned.items()
            if elf.section(source) is not None
            for rel in compare.relocations(elf, source)
            if rel.section == target and rel.offset < size]


def discover_one(unit: Unit, project: Path, cfg, work: Path, rom: bytes, known):
    elf, obj_hash = compile_unit(unit, project, cfg, work)
    symbols = known.copy()
    symbols.update(symmod.from_source((project / unit.source).read_text(), symbols))
    symbols.update(unit.spec.symbols)
    result = compare.compare_object(
        elf, rom, lambda address: address - DELTA,
        unit.rom_start + DELTA, unit.text_size, symbols,
        bases=unit.spec.section_bases, infer=True, infer_externals=True,
        rodata_search=unit.normalization is None,
        rom_window=(START, len(rom)), to_vram=lambda offset: offset + DELTA,
        with_diff=False)
    if not result.exact:
        raise ValueError(f'{unit.key}: does not match: {result.error or result.text.first_diff}')
    symbols.update(result.inferred_symbols)
    bases = dict(result.bases)
    for name in ROM_SECTIONS:
        sec = elf.section(name)
        if sec and sec.size:
            bases.update(compare.complete_bases(elf, name, bases, symbols))
    sections = []
    discarded = []
    verified = {section.name: section for section in result.sections}
    for name in ROM_SECTIONS:
        sec = elf.section(name)
        if sec is None or not sec.size:
            continue
        if name not in bases:
            # A nonempty unreferenced initialized section cannot silently vanish.
            candidates = {symbols[s.name] - s.value for s in elf.symbols
                          if s.section == sec.index and s.name and s.name in symbols}
            if len(candidates) == 1:
                bases[name] = candidates.pop()
            else:
                candidates = compare.section_candidates(
                    elf, name, rom, START, END, lambda offset: offset + DELTA,
                    unit.rom_start + DELTA, limit=(END - START) // 4)
                valid = []
                for candidate in candidates:
                    trial = dict(bases, **{name: candidate})
                    try:
                        body = compare.relocate(elf, name, trial, symbols)
                    except (KeyError, ValueError):
                        continue
                    offset = candidate - DELTA
                    if body == rom[offset:offset + len(body)]:
                        valid.append((candidate, len(body)))
                if len(valid) != 1:
                    owned_names = {'.text'} | set(verified) | set(unit.spec.section_bases)
                    owned = {}
                    for source_name in owned_names:
                        source_section = elf.section(source_name)
                        if source_section is not None:
                            owned[source_name] = unit.text_size if source_name == '.text' else (
                                verified[source_name].size if source_name in verified else source_section.size)
                    references = owned_references(elf, name, owned)
                    if references:
                        raise ValueError(f'{unit.key}: missing placement for referenced {name}: {references}')
                    discarded.append({'name': name, 'emitted_size': len(sec.data),
                                      'unrelocated_sha256': digest(sec.data),
                                      'reason': 'unreferenced emitted section; no unique frozen placement',
                                      'discovery_exact_candidates': len(valid)})
                    continue
                bases[name] = valid[0][0]
        raw = compare.relocate(elf, name, bases, symbols)
        if name == '.text':
            size = unit.text_size
        else:
            compared = verified.get(name)
            if compared is None:
                # A known exact section placement may not have been visited by
                # compare_object (e.g. .lit4). Validate its full output here.
                size = len(raw)
            else:
                size = compared.size
        if size > len(raw):
            raise ValueError(f'{unit.key}: expected extent exceeds emitted {name}')
        trimmed = raw[size:]
        if any(trimmed):
            raise ValueError(f'{unit.key}: nonzero unowned tail in {name}')
        offset = bases[name] - DELTA
        if offset < START or offset + size > END:
            raise ValueError(f'{unit.key}: {name} placement escapes resident segment')
        if raw[:size] != rom[offset:offset + size]:
            raise ValueError(f'{unit.key}: placed {name} differs from original')
        sections.append({'name': name, 'vram': bases[name], 'rom_start': offset,
                         'owned_size': size, 'emitted_size': len(raw),
                         'unowned_zero_tail': len(trimmed), 'sha256': digest(raw[:size])})
    text = next(s for s in sections if s['name'] == '.text')
    if text['sha256'] != unit.expected_hash:
        raise ValueError(f'{unit.key}: text manifest digest differs')
    return {'id': unit.key, 'manifest': unit.manifest, 'row_sha256': unit.row_hash,
            'source': unit.source, 'source_sha256': file_hash(project / unit.source),
            'pipeline': unit.spec.pipeline, 'flags': unit.spec.flags,
            'normalization': unit.normalization, 'includes': unit.includes,
            'object_sha256_at_discovery': obj_hash,
            'section_bases': bases, 'symbols': freeze_symbols(elf, symbols),
            'sections': sections, 'discarded_sections': discarded}


def discover(project: Path, plan_path: Path, rom_path: Path, jobs: int) -> None:
    from verify import EXPECTED_SHA1, EXPECTED_SIZE
    rom = rom_path.read_bytes()
    if len(rom) != EXPECTED_SIZE or hashlib.sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported preservation ROM')
    items = units(project)
    snapshot = inputs_snapshot(project, items)
    cfg = configuration(project)
    known = symmod.load([project / 'config/survey/symbol_addrs.txt'])
    with tempfile.TemporaryDirectory(prefix='sydney-link-discovery-') as tmp:
        def one(pair):
            index, unit = pair
            directory = Path(tmp) / str(index)
            directory.mkdir()
            try:
                return discover_one(unit, project, cfg, directory, rom, known)
            except Exception as error:
                return {'error': str(error), 'unit': unit.key}
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            records = list(pool.map(one, enumerate(items)))
    failures = [record for record in records if 'error' in record]
    if failures:
        raise ValueError('discovery failed for ' + str(len(failures)) + ' units:\n' +
                         '\n'.join(record['unit'] + ': ' + record['error'] for record in failures))
    check_fresh(snapshot, inputs_snapshot(project, items))
    save_json(plan_path, {'version': VERSION, 'rom_sha1': EXPECTED_SHA1,
                         'segment': SEGMENT, 'rom_start': START, 'rom_end': END,
                         'resident_rom_start': START if SEGMENT == 'resident' else None,
                         'resident_rom_end': END if SEGMENT == 'resident' else None,
                         'inputs': snapshot, 'units': records})
    print(f'froze {len(records)} source units in {plan_path}')


def build_one(unit: Unit, record, project: Path, cfg, work: Path):
    if record['row_sha256'] != unit.row_hash or record['source_sha256'] != file_hash(project / unit.source):
        raise ValueError(f'{unit.key}: stale source or manifest row')
    elf, obj_hash = compile_unit(unit, project, cfg, work)
    bases = record['section_bases']
    # Plain dict means even address-encoded names must be explicitly frozen.
    symbols = FrozenSymbols(record['symbols'])
    pieces = []
    expected_names = {section['name'] for section in record['sections']}
    discarded = record.get('discarded_sections', [])
    expected_names.update(section['name'] for section in discarded)
    actual_names = {name for name in ROM_SECTIONS if elf.section(name) and elf.section(name).size}
    if actual_names != expected_names:
        raise ValueError(f'{unit.key}: emitted section set changed')
    owned = {section['name']: section['owned_size'] for section in record['sections']}
    for section in discarded:
        if owned_references(elf, section['name'], owned):
            raise ValueError(f'{unit.key}: discarded section is referenced by owned output')
        emitted = elf.section(section['name'])
        if len(emitted.data) != section['emitted_size'] or digest(emitted.data) != section['unrelocated_sha256']:
            raise ValueError(f'{unit.key}: discarded section changed: {section["name"]}')
    for section in record['sections']:
        name = section['name']
        if section['rom_start'] != section['vram'] - DELTA or section['owned_size'] < 0:
            raise ValueError(f'{unit.key}: inconsistent {name} ROM/VRAM ownership')
        if name == '.text' and (section['rom_start'] != unit.rom_start or
                                section['owned_size'] != unit.text_size):
            raise ValueError(f'{unit.key}: text ownership differs from manifest')
        if name not in bases or bases[name] != section['vram']:
            raise ValueError(f'{unit.key}: missing or changed {name} placement')
        raw = compare.relocate(elf, name, bases, symbols)
        size = section['owned_size']
        if (len(raw) != section['emitted_size'] or any(raw[size:]) or
                len(raw) - size != section['unowned_zero_tail']):
            raise ValueError(f'{unit.key}: emitted extent or unowned padding changed for {name}')
        data = raw[:size]
        if len(data) != size or digest(data) != section['sha256']:
            raise ValueError(f'{unit.key}: source output changed for {name}; rediscover')
        pieces.append((section, data))
    return obj_hash, pieces


def build_image(project: Path, plan_path: Path, output: Path, jobs: int,
                verify_rom: Path | None = None) -> None:
    plan = load_json(plan_path)
    extent = (plan.get('rom_start', plan.get('resident_rom_start')),
              plan.get('rom_end', plan.get('resident_rom_end')))
    if (plan.get('version') != VERSION or extent != (START, END) or
            plan.get('segment', 'resident') != SEGMENT):
        raise ValueError('unsupported link plan schema or resident map')
    items = units(project)
    snapshot = inputs_snapshot(project, items)
    check_fresh(plan['inputs'], snapshot)
    records = {record['id']: record for record in plan['units']}
    if len(records) != len(plan['units']) or set(records) != {unit.key for unit in items}:
        raise ValueError('link plan does not cover the current manifest rows exactly')
    cfg = configuration(project)
    image = CoverageImage(START, END)
    output.mkdir(parents=True, exist_ok=True)
    shard_dir = output / 'pieces'
    shard_dir.mkdir(exist_ok=True)
    provenance = []
    with tempfile.TemporaryDirectory(prefix='sydney-source-build-') as tmp:
        def one(pair):
            index, unit = pair
            directory = Path(tmp) / str(index)
            directory.mkdir()
            try:
                return build_one(unit, records[unit.key], project, cfg, directory)
            except Exception as error:
                return {'error': str(error), 'unit': unit.key}
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            results = list(pool.map(one, enumerate(items)))
        failures = [result for result in results if isinstance(result, dict)]
        if failures:
            raise ValueError('source build failed for ' + str(len(failures)) + ' units:\n' +
                             '\n'.join(result['unit'] + ': ' + result['error'] for result in failures))
        for index, (unit, (obj_hash, pieces)) in enumerate(zip(items, results)):
            for section_index, (section, data) in enumerate(pieces):
                image.add(section['rom_start'], data, unit.key + ':' + section['name'])
                name = f'{index:04d}_{section_index}_{section["name"].lstrip(".")}.bin'
                (shard_dir / name).write_bytes(data)
                provenance.append(dict(section, unit_id=unit.key, source=unit.source,
                                       source_sha256=records[unit.key]['source_sha256'],
                                       object_sha256=obj_hash, file='pieces/' + name))
    check_fresh(snapshot, inputs_snapshot(project, items))
    # ROM access occurs only now, after source compilation and relocation.
    if verify_rom is not None:
        rom = verify_rom.read_bytes()
        for piece in provenance:
            start, size = piece['rom_start'], piece['owned_size']
            data = (output / piece['file']).read_bytes()
            if rom[start:start + size] != data:
                raise ValueError(f'{piece["unit_id"]}: emitted source piece differs from verification ROM')
    (output / f'{SEGMENT}.partial.bin').write_bytes(image.data)
    (output / f'{SEGMENT}.ownership.bin').write_bytes(image.owned)
    ledger = {'version': VERSION, 'complete_rom': False,
              'artifact_kind': f'source-relocated {SEGMENT} partial image',
              'segment': SEGMENT,
              'rom_start': START, 'rom_end': END,
              'covered_bytes': sum(image.owned), 'uncovered_bytes': len(image.owned) - sum(image.owned),
              'overlapping_equal_bytes': image.overlap_bytes, 'gaps': image.gaps(),
              'excluded_regions': ['header', 'IPL3', 'overlay banks', 'runtime catalog',
                                   'file directory and asset catalogs', 'asset payloads', 'cartridge fill'],
              'link_plan_sha256': file_hash(plan_path), 'pieces': provenance,
              'discarded_sections': [dict(section, unit_id=unit['id'])
                                     for unit in plan['units']
                                     for section in unit.get('discarded_sections', [])]}
    save_json(output / 'source_image.json', ledger)
    print(f'built {len(provenance)} source pieces: {ledger["covered_bytes"]} {SEGMENT} bytes; '
          f'{ledger["uncovered_bytes"]} bytes remain unowned (not a complete ROM)')


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=('discover', 'build'))
    parser.add_argument('--project', type=Path, default=ROOT)
    parser.add_argument('--segment', choices=('resident', 'runtime'), default='resident')
    parser.add_argument('--plan', type=Path)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64', help='discovery input only')
    parser.add_argument('--verify-rom', type=Path, help='optional comparison after source-only build')
    parser.add_argument('--output', type=Path)
    parser.add_argument('--jobs', type=int, default=4)
    args = parser.parse_args()
    global DELTA, START, END, SEGMENT, MANIFEST_DIR, PROFILES
    if args.segment == 'runtime':
        DELTA = 0x7FF5C710
        START, END = 0x127640, 0x1A3AB0
        SEGMENT = 'runtime'
        MANIFEST_DIR = 'config/runtime'
        PROFILES = {'matching_sn.tsv': ('sn', []),
                    'matching_kmc.tsv': ('kmc+as', [])}
    args.plan = args.plan or ROOT / ('config/runtime_link_units.json' if SEGMENT == 'runtime'
                                    else 'config/link_units.json')
    args.output = args.output or ROOT / ('build/runtime_image' if SEGMENT == 'runtime'
                                        else 'build/source_image')
    if args.jobs < 1:
        parser.error('--jobs must be positive')
    if args.command == 'discover':
        discover(args.project.resolve(), args.plan.resolve(), args.rom.resolve(), args.jobs)
    else:
        build_image(args.project.resolve(), args.plan.resolve(), args.output.resolve(), args.jobs,
                    args.verify_rom.resolve() if args.verify_rom else None)


if __name__ == '__main__':
    main()
