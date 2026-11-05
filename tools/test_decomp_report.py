#!/usr/bin/env python3
"""Regression checks for exact coverage accounting, independent of the ROM."""
import contextlib
import io
import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import generate_decomp_report as report


def write_data_ledger(root, manifests):
    config = root / 'config'
    config.mkdir(exist_ok=True)
    (config / 'segments.toml').write_text('[rom]\nsha1 = "test-image"\n')
    classification = config / 'classification.tsv'
    classification.write_text('test initialized-data classification')
    inputs = [{"path": path.relative_to(root).as_posix(),
               "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
              for path in [*manifests, classification]]
    ledger = {"version": 1, "rom_sha1": "test-image", "total_data": 16,
              "matched_data": 8, "inputs": inputs,
              "classification": inputs[-1],
              "verification": {"units": 1, "exact_units": 1},
              "ranges": [{"rom_start": 0x2000, "rom_end": 0x2008, "size": 8}]}
    output = config / 'matching_data.json'
    output.write_text(json.dumps(ledger))
    return output


class CoverageTests(unittest.TestCase):
    def test_union_counts_overlaps_and_adjacency_once(self):
        merged = report.merge_ranges([(20, 30), (0, 10), (5, 15),
                                      (15, 20), (2, 8), (40, 44)])
        self.assertEqual(merged, [(0, 30), (40, 44)])
        self.assertEqual(report.covered_bytes(3, 42, merged), 29)
        self.assertEqual(report.missing_ranges(3, 42, merged), [(30, 40)])

    def test_empty_and_outside_ranges(self):
        self.assertEqual(report.covered_bytes(10, 20, []), 0)
        self.assertEqual(report.missing_ranges(10, 20, []), [(10, 20)])
        spans = report.merge_ranges([(0, 12), (18, 30)])
        self.assertEqual(report.covered_bytes(10, 20, spans), 4)
        self.assertEqual(report.missing_ranges(10, 20, spans), [(12, 18)])
        self.assertEqual(report.missing_ranges(10, 20, [(0, 30)]), [])

    def test_union_and_gaps_partition_each_byte(self):
        # A byte-set oracle checks combinations independently of interval logic.
        spans = [(0, 7), (3, 12), (18, 25), (11, 20)]
        for selection in range(1 << len(spans)):
            chosen = [span for bit, span in enumerate(spans) if selection & (1 << bit)]
            merged = report.merge_ranges(chosen)
            expected = {byte for left, right in chosen for byte in range(left, right)}
            for start, end in ((0, 30), (4, 22), (13, 17)):
                domain = set(range(start, end))
                self.assertEqual(report.covered_bytes(start, end, merged),
                                 len(domain & expected))
                gaps = report.missing_ranges(start, end, merged)
                actual = {byte for left, right in gaps for byte in range(left, right)}
                self.assertEqual(actual, domain - expected)

    def test_invalid_ranges_fail(self):
        for span in ((2, 2), (3, 2)):
            with self.assertRaises(ValueError):
                report.merge_ranges([span])

    def test_data_ledger_requires_current_verified_inputs(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            manifest = root / 'matching.tsv'
            manifest.write_text('initial source declaration')
            ledger = write_data_ledger(root, [manifest])
            with patch.object(report, 'ROOT', root), \
                 patch.object(report, 'MANIFESTS', [manifest]):
                self.assertEqual(report.load_data_measures(ledger), (16, 8))
                manifest.write_text('changed source declaration')
                with self.assertRaisesRegex(ValueError, 'stale data ledger input'):
                    report.load_data_measures(ledger)
                ledger = write_data_ledger(root, [manifest])
                data = json.loads(ledger.read_text())
                data['matched_data'] = 9
                ledger.write_text(json.dumps(data))
                with self.assertRaisesRegex(ValueError, 'inconsistent initialized-data totals'):
                    report.load_data_measures(ledger)
                ledger = write_data_ledger(root, [manifest])
                extra = root / 'new_matching.tsv'
                extra.write_text('new unverified compilation unit')
                with patch.object(report, 'MANIFESTS', [manifest, extra]):
                    with self.assertRaisesRegex(ValueError, 'unverified manifest'):
                        report.load_data_measures(ledger)

    def test_partial_functions_and_global_coverage(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            inventory = root / 'functions.toml'
            inventory.write_text('''[[section]]
rom = 0x1000
size = 80
functions = [
 {name = "whole", vram = 0x80000400, size = 16},
 {name = "prefix", vram = 0x80000420, size = 16},
 {name = "suffix", vram = 0x80000440, size = 16},
]
''')
            manifest = root / 'matching.tsv'
            manifest.write_text('''0x1000\t0x8\tfirst.c
0x1008\t0x8\tsecond.c
0x1004\t0x8\toverlap.c
0x1020\t0x8\tprefix.c
0x1048\t0x8\tsuffix.c
0x0\t0x100\toutside.c
''')
            output = root / 'report.json'
            data_ledger = write_data_ledger(root, [manifest])
            with patch.object(report, 'ROOT', root), \
                 patch.object(report, 'DATA_LEDGER', data_ledger), \
                 patch.object(report, 'FUNCTIONS', inventory), \
                 patch.object(report, 'MANIFESTS', [manifest]), \
                 patch.object(report, 'OUTPUT', output), \
                 contextlib.redirect_stdout(io.StringIO()):
                report.main()
            result = json.loads(output.read_text())
            self.assertEqual(result['measures']['matched_code'], '32')
            self.assertEqual(result['measures']['matched_functions'], 1)
            whole, prefix, suffix = result['units']
            self.assertTrue(whole['metadata']['complete'])
            for unit in (prefix, suffix):
                self.assertFalse(unit['metadata']['complete'])
                self.assertEqual(unit['measures']['matched_code'], '8')
                self.assertEqual(unit['functions'][0]['fuzzy_match_percent'], 50)
            self.assertEqual(suffix['metadata']['source_path'], 'suffix.c')
            gaps = json.loads(output.with_name('decomp_gaps.json').read_text())
            self.assertEqual(gaps['incomplete_functions'], ['prefix', 'suffix'])
            self.assertEqual(gaps['unmatched_code_bytes'], 48)
            self.assertEqual([gap['matched_bytes'] for gap in gaps['function_gaps']], [8, 8])
            self.assertEqual(sum(gap['size'] for gap in gaps['unmatched_ranges']), 48)
            for gap in gaps['unmatched_ranges']:
                self.assertEqual(gap['vram_start'] - gap['rom_start'],
                                 report.ROM_TO_VRAM)


if __name__ == '__main__':
    unittest.main()
