#!/usr/bin/env python3
import csv
from hashlib import sha1
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import build_archive_payload as payload


class ArchivePayloadTests(unittest.TestCase):
    def fixture(self, root):
        inventory = root / 'records.tsv'
        fields = ('index', 'record_at', 'logical_offset', 'physical_start',
                  'physical_end', 'size', 'aux', 'role', 'kind',
                  'canonical_index', 'sha1', 'name')
        rows = [
            dict(index='0', record_at='0', logical_offset='0', physical_start='0x10',
                 physical_end='0x12', size='2', aux='0', role='named_file', kind='dat',
                 canonical_index='0', sha1=sha1(b'ab').hexdigest(), name='a.dat'),
            dict(index='1', record_at='0', logical_offset='0', physical_start='0x13',
                 physical_end='0x15', size='2', aux='0', role='named_file', kind='dat',
                 canonical_index='1', sha1=sha1(b'cd').hexdigest(), name='b.dat'),
            dict(index='2', record_at='0', logical_offset='0', physical_start='0x10',
                 physical_end='0x12', size='2', aux='0', role='named_file', kind='dat',
                 canonical_index='0', sha1=sha1(b'ab').hexdigest(), name='alias.dat'),
        ]
        with inventory.open('w', newline='') as output:
            writer = csv.DictWriter(output, fields, delimiter='\t')
            writer.writeheader(); writer.writerows(rows)
        assets = root / 'assets'; assets.mkdir()
        (assets / '0000.bin').write_bytes(b'ab')
        (assets / '0001.bin').write_bytes(b'cd')
        return inventory, assets

    def test_assembles_unique_assets_and_ff_alignment(self):
        with tempfile.TemporaryDirectory() as tmp, \
             patch.object(payload, 'START', 0x10), patch.object(payload, 'END', 0x15):
            inventory, assets = self.fixture(Path(tmp))
            data, inputs = payload.assemble(inventory, assets)
            self.assertEqual(data, b'ab\xffcd')
            self.assertEqual([item['index'] for item in inputs], [0, 1])

    def test_rejects_modified_asset(self):
        with tempfile.TemporaryDirectory() as tmp, \
             patch.object(payload, 'START', 0x10), patch.object(payload, 'END', 0x15):
            inventory, assets = self.fixture(Path(tmp))
            (assets / '0001.bin').write_bytes(b'xx')
            with self.assertRaisesRegex(ValueError, 'failed size/hash'):
                payload.assemble(inventory, assets)


if __name__ == '__main__':
    unittest.main()
