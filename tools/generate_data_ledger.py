#!/usr/bin/env python3
"""Rebuild matching units and record verified initialized-data extents.

Run with the PYTHONPATH/N64DK_TOOLCHAIN environment used by make verify-matching.
The output contains hashes and metadata, never original ROM or object bytes.
A report consumer can check input freshness without possessing the ROM.
"""
from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_TO_VRAM = 0x7FFFF400
ORDINARY = {
    'matching_kmc.tsv': 'kmc+asn64',
    'matching_kmc_hook.tsv': 'kmc+hook',
    'matching_kmc_builtin.tsv': 'kmc+builtin',
    'matching_kmc_as.tsv': 'kmc+as',
    'matching_ido.tsv': 'ido5.3',
    'matching_sn.tsv': 'sn',
    'matching_as.tsv': 'as',
}
NORMALIZED = {'matching_ido_normalized.tsv': 'ido',
              'matching_sn_normalized.tsv': 'sn'}
INCLUDE_DIRS = (
    'tools/ultralib/include', 'tools/ultralib/include/PR',
    'tools/ultralib/include/compiler/gcc', 'tools/ultralib/src/audio',
    'tools/ultralib/src/gu', 'tools/battletanx_ga/src/libmus',
    'tools/battletanx_ga/src/n_audio', 'tools/battletanx_ga/include',
)


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def relative(path: Path) -> str:
    # Keep symbolic links inside the checkout attributable to their repository path.
    return path.absolute().relative_to(ROOT).as_posix()


def merge_ranges(ranges: list[tuple[int, int]]) -> list[tuple[int, int]]:
    merged: list[tuple[int, int]] = []
    for start, end in sorted(ranges):
        if end <= start:
            raise ValueError(f'invalid extent {start:#x}..{end:#x}')
        if merged and start <= merged[-1][1]:
            merged[-1] = merged[-1][0], max(end, merged[-1][1])
        else:
            merged.append((start, end))
    return merged


def classification() -> tuple[Path, list[tuple[int, int]]]:
    path = ROOT / 'config/survey/ledger.tsv'
    intervals = []
    for line in path.read_text().splitlines()[1:]:
        fields = line.split('\t')
        if fields[3] == 'data':
            intervals.append((int(fields[0], 0), int(fields[1], 0)))
    return path, merge_ranges(intervals)


def manifest_rows() -> dict[str, list[dict]]:
    present = {path.name for path in (ROOT / 'config').glob('matching*.tsv')}
    expected = set(ORDINARY) | set(NORMALIZED)
    if present != expected:
        raise ValueError(f'unhandled/missing matching manifests: {sorted(present ^ expected)}')
    result = {}
    for name in sorted(expected):
        rows = []
        path = ROOT / 'config' / name
        for number, line in enumerate(path.read_text().splitlines(), 1):
            if not line or line.startswith('#'):
                continue
            fields = line.split('\t')
            if len(fields) != 5:
                raise ValueError(f'{path}:{number}: expected five fields')
            start, size = int(fields[0], 0), int(fields[1], 0)
            if start < 0 or size <= 0 or not (ROOT / fields[2]).is_file():
                raise ValueError(f'{path}:{number}: invalid source or text extent')
            rows.append({'source': fields[2], 'text_rom_start': start,
                         'manifest': relative(path), 'manifest_line': number,
                         'manifest_row_sha256': hashlib.sha256(line.encode()).hexdigest(),
                         'flags': fields[3], 'text_size': size})
        result[name] = rows
    return result


def input_paths(rows: dict[str, list[dict]], symbol_files: list[Path]) -> list[Path]:
    paths = {ROOT / 'config/survey/ledger.tsv', Path(__file__).absolute(),
             ROOT / 'tools/normalize_kmc_wrappers.py',
             ROOT / 'tools/verify_ido_normalized.py',
             ROOT / 'tools/verify_sn_normalized.py', ROOT / 'tools/verify.py',
             ROOT / 'tools/build_source_image.py', ROOT / 'config/link_units.json'}
    # The link plan's repository inputs must also be checkable in ROM-free CI.
    # External toolkit hashes remain metadata; they are never fake repo paths.
    plan = json.loads((ROOT / 'config/link_units.json').read_text())
    for name in plan['inputs']:
        if name.startswith('@n64dk/'):
            continue
        relative_path = Path(name)
        if relative_path.is_absolute() or '..' in relative_path.parts:
            raise ValueError(f'invalid source-image input path: {name}')
        paths.add(ROOT / relative_path)
    paths.update(ROOT / 'config' / name for name in rows)
    paths.update(Path(path).absolute() for path in symbol_files)
    sources = {ROOT / row['source'] for group in rows.values() for row in group}
    paths.update(sources)
    roots = {ROOT / name for name in INCLUDE_DIRS} | {source.parent for source in sources}
    for directory in roots:
        if not directory.is_dir():
            raise ValueError(f'missing dependency directory: {directory}')
        for path in directory.rglob('*'):
            if path.is_file() and path.suffix.lower() in ('.h', '.inc'):
                paths.add(path)
    # A future local toolchain override must also invalidate the recorded build.
    if (ROOT / 'n64dk.toml').is_file():
        paths.add(ROOT / 'n64dk.toml')
    return sorted(paths, key=relative)


def snapshot(paths: list[Path]) -> list[dict]:
    return [{'path': relative(path), 'sha256': sha256(path)} for path in paths]


def collect_normalized(kind: str, manifest: Path, rom: Path) -> list:
    """Capture comparison results while using the existing reviewed verifier unchanged."""
    module_path = ROOT / f'tools/verify_{kind}_normalized.py'
    spec = importlib.util.spec_from_file_location(f'data_ledger_{kind}', module_path)
    if spec is None or spec.loader is None:
        raise ValueError(f'cannot load {module_path}')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    results = []
    original = module.compare_object

    def capture(*args, **kwargs):
        result = original(*args, **kwargs)
        results.append(result)
        return result

    module.compare_object = capture
    module.verify(manifest, ROOT, rom, ROOT / 'config/survey/symbol_addrs.txt')
    return results


def source_image_sections(rom: Path, jobs: int, rows: dict[str, list[dict]],
                          existing: list[dict]) -> tuple[list[dict], dict]:
    """Build from frozen placements, then compare source output against ROM.

    Only newly covered initialized sections are added; the source-image builder
    never discovers placements or imports ROM bytes in this route.
    """
    import build_source_image as source_image
    plan_path = ROOT / 'config/link_units.json'
    plan = source_image.load_json(plan_path)
    row_map = {(row['manifest'], row['manifest_row_sha256']): row
               for group in rows.values() for row in group}
    plan_units = {unit['id']: unit for unit in plan['units']}
    old_ranges = merge_ranges([(section['rom_start'], section['rom_end'])
                               for section in existing])
    added = []
    with tempfile.TemporaryDirectory(prefix='sydney-data-source-image-') as tmp:
        output = Path(tmp) / 'output'
        # build_image checks the complete frozen input snapshot before and
        # after rebuilding. ROM access occurs only in its post-build verifier.
        source_image.build_image(ROOT, plan_path, output, jobs, verify_rom=rom)
        provider = source_image.load_json(output / 'source_image.json')
        for piece in provider['pieces']:
            if piece['name'] == '.text' or not piece['owned_size']:
                continue
            start, end = piece['rom_start'], piece['rom_start'] + piece['owned_size']
            covered = sum(max(0, min(end, right) - max(start, left))
                          for left, right in old_ranges)
            if covered == end - start:
                continue
            unit = plan_units[piece['unit_id']]
            row = row_map[(unit['manifest'], unit['row_sha256'])]
            data = (output / piece['file']).read_bytes()
            if hashlib.sha256(data).hexdigest() != piece['sha256']:
                raise ValueError('source-image section hash changed during collection')
            added.append({**row, 'pipeline': unit['pipeline'], 'section': piece['name'],
                          'rom_start': start, 'rom_end': end, 'size': len(data),
                          'vram_start': piece['vram'], 'sha256': piece['sha256'],
                          'provider': 'frozen-source-image',
                          'source_image_unit_id': unit['id'],
                          'source_image_plan_sha256': sha256(plan_path),
                          'compiler_flags': unit['flags'],
                          'normalization': unit['normalization'],
                          'emitted_size': piece['emitted_size'],
                          'unowned_zero_tail': piece['unowned_zero_tail']})
    metadata = {
        'plan_path': relative(plan_path), 'plan_sha256': sha256(plan_path),
        'build_tool_path': 'tools/build_source_image.py',
        'build_tool_sha256': sha256(ROOT / 'tools/build_source_image.py'),
        'verified_source_pieces': len(provider['pieces']),
        'owned_resident_bytes': provider['covered_bytes'],
        'added_initialized_sections': len(added),
        'placement_inference_during_build': False,
        'post_build_rom_comparison': True,
        'toolkit_inputs': [{'path': name, 'sha256': value}
                           for name, value in sorted(plan['inputs'].items())
                           if name.startswith('@n64dk/')],
    }
    return added, metadata


def generate(rom_path: Path, output: Path, jobs: int) -> dict:
    from n64dk.match import manifest as manifest_module
    from n64dk.match import symbols as symbol_module
    from n64dk.match.engine import Target, batch
    from n64dk.match.toolchain import load_config
    from n64dk.rom import Rom
    from verify import EXPECTED_SHA1, EXPECTED_SIZE

    rom_path = rom_path.absolute()
    rom_data = rom_path.read_bytes()
    identity = hashlib.sha1(rom_data).hexdigest()
    if len(rom_data) != EXPECTED_SIZE or identity != EXPECTED_SHA1:
        raise ValueError('unsupported original ROM')
    rows = manifest_rows()
    config = load_config(ROOT)
    config.normalizer = 'python3 tools/normalize_kmc_wrappers.py {extra} {input} {output}'
    config.include = list(dict.fromkeys([ROOT / path for path in INCLUDE_DIRS] + config.include))
    symbol_files = config.symbols or symbol_module.discover(ROOT)
    symbols = symbol_module.load(symbol_files)
    inputs = snapshot(input_paths(rows, symbol_files))
    target = Target.from_rom(Rom.load(rom_path), config.vram_delta)
    if target.delta != ROM_TO_VRAM:
        raise ValueError('unexpected resident image address mapping')
    units = []
    provenance = []
    for name, pipeline in ORDINARY.items():
        parsed = manifest_module.parse(ROOT / 'config' / name, ROOT,
                                       target.rom_to_vram, pipeline)
        if len(parsed) != len(rows[name]):
            raise ValueError(f'parser dropped rows from {name}')
        units.extend(parsed)
        provenance.extend(rows[name])
    outcomes = batch(units, config, target, symbols, jobs, True)
    verified = []
    for row, outcome in zip(provenance, outcomes):
        if not outcome.exact or outcome.result is None:
            raise ValueError(f"{row['source']}: matching verification failed: {outcome.error}")
        if outcome.vram - ROM_TO_VRAM != row['text_rom_start']:
            raise ValueError('matching result/provenance order changed')
        verified.append((row, outcome.spec.pipeline, outcome.result))
    for name, kind in NORMALIZED.items():
        results = collect_normalized(kind, ROOT / 'config' / name, rom_path)
        if len(results) != len(rows[name]):
            raise ValueError(f'normalized verifier dropped rows from {name}')
        for row, result in zip(rows[name], results):
            if not result.exact or result.text.vram - ROM_TO_VRAM != row['text_rom_start']:
                raise ValueError('normalized result/provenance mismatch')
            verified.append((row, f'{kind}-normalized', result))
    sections = []
    for row, pipeline, result in verified:
        for section in result.sections:
            if not section.match:
                raise ValueError(f"{row['source']}: unmatched initialized section")
            if section.name not in ('.rodata', '.rdata', '.data'):
                raise ValueError(f'unhandled initialized section {section.name}')
            if not section.size:
                continue
            start = section.vram - ROM_TO_VRAM
            end = start + section.size
            if not (0 <= start < end <= len(rom_data)):
                raise ValueError('compared section escapes original ROM')
            sections.append({**row, 'pipeline': pipeline, 'section': section.name,
                             'rom_start': start, 'rom_end': end, 'size': section.size,
                             'vram_start': section.vram,
                             'sha256': hashlib.sha256(rom_data[start:end]).hexdigest()})
    additional, source_provider = source_image_sections(rom_path, jobs, rows, sections)
    sections.extend(additional)
    classification_path, data_ranges = classification()
    compared_ranges = merge_ranges([(row['rom_start'], row['rom_end']) for row in sections])
    matched_ranges = merge_ranges([
        (max(start, left), min(end, right))
        for start, end in compared_ranges for left, right in data_ranges
        if max(start, left) < min(end, right)
    ])
    if compared_ranges != matched_ranges:
        raise ValueError('compared initialized section is outside classified data; review classification')
    # Reject a ledger produced while another worker changed any compiler input.
    if rows != manifest_rows() or inputs != snapshot(input_paths(rows, symbol_files)):
        raise ValueError('compiler inputs changed during verification; regenerate after edits settle')
    ledger = {
        'version': 1, 'rom_sha1': identity,
        'total_data': sum(end - start for start, end in data_ranges),
        'matched_data': sum(end - start for start, end in matched_ranges),
        'ranges': [{'rom_start': start, 'rom_end': end, 'size': end - start,
                    'sha256': hashlib.sha256(rom_data[start:end]).hexdigest()}
                   for start, end in matched_ranges],
        'inputs': inputs,
        'sections': sorted(sections, key=lambda row: (row['rom_start'], row['source'])),
        'verification': {'units': len(verified), 'exact_units': len(verified)},
        'source_image_provider': source_provider,
        'classification': {'path': relative(classification_path),
                           'sha256': sha256(classification_path)},
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    temporary = output.with_suffix(output.suffix + '.tmp')
    temporary.write_text(json.dumps(ledger, indent=2) + '\n')
    temporary.replace(output)
    return ledger


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--output', type=Path, default=ROOT / 'config/matching_data.json')
    parser.add_argument('--jobs', type=int, default=8)
    args = parser.parse_args()
    if args.jobs < 1:
        parser.error('--jobs must be positive')
    ledger = generate(args.rom, args.output, args.jobs)
    print(f"verified {ledger['verification']['units']} matching units; "
          f"{ledger['matched_data']} unique initialized-data bytes in "
          f"{len(ledger['ranges'])} ranges; wrote {args.output}")


if __name__ == '__main__':
    main()
