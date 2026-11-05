#!/usr/bin/env python3
"""Regression checks for ownership, stale plans and source-only output."""
import json
from pathlib import Path
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

import build_source_image as image


class CoverageTests(unittest.TestCase):
    def test_equal_overlap_does_not_double_count(self):
        result = image.CoverageImage(10, 18)
        result.add(11, b'abc', 'one')
        result.add(12, b'bcde', 'two')
        self.assertEqual(sum(result.owned), 5)
        self.assertEqual(result.overlap_bytes, 2)
        self.assertEqual(result.gaps(), [dict(rom_start=10, rom_end=11, size=1),
                                        dict(rom_start=16, rom_end=18, size=2)])

    def test_conflicting_overlap_and_escape_are_rejected(self):
        result = image.CoverageImage(10, 18)
        result.add(11, b'abc', 'one')
        with self.assertRaisesRegex(ValueError, 'conflicting overlap'):
            result.add(12, b'X', 'two')
        with self.assertRaisesRegex(ValueError, 'escapes'):
            result.add(9, b'X', 'outside')
        with self.assertRaisesRegex(ValueError, 'escapes'):
            result.add(17, b'XX', 'outside')

    def test_emitted_zero_is_owned_but_unfilled_zero_is_not(self):
        result = image.CoverageImage(0, 4)
        result.add(1, bytes(2), 'source zero')
        self.assertEqual(result.data, bytes(4))
        self.assertEqual(result.owned, bytes((0, 1, 1, 0)))


class PlanTests(unittest.TestCase):
    def test_header_source_removed_and_new_inputs_make_plan_stale(self):
        snapshot = {'source.c': 'a', 'headers/example.h': 'b'}
        image.check_fresh(snapshot, snapshot.copy())
        variants = [{'source.c': 'changed', 'headers/example.h': 'b'},
                    {'source.c': 'a', 'headers/example.h': 'changed'},
                    {'source.c': 'a'},
                    dict(snapshot, new_header='c')]
        for actual in variants:
            with self.subTest(actual=actual), self.assertRaisesRegex(ValueError, 'stale'):
                image.check_fresh(snapshot, actual)

    def test_unfrozen_address_encoded_symbol_is_not_inferred(self):
        symbols = image.FrozenSymbols({'present': 123})
        self.assertEqual(symbols.resolve('present'), 123)
        self.assertIsNone(symbols.resolve('func_80001000'))
        self.assertNotIn('func_80001000', symbols)
        with self.assertRaises(KeyError):
            _ = symbols['func_80001000']

    def test_common_symbols_are_frozen_as_external_addresses(self):
        elf = SimpleNamespace(symbols=[
            SimpleNamespace(name='common', section=0xFFF2),
            SimpleNamespace(name='undefined', section=0),
            SimpleNamespace(name='local', section=1)])
        symbols = image.symmod.SymbolMap(common=0x80060000, undefined=0x80070000)
        self.assertEqual(image.freeze_symbols(elf, symbols),
                         dict(common=0x80060000, undefined=0x80070000))

    def test_owned_reference_check_does_not_claim_unowned_text_tail(self):
        elf = SimpleNamespace(section=lambda name: object())
        relocations = [SimpleNamespace(section='.data', offset=4),
                       SimpleNamespace(section='.data', offset=20)]
        with patch.object(image.compare, 'relocations', return_value=relocations):
            self.assertEqual(image.owned_references(elf, '.data', {'.text': 8}),
                             [('.text', 4)])
            self.assertEqual(image.owned_references(elf, '.data', {'.text': 4}), [])

    def test_source_change_rejected_before_compilation(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'source.c').write_text('changed')
            unit = SimpleNamespace(key='unit', row_hash='row', source='source.c')
            record = {'row_sha256': 'row', 'source_sha256': image.digest(b'old')}
            with patch.object(image, 'compile_unit') as compiler:
                with self.assertRaisesRegex(ValueError, 'stale'):
                    image.build_one(unit, record, project, None, project)
                compiler.assert_not_called()

    def test_partial_build_uses_only_compiled_bytes_and_no_rom_inference(self):
        class FakeElf:
            def section(self, name):
                return SimpleNamespace(size=4, data=b'\x12\x34\x00\x00') if name == '.text' else None
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'source.c').write_text('source')
            payload = b'\x12\x34\x00\x00'
            unit = image.Unit('unit', 'manifest', 'row', 'source.c', image.START, 4,
                              image.digest(payload), None, [], None)
            # Overlay text may relocate at a runtime address unrelated to the
            # bank-wide delta while still owning the manifest's ROM range.
            text_vram = image.START + image.DELTA + 0x1000
            section = dict(name='.text', vram=text_vram,
                           rom_start=image.START, owned_size=4, emitted_size=4,
                           unowned_zero_tail=0, sha256=image.digest(payload))
            record = dict(id='unit', row_sha256='row', source_sha256=image.file_hash(project / 'source.c'),
                          section_bases={'.text': text_vram},
                          symbols={}, sections=[section], discarded_sections=[])
            plan = dict(version=image.VERSION, resident_rom_start=image.START,
                        resident_rom_end=image.END, inputs={}, units=[record])
            plan_path = project / 'plan.json'
            image.save_json(plan_path, plan)
            with patch.object(image, 'units', return_value=[unit]), \
                 patch.object(image, 'inputs_snapshot', return_value={}), \
                 patch.object(image, 'configuration', return_value=None), \
                 patch.object(image, 'compile_unit', return_value=(FakeElf(), 'object')), \
                 patch.object(image.compare, 'relocate', return_value=payload), \
                 patch.object(image.compare, 'compare_object', side_effect=AssertionError('ROM inference called')):
                image.build_image(project, plan_path, project / 'output', 1)
                record['section_bases'] = {}
                with self.assertRaisesRegex(ValueError, 'missing or changed'):
                    image.build_one(unit, record, project, None, project)
            output = project / 'output'
            actual = (output / 'resident.partial.bin').read_bytes()
            bitmap = (output / 'resident.ownership.bin').read_bytes()
            self.assertEqual(actual[:4], payload)
            self.assertEqual(sum(bitmap), 4)
            self.assertEqual(actual[4:], bytes(len(actual) - 4))
            self.assertEqual(bitmap[4:], bytes(len(bitmap) - 4))
            ledger = json.loads((output / 'source_image.json').read_text())
            self.assertFalse(ledger['complete_rom'])
            self.assertEqual(ledger['covered_bytes'], 4)


if __name__ == '__main__':
    unittest.main()
