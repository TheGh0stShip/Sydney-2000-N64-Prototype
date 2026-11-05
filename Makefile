PYTHON ?= python3
BASEROM ?= baserom.z64
BUILD_DIR := build
N64DK_ROOT ?= ../n64-decomp-kit
N64DK_PYTHON ?= $(N64DK_ROOT)/.venv/bin/python
N64DK_TOOLCHAIN ?= ../BattleTanx/.toolchain
N64DK := PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) -m n64dk

.PHONY: all setup verify verify-matching inventory inventory-check report report-check report-test data-ledger data-ledger-check validate-aligned-heap validate-scene-lights validate-render-queue runtime-survey runtime-survey-check overlay-survey overlay-survey-check verify-runtime runtime-link-plan runtime-pieces source-link-plan source-pieces resident-partial source-image-verify source-image-test validate-mapped-inputs validate-texture-sheets archive-directory verify-archive-directory archive-directory-test initialized-data initialized-data-verify initialized-data-test initialized-data-check reconstruction reconstruction-verify reconstructed-rom reconstruction-test validate-runtime-priority validate-runtime-memory rsp-tools rsp-pieces rsp-verify rsp-check rsp-test clean

all: setup

setup: $(BUILD_DIR)/main_segment.bin

$(BUILD_DIR)/main_segment.bin: $(BASEROM) tools/extract.py
	$(PYTHON) tools/extract.py $(BASEROM) $(BUILD_DIR)

verify: $(BASEROM) rsp-test rsp-verify report-test source-image-test initialized-data-test reconstruction-test initialized-data-verify archive-directory-test verify-archive-directory data-ledger-check inventory-check verify-matching verify-runtime
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
	$(N64DK) match-batch config/runtime/matching_sn.tsv=sn config/runtime/matching_kmc.tsv=kmc+as --project . --vram-delta 0x7FF5C710

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

initialized-data:
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_initialized_data.py build

initialized-data-verify: $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) tools/build_initialized_data.py build --verify-rom $(BASEROM)

initialized-data-check:
	$(PYTHON) tools/build_initialized_data.py check

initialized-data-test:
	$(PYTHON) tools/test_initialized_data.py

# Composition reads source artifacts only; verification may read ROM afterward.
reconstruction: source-pieces runtime-pieces initialized-data rsp-pieces archive-directory
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/compose_reconstruction.py

reconstruction-verify: source-pieces runtime-pieces initialized-data rsp-pieces archive-directory $(BASEROM)
	PYTHONPATH=$(abspath $(N64DK_ROOT)) $(N64DK_PYTHON) tools/compose_reconstruction.py --verify-rom $(BASEROM)

# This must fail while any ROM byte is unowned or the final SHA-1 differs.
reconstructed-rom: source-pieces runtime-pieces initialized-data rsp-pieces archive-directory
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
