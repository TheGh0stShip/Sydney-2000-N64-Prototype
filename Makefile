PYTHON ?= python3
BASEROM ?= baserom.z64
BUILD_DIR := build
N64DK_ROOT ?= ../n64-decomp-kit
N64DK_PYTHON ?= $(N64DK_ROOT)/.venv/bin/python
N64DK_TOOLCHAIN ?= ../BattleTanx/.toolchain
N64DK := PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) -m n64dk

.PHONY: all setup verify verify-matching clean

all: setup

setup: $(BUILD_DIR)/main_segment.bin

$(BUILD_DIR)/main_segment.bin: $(BASEROM) tools/extract.py
	$(PYTHON) tools/extract.py $(BASEROM) $(BUILD_DIR)

verify: $(BASEROM) verify-matching
	$(PYTHON) tools/verify.py $(BASEROM)

verify-matching: $(BASEROM)
	$(N64DK) match-batch config/matching_kmc.tsv=kmc+asn64 --project . -I tools/ultralib/include
	$(N64DK) match-batch config/matching_kmc_builtin.tsv=kmc+builtin --project . -I tools/ultralib/include -I tools/ultralib/include/PR -I tools/ultralib/src/audio -I tools/ultralib/src/gu
	$(N64DK) match-batch config/matching_kmc_as.tsv=kmc+as --project . -I tools/ultralib/include -I tools/ultralib/include/PR -I tools/ultralib/include/compiler/gcc -I tools/ultralib/src/audio -I tools/ultralib/src/gu -I tools/battletanx_ga/src/libmus -I tools/battletanx_ga/include

clean:
	rm -rf $(BUILD_DIR)
