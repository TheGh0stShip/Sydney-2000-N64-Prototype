#!/usr/bin/env python3
"""Ownership, input-provenance and provider-boundary regression checks."""
import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import compose_reconstruction as reconstruction


class CompositionTests(unittest.TestCase):
    def test_identical_overlaps_deduplicate_and_conflicts_fail(self):
        image = reconstruction.RomImage(8)
        image.add(2, b'abcd', 'one')
        image.add(3, b'bc', 'alias')
        self.assertEqual(sum(image.owned), 4)
        self.assertEqual(image.equal_overlap_bytes, 2)
        with self.assertRaisesRegex(ValueError, 'conflicting'):
            image.add(4, b'X', 'conflict')

    def test_zero_value_does_not_create_ownership(self):
        image = reconstruction.RomImage(8)
        image.add(2, bytes(2), 'typed zero')
        self.assertEqual(image.data, bytes(8))
        self.assertEqual(image.owned, bytes((0, 0, 1, 1, 0, 0, 0, 0)))
        self.assertEqual(image.gaps(), [dict(rom_start=0, rom_end=2, size=2),
                                        dict(rom_start=4, rom_end=8, size=4)])

    def test_rom_bounds_and_declared_regions_are_enforced(self):
        image = reconstruction.RomImage(8)
        for start, payload in ((-1, b'a'), (8, b'a'), (7, b'ab')):
            with self.subTest(start=start), self.assertRaisesRegex(ValueError, 'bounds'):
                image.add(start, payload, 'outside')
        for start, size in ((9, 2), (19, 2), (10, -1), (True, 1)):
            with self.subTest(start=start), self.assertRaisesRegex(ValueError, 'region'):
                reconstruction.require_region(start, size, 10, 20, 'restricted')
        with self.assertRaisesRegex(ValueError, 'classified'):
            reconstruction.require_data(10, 4, [(10, 12)])

    def test_stale_inputs_and_mid_composition_changes_are_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            source = project / 'source.c'
            source.write_bytes(b'original')
            tracker = reconstruction.Evidence(project)
            tracker.check_inputs([dict(path='source.c', sha256=reconstruction.sha256(b'original'))])
            source.write_bytes(b'changed')
            with self.assertRaisesRegex(ValueError, 'stale|changed'):
                tracker.fresh()
            with self.assertRaisesRegex(ValueError, 'stale'):
                reconstruction.Evidence(project).check_inputs([
                    dict(path='source.c', sha256=reconstruction.sha256(b'original'))])

    def test_sdk_hashes_resolve_in_the_real_namespace_not_repo_paths(self):
        with tempfile.TemporaryDirectory() as tmp:
            project, sdk = Path(tmp) / 'project', Path(tmp) / 'sdk'
            project.mkdir(); sdk.mkdir()
            (sdk / 'elf.py').write_bytes(b'code')
            tracker = reconstruction.Evidence(project, sdk_root=sdk)
            tracker.check_inputs([dict(path='@n64dk/elf.py', sha256=reconstruction.sha256(b'code'))])
            repo, external = tracker.metadata()
            self.assertEqual(repo, [])
            self.assertEqual(external[0]['path'], '@n64dk/elf.py')
            (sdk / 'new.py').write_bytes(b'new')
            with self.assertRaisesRegex(ValueError, 'file set'):
                reconstruction.Evidence(project, sdk_root=sdk).check_inputs([
                    dict(path='@n64dk/elf.py', sha256=reconstruction.sha256(b'code'))])

    def test_piece_corruption_and_declared_size_are_checked(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            artifact = project / 'component.json'
            payload = project / 'piece.bin'
            payload.write_bytes(b'abcd')
            item = {'file': 'piece.bin'}
            tracker = reconstruction.Evidence(project)
            self.assertEqual(reconstruction.piece_bytes(tracker, artifact, item, 4,
                                                        reconstruction.sha256(b'abcd')), b'abcd')
            with self.assertRaisesRegex(ValueError, 'size'):
                reconstruction.piece_bytes(tracker, artifact, item, 3, reconstruction.sha256(b'abcd'))
            payload.write_bytes(b'corrupt')
            with self.assertRaisesRegex(ValueError, 'corrupt'):
                reconstruction.piece_bytes(reconstruction.Evidence(project), artifact, item, 7,
                                           reconstruction.sha256(b'abcd'))

    def test_typed_header_and_capacity_fill_are_serialized_without_rom_input(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'config').mkdir()
            source = Path(__file__).parents[1] / 'config/rom_layout.json'
            (project / 'config/rom_layout.json').write_bytes(source.read_bytes())
            pieces = reconstruction.load_static_layout(reconstruction.Evidence(project))
            self.assertEqual(pieces[0][0], 0)
            self.assertEqual(len(pieces[0][1]), 0x40)
            self.assertEqual(pieces[0][1][0x20:0x34], b'Syd2k USA           ')
            self.assertEqual(pieces[1][0], 0x1DC1CE2)
            self.assertEqual(len(pieces[1][1]), 0x2000000 - 0x1DC1CE2)
            self.assertFalse(any(pieces[1][1]))

    def test_absolute_traversing_and_symlinked_piece_paths_are_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp) / 'project'
            outside = Path(tmp) / 'outside'
            project.mkdir(); outside.mkdir()
            (project / 'escape').symlink_to(outside, target_is_directory=True)
            for path in ('/etc/passwd', '../outside/file', 'escape/file'):
                with self.subTest(path=path), self.assertRaisesRegex(ValueError, 'path'):
                    reconstruction.safe_path(project, path)

    def test_unknown_component_kinds_and_missing_artifacts_fail_clearly(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            artifact = project / 'component.json'
            artifact.write_text(json.dumps({'version': 1, 'kind': 'opaque original ROM blob'}))
            with self.assertRaisesRegex(ValueError, 'unsupported'):
                reconstruction.load_directory(reconstruction.Evidence(project), artifact)
            with self.assertRaisesRegex(ValueError, 'make archive-directory'):
                reconstruction.load_directory(reconstruction.Evidence(project), project / 'missing.json')
            with self.assertRaisesRegex(ValueError, 'make source-pieces'):
                reconstruction.load_resident(reconstruction.Evidence(project), project / 'missing.json', [])

    def test_resident_text_piece_is_bound_to_frozen_plan_and_source_inputs(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            source = 'src/source.c'
            manifest = 'config/matching_fixture.tsv'
            payload = b'code'
            row = '0x1000\t0x4\t' + source + '\t-O2\t' + reconstruction.sha256(payload)
            unit_id = 'matching_fixture.tsv:' + reconstruction.sha256(row.encode())[:16]
            unit = dict(id=unit_id, source=source, manifest=manifest, includes=[],
                        source_sha256=reconstruction.sha256(b'source'))
            section = dict(name='.text', rom_start=0x1000, vram=0x80000400,
                           owned_size=4, emitted_size=4, unowned_zero_tail=0,
                           sha256=reconstruction.sha256(payload))
            unit['sections'] = [section]
            names = reconstruction.resident_input_names(project, [unit])
            for name in names:
                path = project / name
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(b'fixture')
            (project / source).write_bytes(b'source')
            (project / manifest).write_text(row + '\n')
            inputs = {name: reconstruction.sha256((project / name).read_bytes()) for name in names}
            plan = dict(version=1, rom_sha1=reconstruction.ROM_SHA1, inputs=inputs, units=[unit],
                        resident_rom_start=reconstruction.RESIDENT_START,
                        resident_rom_end=reconstruction.RESIDENT_END)
            plan_path = project / 'config/link_units.json'
            plan_path.write_text(json.dumps(plan))
            artifact = project / 'build/source_image.json'
            artifact.parent.mkdir()
            (artifact.parent / 'piece.bin').write_bytes(payload)
            piece = dict(section, unit_id=unit_id, source=source,
                         source_sha256=unit['source_sha256'], file='piece.bin')
            metadata = dict(version=1, artifact_kind='source-relocated resident partial image',
                            complete_rom=False, rom_start=reconstruction.RESIDENT_START,
                            rom_end=reconstruction.RESIDENT_END, covered_bytes=4,
                            link_plan_sha256=reconstruction.sha256(plan_path.read_bytes()), pieces=[piece])
            artifact.write_text(json.dumps(metadata))
            result = reconstruction.load_resident(reconstruction.Evidence(project), artifact, [])
            self.assertEqual(result[0][:2], (0x1000, payload))
            piece['sha256'] = reconstruction.sha256(b'fake')
            metadata['pieces'] = [piece]
            artifact.write_text(json.dumps(metadata))
            with self.assertRaisesRegex(ValueError, 'frozen'):
                reconstruction.load_resident(reconstruction.Evidence(project), artifact, [])

    def test_matching_partial_sha_never_overrides_gaps_or_emits_full_filename(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'tools').mkdir()
            (project / 'tools/compose_reconstruction.py').write_bytes(
                Path(reconstruction.__file__).read_bytes())
            output = project / 'output'
            output.mkdir()
            (output / 'rom.z64').write_bytes(b'stale full artifact')
            piece = (2, bytes(2), dict(owner='fixture', kind='typed fixture', source='fixture.c'))
            with patch.object(reconstruction, 'ROM_SIZE', 8), \
                 patch.object(reconstruction, 'ROM_SHA1', hashlib.sha1(bytes(8)).hexdigest()), \
                 patch.object(reconstruction, 'REGIONS', [(0, 8, 'fixture')]), \
                 patch.object(reconstruction, 'classified_data', return_value=[]), \
                 patch.object(reconstruction, 'load_resident', return_value=[piece]), \
                 patch.object(reconstruction, 'load_initialized', return_value=[]), \
                 patch.object(reconstruction, 'load_rsp', return_value=[]), \
                 patch.object(reconstruction, 'load_runtime', return_value=[]), \
                 patch.object(reconstruction, 'load_static_layout', return_value=[]), \
                 patch.object(reconstruction, 'load_directory', return_value=[]):
                with self.assertRaisesRegex(ValueError, '6 unowned bytes in 2 gaps'):
                    reconstruction.compose(project, project / 'resident.json',
                                           project / 'data.json', project / 'directory.json',
                                           output, require_complete=True)
            summary = json.loads((output / 'reconstruction.json').read_text())
            self.assertFalse(summary['complete_rom'])
            self.assertEqual(summary['partial_image_sha1'], hashlib.sha1(bytes(8)).hexdigest())
            self.assertFalse((output / 'rom.z64').exists())
            self.assertEqual((output / 'rom.ownership.bin').read_bytes(),
                             bytes((0, 0, 1, 1, 0, 0, 0, 0)))

    def test_rsp_component_enforces_code_and_dmem_regions(self):
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            (project / 'tools').mkdir()
            import build_rsp
            (project / 'tools/build_rsp.py').write_bytes(Path(build_rsp.__file__).read_bytes())
            artifact = project / 'rsp.json'
            payload = project / 'code.bin'
            payload.write_bytes(b'\x4a\0\0\x2c')
            piece = dict(unit_id='graphics', name='.text', source='rsp.s', file='code.bin',
                         rom_start=0x2F90, storage_vram=0x80002390, size=4,
                         sha256=reconstruction.sha256(payload.read_bytes()), logical_mappings=[])
            metadata = dict(config_path='config/rsp/units.json', inputs=[], tools=[], pieces=[piece])
            with patch.object(build_rsp, 'check_artifact'):
                artifact.write_text(json.dumps(metadata))
                result = reconstruction.load_rsp(reconstruction.Evidence(project), artifact, [])
                self.assertEqual(result[0][0], 0x2F90)
                self.assertEqual(result[0][2]['kind'], 'symbolic RSP source')
                piece['rom_start'] = 0x5000
                artifact.write_text(json.dumps(metadata))
                with self.assertRaisesRegex(ValueError, 'approved region'):
                    reconstruction.load_rsp(reconstruction.Evidence(project), artifact, [])
                piece.update(name='.data', rom_start=0x39170, storage_vram=0x80038570)
                artifact.write_text(json.dumps(metadata))
                with self.assertRaisesRegex(ValueError, 'classified data'):
                    reconstruction.load_rsp(reconstruction.Evidence(project), artifact, [])
                result = reconstruction.load_rsp(reconstruction.Evidence(project), artifact,
                                                  [(0x39170, 0x39590)])
                self.assertEqual(result[0][0], 0x39170)

    def test_directory_cannot_claim_payload_or_escape_exact_region(self):
        base = dict(version=1, kind='reconstructed archive-directory metadata', complete_rom=False,
                    complete_component=True, payload_included=False, decompiled_code_bytes=0,
                    rom_start=reconstruction.DIRECTORY_START, rom_end=reconstruction.DIRECTORY_END,
                    size=reconstruction.DIRECTORY_END - reconstruction.DIRECTORY_START,
                    records=reconstruction.DIRECTORY_RECORDS)
        with tempfile.TemporaryDirectory() as tmp:
            project = Path(tmp)
            artifact = project / 'directory.json'
            for changed in (dict(base, payload_included=True), dict(base, rom_end=0x2000000)):
                artifact.write_text(json.dumps(changed))
                with self.assertRaises(ValueError):
                    reconstruction.load_directory(reconstruction.Evidence(project), artifact)


if __name__ == '__main__':
    unittest.main()
