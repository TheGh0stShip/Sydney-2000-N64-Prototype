#!/usr/bin/env python3
"""Propose (never apply) manifest extensions for source-emitted zero padding.

Only frozen-plan source output can supply additional bytes. Each candidate is
capped to its existing catalogue function, independently compiled and relocated
without ROM inference, and then compared against the preservation image.
"""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
from pathlib import Path
import tempfile
import tomllib

import build_source_image as source_image

ROOT = Path(__file__).resolve().parents[1]


def merge(ranges):
    result = []
    for start, end in sorted(ranges):
        if start >= end:
            continue
        if result and start <= result[-1][1]:
            result[-1] = result[-1][0], max(end, result[-1][1])
        else:
            result.append((start, end))
    return result


def uncovered(start, end, coverage):
    result, cursor = [], start
    for left, right in coverage:
        if right <= cursor or left >= end:
            continue
        if cursor < left:
            result.append((cursor, left))
        cursor = max(cursor, min(right, end))
    if cursor < end:
        result.append((cursor, end))
    return result


def row_details(project, unit):
    rows = [(number, line) for number, line in enumerate(
        (project / unit.manifest).read_text().splitlines(), 1)
        if source_image.digest(line.encode()) == unit.row_hash]
    if len(rows) != 1:
        raise ValueError(f'{unit.key}: cannot uniquely identify original row')
    return rows[0]


def audit(project, plan_path, rom_path, output, jobs):
    from verify import EXPECTED_SHA1, EXPECTED_SIZE
    rom = rom_path.read_bytes()
    if len(rom) != EXPECTED_SIZE or hashlib.sha1(rom).hexdigest() != EXPECTED_SHA1:
        raise ValueError('unsupported preservation ROM')
    plan = source_image.load_json(plan_path)
    if plan.get('version') != source_image.VERSION:
        raise ValueError('unsupported frozen link plan')
    units = source_image.units(project)
    records = {record['id']: record for record in plan['units']}
    if set(records) != {unit.key for unit in units}:
        raise ValueError('frozen plan does not cover current manifest rows')
    snapshot = source_image.inputs_snapshot(project, units)
    source_image.check_fresh(plan['inputs'], snapshot)
    catalogue_path = project / 'config/survey/functions.toml'
    catalogue_hash = source_image.file_hash(catalogue_path)
    section = tomllib.loads(catalogue_path.read_text())['section'][0]
    functions = sorted((function['vram'] - source_image.DELTA,
                        function['vram'] - source_image.DELTA + function['size'],
                        function['name']) for function in section['functions'])
    initial_coverage = merge([(unit.rom_start, unit.rom_start + unit.text_size)
                              for unit in units])
    candidates, skipped = [], []
    tail_units, tail_bytes = 0, 0
    for unit in units:
        record = records[unit.key]
        text = next(s for s in record['sections'] if s['name'] == '.text')
        start = text['rom_start'] + text['owned_size']
        emitted_end = text['rom_start'] + text['emitted_size']
        if start >= emitted_end:
            continue
        tail_units += 1
        tail_bytes += emitted_end - start
        entry = {'unit_id': unit.key, 'source': unit.source,
                 'tail_rom_start': start, 'tail_rom_end': emitted_end}
        if (text['owned_size'] != unit.text_size or text['rom_start'] != unit.rom_start or
                text['unowned_zero_tail'] != emitted_end - start):
            raise ValueError(f'{unit.key}: frozen tail extent is inconsistent')
        owners = [(index, function) for index, function in enumerate(functions)
                  if function[0] <= start - 1 < function[1]]
        reason = None
        if len(owners) != 1:
            reason = 'last owned byte has no unique catalogue function'
        else:
            index, function = owners[0]
            if function[1] <= start:
                reason = 'owned extent already reaches its catalogue function end'
            elif index + 1 < len(functions) and emitted_end > functions[index + 1][0]:
                reason = 'raw emitted tail overlaps the next catalogue function'
            elif unit.normalization:
                reason = 'binary-normalized unit requires separate strict-size padding review'
            else:
                end = min(emitted_end, function[1])
                if not uncovered(start, end, initial_coverage):
                    reason = 'candidate range is already covered by matching source'
        if reason:
            skipped.append(dict(entry, reason=reason))
            continue
        candidates.append((unit, record, text, function, start, end))
    cfg = source_image.configuration(project)
    with tempfile.TemporaryDirectory(prefix='sydney-padding-audit-') as tmp:
        def one(pair):
            number, (unit, record, text, function, start, end) = pair
            work = Path(tmp) / str(number)
            work.mkdir()
            elf, obj_hash = source_image.compile_unit(unit, project, cfg, work)
            # Only explicit frozen addresses resolve; no ROM inference API is called.
            emitted = source_image.compare.relocate(
                elf, '.text', record['section_bases'],
                source_image.FrozenSymbols(record['symbols']))
            if len(emitted) != text['emitted_size']:
                raise ValueError(f'{unit.key}: emitted text extent changed')
            if source_image.digest(emitted[:unit.text_size]) != unit.expected_hash:
                raise ValueError(f'{unit.key}: original source-owned text no longer matches')
            if any(emitted[unit.text_size:]):
                raise ValueError(f'{unit.key}: emitted tail is no longer all zero')
            size = end - unit.rom_start
            data = emitted[:size]
            if data != rom[unit.rom_start:end]:
                return None, {'unit_id': unit.key, 'source': unit.source,
                              'reason': 'expanded source text differs from original ROM',
                              'tail_rom_start': start, 'tail_rom_end': end}
            line_number, old_line = row_details(project, unit)
            fields = old_line.split('\t')
            fields[1] = f'0x{size:X}'
            fields[4] = source_image.digest(data)
            new_line = '\t'.join(fields)
            function_start, function_end, name = function
            proposal = {
                'unit_id': unit.key, 'source': unit.source,
                'source_sha256': record['source_sha256'],
                'manifest': unit.manifest, 'manifest_line': line_number,
                'old_row': old_line, 'proposed_row': new_line,
                'old_row_sha256': unit.row_hash,
                'proposed_row_sha256': source_image.digest(new_line.encode()),
                'old_text_sha256': unit.expected_hash,
                'new_text_sha256': fields[4],
                'old_text_size': unit.text_size, 'new_text_size': size,
                'emitted_text_size': len(emitted),
                'added_rom_start': start, 'added_rom_end': end,
                'added_bytes': end - start,
                'added_source_sha256': source_image.digest(emitted[unit.text_size:size]),
                'object_sha256': obj_hash,
                'pipeline': unit.spec.pipeline, 'compiler_flags': unit.spec.flags,
                'normalization': unit.normalization,
                'function': {'name': name, 'rom_start': function_start,
                             'rom_end': function_end,
                             'vram_start': function_start + source_image.DELTA},
                'function_prefix_covered_before': not uncovered(
                    function_start, start, initial_coverage),
                'new_function_body_decompilation': False,
            }
            return proposal, None
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            checked = list(pool.map(one, enumerate(candidates)))
    proposals = sorted([proposal for proposal, _ in checked if proposal],
                       key=lambda p: (p['added_rom_start'], p['manifest'], p['unit_id']))
    skipped.extend(failure for _, failure in checked if failure)
    coverage = list(initial_coverage)
    accepted = []
    for proposal in proposals:
        new_ranges = uncovered(proposal['added_rom_start'], proposal['added_rom_end'], coverage)
        if not new_ranges:
            skipped.append({'unit_id': proposal['unit_id'], 'source': proposal['source'],
                            'reason': 'duplicates an earlier verified proposal'})
            continue
        proposal['new_unique_ranges'] = [dict(rom_start=start, rom_end=end, size=end - start)
                                         for start, end in new_ranges]
        proposal['new_unique_bytes'] = sum(end - start for start, end in new_ranges)
        coverage = merge(coverage + [(proposal['added_rom_start'], proposal['added_rom_end'])])
        accepted.append(proposal)
    for proposal in accepted:
        function = proposal['function']
        proposal['completes_catalogued_function_extent'] = not uncovered(
            function['rom_start'], function['rom_end'], coverage)
    source_image.check_fresh(snapshot, source_image.inputs_snapshot(project, units))
    if catalogue_hash != source_image.file_hash(catalogue_path):
        raise ValueError('function catalogue changed during audit')
    result = {
        'version': 1, 'applied': False,
        'artifact_kind': 'verified source-emitted zero-padding proposals',
        'rom_sha1': EXPECTED_SHA1, 'link_plan_path': str(plan_path.relative_to(project)),
        'link_plan_sha256': source_image.file_hash(plan_path),
        'catalogue_path': str(catalogue_path.relative_to(project)),
        'catalogue_sha256': catalogue_hash,
        'audit_tool_path': 'tools/audit_source_padding.py',
        'audit_tool_sha256': source_image.file_hash(Path(__file__)),
        'verification': 'frozen source compilation and relocation; full expanded text compared to ROM',
        'placement_inference_during_audit': False,
        'source_zero_tail_units': tail_units, 'source_zero_tail_bytes': tail_bytes,
        'compiled_candidate_units': len(candidates), 'proposed_rows': len(accepted),
        'new_unique_bytes': sum(proposal['new_unique_bytes'] for proposal in accepted),
        'new_function_bodies': 0,
        'function_extents_completed': len({proposal['function']['name'] for proposal in accepted
                                           if proposal['completes_catalogued_function_extent']}),
        'proposals': accepted, 'skipped': skipped,
    }
    source_image.save_json(output, result)
    print(f'verified {len(accepted)} padding proposals: {result["new_unique_bytes"]} new unique bytes, '
          f'{result["function_extents_completed"]} completed catalogue extents; no rows applied')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=ROOT)
    parser.add_argument('--plan', type=Path, default=ROOT / 'config/link_units.json')
    parser.add_argument('--rom', type=Path, default=ROOT / 'baserom.z64')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/source_padding_proposals.json')
    parser.add_argument('--jobs', type=int, default=4)
    args = parser.parse_args()
    if args.jobs < 1:
        parser.error('--jobs must be positive')
    audit(args.project.resolve(), args.plan.resolve(), args.rom.resolve(), args.output.resolve(), args.jobs)


if __name__ == '__main__':
    main()
