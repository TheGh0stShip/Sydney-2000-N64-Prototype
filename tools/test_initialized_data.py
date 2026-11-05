#!/usr/bin/env python3
"""Data-only ownership/ABI/provenance tests; no ROM or N64 compiler needed."""
import copy
from pathlib import Path
import tempfile
from types import SimpleNamespace
import unittest

import build_initialized_data as data


def fixture_unit():
    return {'id': 'fixture', 'source': 'src/data.c', 'inputs': {}, 'pipeline': 'sn',
            'flags': [], 'symbols': {}, 'sections': [
                {'name': '.data', 'segment': 'resident', 'rom_start': 0x1000,
                 'vram': 0x80000400, 'size': 4, 'sha256': data.sha256(bytes(4))}]}


class FakeElf:
    def __init__(self, sections, relocations=(), symbols=()):
        self.sections = [SimpleNamespace(name=name, data=body, size=len(body), type=1,
                                        index=index) for index, (name, body) in enumerate(sections)]
        self.symbols = symbols
        self._relocations = relocations

    def relocations(self, section):
        return self._relocations

    def relocate(self, name, bases, symbols):
        return next(section.data for section in self.sections if section.name == name)


class InitializedDataTests(unittest.TestCase):
    def test_explicit_data_zero_initializer_is_owned(self):
        unit = fixture_unit()
        elf = FakeElf([('.text', b''), ('.data', bytes(4))])
        pieces = data.extract_pieces(elf, {'.text': 6, '.data': 3}, unit)
        self.assertEqual(len(pieces), 1)
        self.assertEqual(pieces[0].data, bytes(4))
        self.assertEqual(data.merge_pieces(pieces), dict.fromkeys(range(0x1000, 0x1004), 0))

    def test_dummy_text_or_executable_section_is_forbidden(self):
        for name, flags in (('.text', 0), ('.text', 6), ('.startup', 6)):
            with self.subTest(name=name, flags=flags), self.assertRaisesRegex(ValueError, 'executable'):
                data.extract_pieces(FakeElf([(name, bytes(4)), ('.data', bytes(4))]),
                                    {name: flags, '.data': 3}, fixture_unit())

    def test_unexpected_missing_and_padded_sections_fail(self):
        variants = [([('.data', bytes(4)), ('.rodata', bytes(4))], 'unexpected'),
                    ([('.bss', b'')], 'missing'),
                    ([('.data', bytes(8))], 'extent')]
        for sections, error in variants:
            with self.subTest(sections=sections), self.assertRaisesRegex(ValueError, error):
                data.extract_pieces(FakeElf(sections), {'.data': 3, '.rodata': 2}, fixture_unit())

    def test_wrong_initialized_values_are_rejected(self):
        with self.assertRaisesRegex(ValueError, 'digest'):
            data.extract_pieces(FakeElf([('.data', b'abcd')]), {'.data': 3}, fixture_unit())

    def test_references_to_unplaced_defined_sections_are_rejected(self):
        elf = FakeElf([('.data', bytes(4)), ('.bss', b'')], [(0, 2, 0, None)],
                      [SimpleNamespace(section=1)])
        with self.assertRaisesRegex(ValueError, 'unplaced'):
            data.extract_pieces(elf, {'.data': 3}, fixture_unit())

    def test_equal_overlaps_deduplicate_but_conflicts_fail(self):
        one = data.Piece('one', 'one.c', '.data', 'resident', 10, 0x8000000A, b'abcd')
        two = data.Piece('two', 'two.c', '.data', 'resident', 12, 0x8000000C, b'cd')
        owned = data.merge_pieces([one, two])
        self.assertEqual(len(owned), 4)
        self.assertEqual(data.ranges_of(owned), [dict(rom_start=10, rom_end=14, size=4,
                                                     sha256=data.sha256(b'abcd'))])
        two.data = b'XX'
        with self.assertRaisesRegex(ValueError, 'conflicting'):
            data.merge_pieces([one, two])

    def test_manifest_rejects_wrong_abi_addresses_and_stale_sources(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'src').mkdir()
            source = project / 'src/data.c'
            source.write_text('unsigned int value = 0;')
            unit = fixture_unit()
            unit['inputs'] = {'src/data.c': data.sha256(source.read_bytes())}
            config = {'version': 1, 'target': data.TARGET.copy(), 'segments': [
                {'id': 'resident', 'rom_start': 0x1000, 'rom_end': 0x2000,
                 'vram_delta': 0x7FFFF400}], 'units': [unit]}
            data.validate_manifest(config, project)
            variants = []
            wrong = copy.deepcopy(config); wrong['target']['pointer_bits'] = 64; variants.append(wrong)
            wrong = copy.deepcopy(config); wrong['units'][0]['sections'][0]['vram'] += 4; variants.append(wrong)
            wrong = copy.deepcopy(config); wrong['units'][0]['sections'][0]['rom_start'] = 0x2000; variants.append(wrong)
            wrong = copy.deepcopy(config); wrong['units'][0]['symbols'] = {'host_pointer': 1 << 40}; variants.append(wrong)
            for wrong in variants:
                with self.subTest(config=wrong), self.assertRaises(ValueError):
                    data.validate_manifest(wrong, project)
            inputs = data.snapshot(project, [source])
            source.write_text('unsigned int value = 1;')
            with self.assertRaisesRegex(ValueError, 'stale'):
                data.validate_manifest(config, project)
            with self.assertRaisesRegex(ValueError, 'stale'):
                data.check_inputs(project, inputs)

    def test_elf_header_rejects_n32_and_64_bit_abi_flags(self):
        import struct
        raw = bytearray(52)
        raw[:7] = b'\x7fELF\x01\x02\x01'
        struct.pack_into('>HH', raw, 16, 1, 8)
        for flags in (0x20, 0x2000, 0x3000, 0x4000):
            struct.pack_into('>I', raw, 0x24, flags)
            with self.subTest(flags=flags), self.assertRaisesRegex(ValueError, 'o32'):
                data.elf_section_flags(SimpleNamespace(data=raw, sections=[]))
        struct.pack_into('>I', raw, 0x24, 0x20001101)
        self.assertEqual(data.elf_section_flags(SimpleNamespace(data=raw, sections=[])), {})

    def test_repository_inputs_cannot_escape_to_host_files(self):
        with tempfile.TemporaryDirectory() as tmp:
            for path in ('/etc/passwd', '../private.h'):
                with self.subTest(path=path), self.assertRaises(ValueError):
                    data.local_path(Path(tmp), path)


if __name__ == '__main__':
    unittest.main()
