PYTHON ?= python3
BASEROM ?= baserom.z64
BUILD_DIR := build
N64DK_ROOT ?= ../n64-decomp-kit
N64DK_PYTHON ?= $(N64DK_ROOT)/.venv/bin/python
N64DK_TOOLCHAIN ?= ../BattleTanx/.toolchain
N64DK := PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) -m n64dk

.PHONY: all setup verify verify-matching inventory inventory-check report report-check report-test data-ledger data-ledger-check validate-aligned-heap validate-scene-lights validate-render-queue runtime-survey runtime-survey-check overlay-survey overlay-survey-check verify-runtime verify-overlays runtime-link-plan runtime-pieces ceremony-link-plan ceremony-pieces closing-link-plan closing-pieces event-bank-link-plan event-bank-pieces residual-literals source-link-plan source-pieces resident-partial source-image-verify source-image-test validate-mapped-inputs validate-texture-sheets archive-directory archive-assets verify-archive-assets archive-assets-test verify-archive-directory archive-directory-test initialized-data initialized-data-verify initialized-data-test initialized-data-check reconstruction reconstruction-verify reconstructed-rom reconstruction-test validate-runtime-priority validate-runtime-memory rsp-tools rsp-pieces rsp-verify rsp-check rsp-test clean

all: setup

setup: $(BUILD_DIR)/main_segment.bin

$(BUILD_DIR)/main_segment.bin: $(BASEROM) tools/extract.py
	$(PYTHON) tools/extract.py $(BASEROM) $(BUILD_DIR)

verify: $(BASEROM) rsp-test rsp-verify report-test source-image-test initialized-data-test reconstruction-test initialized-data-verify archive-directory-test archive-assets-test verify-archive-directory verify-archive-assets data-ledger-check inventory-check verify-matching verify-runtime verify-overlays
	$(PYTHON) tools/verify.py $(BASEROM)

inventory: $(BASEROM)
	$(PYTHON) tools/inventory_rom.py $(BASEROM)

inventory-check: $(BASEROM)
	$(PYTHON) tools/inventory_rom.py $(BASEROM) --check

verify-matching: $(BASEROM)
	$(N64DK) match-batch config/matching_kmc.tsv=kmc+asn64 --project . -I tools/ultralib/include
	$(N64DK) match-batch config/matching_kmc_hook.tsv=kmc+hook --project . -I tools/ultralib/include --normalizer 'python3 tools/normalize_kmc_wrappers.py {extra} {input} {output}'
	$(N64DK) match-batch config/matching_kmc_builtin.tsv=kmc+builtin --project . -I tools/ultralib/include -I tools/ultralib/include/PR -I tools/ultralib/src/audio -I tools/ultralib/src/gu
	$(N64DK) match-batch config/matching_kmc_as.tsv=kmc+as --project . -I tools/ultralib/include -I tools/ultralib/include/PR -I tools/ultralib/include/compiler/gcc -I tools/ultralib/src/audio -I tools/ultralib/src/gu -I tools/battletanx_ga/src/libmus -I tools/battletanx_ga/src/n_audio -I tools/battletanx_ga/include
	$(N64DK) match-batch config/matching_ido.tsv=ido5.3 --project .
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/verify_ido_normalized.py config/matching_ido_normalized.tsv --rom $(BASEROM) --symbols config/survey/symbol_addrs.txt
	$(N64DK) match-batch config/matching_sn.tsv=sn --project .
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/verify_sn_normalized.py config/matching_sn_normalized.tsv --rom $(BASEROM) --symbols config/survey/symbol_addrs.txt
	$(N64DK) match-batch config/matching_as.tsv=as --project .

validate-aligned-heap: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/validate_aligned_heap.py

validate-scene-lights: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/validate_scene_lights.py

validate-render-queue: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/validate_render_queue.py

# Startup runtime image only; other overlay banks need their own mappings.
verify-runtime: $(BASEROM) runtime-survey-check
	$(N64DK) match-batch config/runtime/matching_sn.tsv=sn config/runtime/matching_sweep_sn.tsv=sn config/runtime/matching_kmc.tsv=kmc+as --project . --vram-delta 0x7FF5C710

verify-overlays: $(BASEROM) overlay-survey-check
	$(N64DK) match-batch config/overlay/ceremony/matching_sn.tsv=sn --project . --vram-delta 0x80007924
	$(N64DK) match-batch config/overlay/ceremony/matching_sweep_sn.tsv=sn --project . --vram-delta 0x80007924
	$(N64DK) match-batch config/overlay/closing/matching_sn.tsv=sn --project . --vram-delta 0x80002554
	$(N64DK) match-batch config/overlay/event_bank/matching_sn.tsv=sn --project . --vram-delta 0x80000000
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffdaa10_sn.tsv=sn --project . --vram-delta 0x7FFDAA10
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffd4240_sn.tsv=sn --project . --vram-delta 0x7FFD4240
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffc82f0_sn.tsv=sn --project . --vram-delta 0x7FFC82F0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffcf000_sn.tsv=sn --project . --vram-delta 0x7FFCF000
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffb55c0_sn.tsv=sn --project . --vram-delta 0x7FFB55C0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa1800_sn.tsv=sn --project . --vram-delta 0x7FFA1800
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff9d310_sn.tsv=sn --project . --vram-delta 0x7FF9D310
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff9e610_sn.tsv=sn --project . --vram-delta 0x7FF9E610
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffaba00_sn.tsv=sn --project . --vram-delta 0x7FFABA00
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa50e0_sn.tsv=sn --project . --vram-delta 0x7FFA50E0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffb3a00_sn.tsv=sn --project . --vram-delta 0x7FFB3A00
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffb7c80_sn.tsv=sn --project . --vram-delta 0x7FFB7C80
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffb9c30_sn.tsv=sn --project . --vram-delta 0x7FFB9C30
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffb1f60_sn.tsv=sn --project . --vram-delta 0x7FFB1F60
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa0490_sn.tsv=sn --project . --vram-delta 0x7FFA0490
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff5f9f0_sn.tsv=sn --project . --vram-delta 0x7FF5F9F0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffe0d50_sn.tsv=sn --project . --vram-delta 0x7FFE0D50
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffe7c90_sn.tsv=sn --project . --vram-delta 0x7FFE7C90
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff64fa0_sn.tsv=sn --project . --vram-delta 0x7FF64FA0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffc0e30_sn.tsv=sn --project . --vram-delta 0x7FFC0E30
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_800004f0_sn.tsv=sn --project . --vram-delta 0x800004F0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff73a50_sn.tsv=sn --project . --vram-delta 0x7FF73A50
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff8c7d0_sn.tsv=sn --project . --vram-delta 0x7FF8C7D0
	$(N64DK) match-batch config/overlay/ceremony/matching_delta_800061b0_sn.tsv=sn --project . --vram-delta 0x800061B0
	$(N64DK) match-batch config/overlay/ceremony/matching_delta_80007760_sn.tsv=sn --project . --vram-delta 0x80007760
	$(N64DK) match-batch config/overlay/closing/matching_delta_80002550_sn.tsv=sn --project . --vram-delta 0x80002550
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff5c700_sn.tsv=sn --project . --vram-delta 0x7FF5C700
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff60e80_sn.tsv=sn --project . --vram-delta 0x7FF60E80
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff62790_sn.tsv=sn --project . --vram-delta 0x7FF62790
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff64980_sn.tsv=sn --project . --vram-delta 0x7FF64980
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff65f70_sn.tsv=sn --project . --vram-delta 0x7FF65F70
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff67150_sn.tsv=sn --project . --vram-delta 0x7FF67150
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff69ac0_sn.tsv=sn --project . --vram-delta 0x7FF69AC0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff6b310_sn.tsv=sn --project . --vram-delta 0x7FF6B310
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff703c0_sn.tsv=sn --project . --vram-delta 0x7FF703C0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff76df0_sn.tsv=sn --project . --vram-delta 0x7FF76DF0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff79e60_sn.tsv=sn --project . --vram-delta 0x7FF79E60
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff7eec0_sn.tsv=sn --project . --vram-delta 0x7FF7EEC0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff81f10_sn.tsv=sn --project . --vram-delta 0x7FF81F10
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff85a80_sn.tsv=sn --project . --vram-delta 0x7FF85A80
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff89370_sn.tsv=sn --project . --vram-delta 0x7FF89370
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff91b70_sn.tsv=sn --project . --vram-delta 0x7FF91B70
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff94610_sn.tsv=sn --project . --vram-delta 0x7FF94610
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff95340_sn.tsv=sn --project . --vram-delta 0x7FF95340
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ff9b490_sn.tsv=sn --project . --vram-delta 0x7FF9B490
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa38e0_sn.tsv=sn --project . --vram-delta 0x7FFA38E0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa7710_sn.tsv=sn --project . --vram-delta 0x7FFA7710
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa8800_sn.tsv=sn --project . --vram-delta 0x7FFA8800
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffa9ce0_sn.tsv=sn --project . --vram-delta 0x7FFA9CE0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffab940_sn.tsv=sn --project . --vram-delta 0x7FFAB940
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffaecb0_sn.tsv=sn --project . --vram-delta 0x7FFAECB0
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7ffeec30_sn.tsv=sn --project . --vram-delta 0x7FFEEC30
	$(N64DK) match-batch config/overlay/event_bank/matching_delta_7fff6d70_sn.tsv=sn --project . --vram-delta 0x7FFF6D70

rsp-tools:
	bash config/rsp/bootstrap_armips.sh

rsp-pieces:
	$(PYTHON) tools/build_rsp.py build

rsp-verify: $(BASEROM)
	$(PYTHON) tools/build_rsp.py build --verify-rom $(BASEROM)

rsp-check:
	$(PYTHON) tools/build_rsp.py check

rsp-test:
	$(PYTHON) tools/test_rsp.py

archive-directory:
	$(PYTHON) tools/build_archive_directory.py

verify-archive-directory: $(BASEROM)
	$(PYTHON) tools/build_archive_directory.py --verify-rom $(BASEROM)

archive-directory-test:
	$(PYTHON) tools/test_archive_directory.py

archive-assets: $(BASEROM)
	$(PYTHON) tools/build_archive_payload.py extract --rom $(BASEROM)
	$(PYTHON) tools/build_archive_payload.py build

verify-archive-assets: archive-assets
	$(PYTHON) tools/build_archive_payload.py build --verify-rom $(BASEROM)

archive-assets-test:
	$(PYTHON) tools/test_archive_payload.py

residual-literals: config/residual_literals.json
	$(PYTHON) tools/build_residual_literals.py build

initialized-data:
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_initialized_data.py build

initialized-data-verify: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_initialized_data.py build --verify-rom $(BASEROM)

initialized-data-check:
	$(PYTHON) tools/build_initialized_data.py check

initialized-data-test:
	$(PYTHON) tools/test_initialized_data.py

# Composition reads source artifacts only; verification may read ROM afterward.
reconstruction: source-pieces runtime-pieces ceremony-pieces closing-pieces event-bank-pieces initialized-data rsp-pieces archive-directory archive-assets residual-literals
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/compose_reconstruction.py

reconstruction-verify: source-pieces runtime-pieces ceremony-pieces closing-pieces event-bank-pieces initialized-data rsp-pieces archive-directory archive-assets residual-literals $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/compose_reconstruction.py --verify-rom $(BASEROM)

# This must fail while any ROM byte is unowned or the final SHA-1 differs.
reconstructed-rom: source-pieces runtime-pieces ceremony-pieces closing-pieces event-bank-pieces initialized-data rsp-pieces archive-directory archive-assets residual-literals
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/compose_reconstruction.py --require-complete

reconstruction-test:
	$(PYTHON) tools/test_reconstruction.py

validate-runtime-memory: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/validate_runtime_memory.py --rom $(BASEROM)

validate-runtime-priority: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/validate_runtime_priority.py --rom $(BASEROM)

source-link-plan: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py discover --rom $(BASEROM)

source-pieces: config/link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build

runtime-link-plan: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py discover --segment runtime --rom $(BASEROM)

runtime-pieces: config/runtime_link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build --segment runtime

ceremony-link-plan: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py discover --segment ceremony --rom $(BASEROM)

ceremony-pieces: config/overlay_link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build --segment ceremony

closing-link-plan: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py discover --segment closing --rom $(BASEROM)

closing-pieces: config/closing_link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build --segment closing

event-bank-link-plan: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py discover --segment event_bank --rom $(BASEROM)

event-bank-pieces: config/event_bank_link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build --segment event_bank

resident-partial: source-pieces

source-image-verify: $(BASEROM) config/link_units.json
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_source_image.py build --verify-rom $(BASEROM)

source-image-test:
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/test_source_image.py

validate-mapped-inputs: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/validate_mapped_inputs.py

validate-texture-sheets: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/validate_queued_texture_sheets.py

runtime-survey: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/survey_runtime_image.py --rom $(BASEROM)

runtime-survey-check: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/survey_runtime_image.py --rom $(BASEROM) --check

overlay-survey: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/survey_overlay_bank.py --rom $(BASEROM)

overlay-survey-check: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/survey_overlay_bank.py --rom $(BASEROM) --check

data-ledger: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/generate_data_ledger.py --rom $(BASEROM)

data-ledger-check:
	$(PYTHON) -c "from tools.generate_decomp_report import load_data_measures; load_data_measures()"

report-test:
	$(PYTHON) tools/test_decomp_report.py

report:
	$(PYTHON) tools/generate_decomp_report.py

report-check: report-test report
	git diff --exit-code -- build/report.json

clean:
	rm -rf $(BUILD_DIR)
