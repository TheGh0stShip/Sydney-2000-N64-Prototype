#!/usr/bin/env python3
"""Archive directory packing, bounds, aliases, and source-only checks."""
from copy import deepcopy
import struct
import unittest

from build_archive_directory import build_directory, RECORD_SIZE

START = 0x1000
END = START + 4 + 2 * RECORD_SIZE


def fixture():
    return [dict(index=str(index), record_at=hex(START + 4 + index * RECORD_SIZE),
                 logical_offset='0x10', physical_start=hex(END + 16),
                 physical_end=hex(END + 20), size='4', aux=hex(index),
                 canonical_index='0', name=name)
            for index, name in enumerate(('sprites\\ball.spr', 'alias.spr'))]


class DirectoryTests(unittest.TestCase):
    def test_big_endian_fields_names_and_duplicate_aliases(self):
        rows = fixture()
        result = build_directory(rows, START, END, END + 100)
        self.assertEqual(len(result), END - START)
        self.assertEqual(struct.unpack_from('>I', result)[0], 2)
        self.assertEqual(struct.unpack_from('>III', result, 4), (4, 16, 0))
        self.assertEqual(struct.unpack_from('>III', result, 4 + RECORD_SIZE), (4, 16, 1))
        self.assertEqual(result[16:80], b'sprites\\ball.spr' + bytes(48))

    def test_names_must_fit_without_truncation(self):
        for name in ('', 'a' * 64, 'bad\0name', 'bad\tname', '\u00e9'):
            rows = fixture()
            rows[0]['name'] = name
            with self.assertRaises(ValueError):
                build_directory(rows, START, END, END + 100)

    def test_invalid_extents_and_widths_fail(self):
        mutations = [('index', '2'), ('record_at', '0'), ('size', '-1'),
                     ('aux', '0x100000000'), ('logical_offset', '0x100000000'),
                     ('physical_start', str(END - 1)), ('physical_end', str(END + 101)),
                     ('canonical_index', '1')]
        for field, value in mutations:
            rows = deepcopy(fixture())
            rows[0][field] = value
            with self.subTest(field=field, value=value), self.assertRaises(ValueError):
                build_directory(rows, START, END, END + 100)

    def test_count_and_alias_geometry_fail(self):
        with self.assertRaises(ValueError):
            build_directory(fixture()[:1], START, END, END + 100)
        rows = fixture()
        rows[1]['canonical_index'] = '1'
        with self.assertRaisesRegex(ValueError, 'duplicate alias'):
            build_directory(rows, START, END, END + 100)


if __name__ == '__main__':
    unittest.main()
