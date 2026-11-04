PYTHON ?= python3
BASEROM ?= baserom.z64
BUILD_DIR := build

.PHONY: all setup verify clean

all: setup

setup: $(BUILD_DIR)/main_segment.bin

$(BUILD_DIR)/main_segment.bin: $(BASEROM) tools/extract.py
	$(PYTHON) tools/extract.py $(BASEROM) $(BUILD_DIR)

verify: $(BASEROM)
	$(PYTHON) tools/verify.py $(BASEROM)

clean:
	rm -rf $(BUILD_DIR)
