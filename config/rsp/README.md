The provider assembles big-endian RSP scalar/vector programs. RSP IMEM/DMEM addresses in `units.json` describe execution; `storage_vram` describes the separate CPU-visible resident storage. CPU o32 function counts do not apply to these images.

Initialize the pinned graphics source dependency, build the separately cached assembler, then build the source provider:

```sh
git submodule update --init tools/f3dex2
bash config/rsp/bootstrap_armips.sh
python3 tools/build_rsp.py build
python3 tools/build_rsp.py build --verify-rom baserom.z64
python3 tools/build_rsp.py check
python3 -m unittest discover -s tools -p test_rsp.py
```

`ARMIPS` or `--armips` overrides the local `.toolchain/armips/armips` cache. The bootstrap verifies both pinned source archives and builds with CMake Release, tests disabled. Its commit and flags are recorded separately from the actual executable hash; a supplied executable's origin is never inferred merely from its filename.

The four reviewed outputs own 9,440 bytes:

| Source output | ROM interval (exclusive end) | Bytes |
| --- | --- | ---: |
| rspboot | `2EC0..2F90` | 208 |
| F3DEX FIFO 2.08 instructions and overlays | `2F90..4320` | 5008 |
| n_aspMain audio instructions | `4320..4F80` | 3168 |
| F3DEX initial DMEM data | `39170..39590` | 1056 |

The boot recipe inserts an explicit `.align 16` before the symbolic source's single `.close`: 204 instruction bytes and four assembler-generated alignment zeros. Audio already includes 12 source padding bytes. F3DEX's 5,008-byte file includes overlays; it is not loaded as one contiguous 4 KiB IMEM image. The manifest records the initial DMA and four overlay mappings explicitly.

Build never opens ROM. An optional comparison occurs only after source assembly, reviewed digest/size validation, freshness and overlap checks. No original binary instruction image is a source input. Outputs are partial provider artifacts and cannot establish a complete ROM.
