#!/usr/bin/env python3
"""Focused RSP ownership, provenance and target boundary tests (no SDK needed)."""
import copy
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import build_rsp as rsp


class RspTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'tools').mkdir()
        (self.root / 'tools/build_rsp.py').write_bytes(Path(rsp.__file__).read_bytes())
        (self.root / 'source.s').write_text('.rsp\n')
        self.data = b'\x4a\x00\x00\x2c'
        self.section = {'name': '.text', 'rom_start': 0x2000, 'storage_vram': 0x80001400,
                        'size': 4, 'sha256': rsp.digest(self.data),
                        'logical_mappings': [{'file_offset': 0, 'size': 4, 'rsp_address': 0x1080,
                                              'memory': 'IMEM', 'role': 'task'}]}
        self.config = {'version': 1, 'target': rsp.TARGET, 'rom_size': 0x2000000,
                       'rom_sha1': 'a' * 40, 'assembler': {'commit': 'fixture'},
                       'inputs': {'source.s': rsp.digest((self.root / 'source.s').read_bytes())},
                       'units': [{'id': 'test', 'source': 'source.s', 'recipe': 'armips',
                                  'sections': [self.section]}]}
        self.config_path = self.root / 'config.json'
        self.write_config()

    def write_config(self):
        self.config_path.write_text(json.dumps(self.config))

    def piece(self, **changes):
        return dict(self.section, unit_id='test', source='source.s', **changes)

    def build_fixture(self):
        with patch.object(rsp, 'assemble', return_value=([(self.piece(), self.data)], [])):
            return rsp.build_rsp(self.config_path, self.root / 'out', self.root, armips='/bin/true')

    def test_rsp_target_is_not_cpu_abi(self):
        rsp.validate(self.config, self.root)
        self.config['target'] = dict(rsp.TARGET, cpu_abi='o32')
        with self.assertRaisesRegex(ValueError, 'RSP target'):
            rsp.validate(self.config, self.root)

    def test_overlap_equality_and_conflict(self):
        piece = self.piece()
        self.assertEqual(len(rsp.merge([(piece, self.data), (piece, self.data)])), 4)
        bad = b'\0' * 4
        other = dict(piece, sha256=rsp.digest(bad))
        with self.assertRaisesRegex(ValueError, 'conflicting RSP overlap'):
            rsp.merge([(piece, self.data), (other, bad)])

    def test_missing_f3dex_data_rejected(self):
        self.config['units'][0]['recipe'] = 'f3dex2_make'
        with self.assertRaisesRegex(ValueError, 'missing owned'):
            rsp.validate(self.config, self.root)

    def test_bounds_and_storage_address(self):
        for changes, message in [({'rom_start': -4}, 'ROM bounds'),
                                 ({'storage_vram': 0x80001401}, 'storage address'),
                                 ({'size': True}, 'integer size')]:
            config = copy.deepcopy(self.config)
            config['units'][0]['sections'][0].update(changes)
            with self.assertRaisesRegex(ValueError, message):
                rsp.validate(config, self.root)

    def test_logical_bank_bounds_and_coverage(self):
        mapping = self.section['logical_mappings'][0]
        for changes, message in [({'rsp_address': 0x1fff}, '4 KiB'),
                                 ({'memory': 'DMEM', 'rsp_address': 0}, 'wrong memory bank'),
                                 ({'size': 3}, 'unspecified')]:
            config = copy.deepcopy(self.config)
            config['units'][0]['sections'][0]['logical_mappings'][0].update(changes)
            with self.assertRaisesRegex(ValueError, message):
                rsp.validate(config, self.root)
        self.assertEqual(mapping['memory'], 'IMEM')

    def test_stale_source_rejected(self):
        (self.root / 'source.s').write_text('.word 0\n')
        with self.assertRaisesRegex(ValueError, 'stale RSP input'):
            rsp.validate(self.config, self.root)

    def test_path_escape_rejected(self):
        for name in ('../outside.s', '/tmp/outside.s'):
            with self.assertRaisesRegex(ValueError, 'repository-relative'):
                rsp.local(self.root, name)
        (self.root / 'escape').symlink_to('/tmp')
        with self.assertRaisesRegex(ValueError, 'escapes repository'):
            rsp.local(self.root, 'escape/other.s')

    def test_build_uses_source_only_and_preserves_owned_zero(self):
        self.data = b'\0' * 4
        self.section['sha256'] = rsp.digest(self.data)
        self.write_config()
        with patch.object(rsp, 'verify', side_effect=AssertionError('ROM read during build')):
            artifact = self.build_fixture()
        self.assertFalse(artifact['complete_rom'])
        self.assertFalse(artifact['post_build_rom_comparison'])
        self.assertEqual(artifact['unique_owned_bytes'], 4)
        self.assertEqual(rsp.check_artifact(self.root / 'out/rsp.json', self.root)['pieces'][0]['size'], 4)

    def test_artifact_corruption_stale_producer_and_placement(self):
        self.build_fixture()
        path = self.root / 'out/rsp.json'
        artifact = json.loads(path.read_text())
        piece = self.root / 'out' / artifact['pieces'][0]['file']
        piece.write_bytes(b'\0' * 4)
        with self.assertRaisesRegex(ValueError, 'size/digest'):
            rsp.check_artifact(path, self.root)
        piece.write_bytes(self.data)
        artifact['pieces'][0]['rom_start'] += 4
        path.write_text(json.dumps(artifact))
        with self.assertRaisesRegex(ValueError, 'placement/provenance'):
            rsp.check_artifact(path, self.root)
        self.build_fixture()
        (self.root / 'tools/build_rsp.py').write_text('changed')
        with self.assertRaisesRegex(ValueError, 'stale RSP input'):
            rsp.check_artifact(path, self.root)

    def test_unsupported_recipe(self):
        self.config['units'][0]['recipe'] = 'copy_original_rom'
        with self.assertRaisesRegex(ValueError, 'unsupported RSP'):
            rsp.validate(self.config, self.root)


if __name__ == '__main__':
    unittest.main()
