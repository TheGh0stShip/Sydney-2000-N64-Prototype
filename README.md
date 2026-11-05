# Sydney 2000 Nintendo 64 prototype

[![Code](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype)
[![Functions](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype)
[![Data](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype.svg?mode=shield&label=Data&measure=matched_data_percent)](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype)
[![Report](https://github.com/TheGh0stShip/Sydney-2000-N64-Prototype/actions/workflows/progress.yml/badge.svg)](https://github.com/TheGh0stShip/Sydney-2000-N64-Prototype/actions/workflows/progress.yml)

Matching decompilation of the unreleased North American prototype of
*Sydney 2000* for Nintendo 64.

The original game image is required but is not distributed by this project.
Clone submodules, place the image at `baserom.z64`, then run:

```sh
make setup
make verify
```

Accepted image:

- Size: 33,554,432 bytes
- SHA-1: `711c79790a713e65cc2ecb4857f35898b8e92985`
- Internal title: `Syd2k USA`
- Byte order: big-endian (`z64`)
- CIC: 6102

## Current map

The initial program is loaded from ROM `0x1000..0x69070` at
`0x80000400..0x80068470`. BSS occupies `0x80068470..0x800707D0`.
The current survey identifies 751 functions. The game and most libraries were
built with KMC GCC. Matching manifests cover 176,064 unique bytes of the 229,736-byte surveyed
resident text span (76.64%), including assembly units. Complete extents are
covered for 707 of 751 catalogued functions. Another 32 have reconstructed
bodies with uncovered zero-padding suffixes (312 bytes total), and 12 have
wholly unmatched bodies (36,888 bytes). The remaining 16,472 uncovered bytes
are outside catalogued function extents and include boot, RSP, and data spans
that need classification.

Earlier row-sum reporting double-counted 2,792 overlapping bytes and credited
function extents based only on their first byte. A subsequent source-padding
audit verified 728 compiler-emitted zero bytes, completing 77 extents without
adding function bodies. The current report counts the
union of matching ranges and requires complete extent coverage. These are
resident survey measures, not whole-game percentages: the overlay bank at ROM
`0x69070..0x127640` is outside the current function survey. Initialized-data
coverage is 5,820 unique bytes of 206,276 classified bytes (2.82%), recorded in
`config/matching_data.json`. `make data-ledger` rebuilds all matching units and
regenerates this ledger, including source-built data sections with frozen placements.
Reporting checks the recorded source, manifest,
normalizer, symbol-map, and header hashes; stale inputs fail with a request to
regenerate. `make data-ledger-check` checks freshness without the ROM or compiler.

`make runtime-survey` probes the original startup's loader arguments under the
integer MIPS interpreter with external helpers stubbed. It establishes the
startup runtime mapping from ROM `0x127640..0x1A3AB0` to
`0x80083D50..0x801001C0`. Resident direct calls and initializer-table pointers
seed 139 provisional runtime function candidates in
`config/survey/runtime_candidates.json`. `make runtime-survey-check` verifies
reproducibility. These candidates are outside the resident progress denominator
and receive no matching credit; boundaries and indirect-only entry points still
need review.

Exact startup-runtime C matches are recorded separately in
`config/runtime/matching_sn.tsv` and `config/runtime/matching_kmc.tsv`.
`make verify-runtime` compiles them with the startup mapping
`VRAM - ROM = 0x7FF5C710`; the resident delta is not reused. These matches do not
change resident coverage or imply that all runtime candidates or other overlay
banks are decompiled.
`src/game/initialize_debug_memory_regions.c` reconstructs `func_80028D54`; its
reviewed equivalent instruction transformations are checked by
`tools/verify_sn_normalized.py` before comparison against the original bytes.

The aligned heap allocator at `0x80037B30` has an exact C reconstruction in
`src/game/allocate_aligned_heap_block.c`. Run `make validate-aligned-heap` for
258 deterministic differential MIPS execution cases against the original. These
check return values and heap writes but do not establish byte matching or
physical hardware correctness.

`src/game/build_scene_light_commands.c` is an exact SN GCC reconstruction of
`func_800064D0`. `make validate-scene-lights` compares 400 deterministic MIPS
execution cases for empty, disabled, filtered, active, and mixed light groups
across three normal view indices plus an index-3 layout edge case. In the latter,
ambient writes overlap group counts; the validator preserves that original
behavior with a zero packed color. It compares generated commands, the display-list
cursor, ambient-color state, and input records against the ROM. All 620 text
bytes match without normalization.

`src/game/queue_render_resource_record.c` reconstructs the resource-record
queue at `0x8000C68C`. `make validate-render-queue` checks 400 differential MIPS
cases for special identifiers, immediate dispatch, identifier/resource
deduplication, free-record reuse, appending, range failures, and argument
forwarding. External helpers use identical deterministic stubs; the checks
cover queue logic and helper arguments, including o32 stack arguments, rather
than the helpers' implementations. All 696 text bytes match with SN GCC without
normalization.

## Progress trackers

[ByteMatch](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype)
consumes the `SYD2K_report` artifact published by every successful push to
`main`. The `us_report` artifact carries the same objdiff v2 report for
compatibility with established N64 decompilation project tooling. Run
`make report` to generate the report locally at `build/report.json` and the
remaining-range ledger at `build/decomp_gaps.json`. `make report-test` checks
coverage accounting, including overlap, partial extents, and segment clipping.
The progress workflow tests reporting and publishes these artifacts; it does
not compile the matching units.

The root [`.recomp.json`](.recomp.json) records the prototype identity and live
project links for recomp.fyi-compatible directories. Code, functions, and
initialized data remain separate measures; surveyed or merely identified bytes
are not credited as matching source.

Generated analysis lives in `config/`. It is evidence for source splitting and
symbol naming; addresses remain provisional until each unit is linked and
compared against the original image.

## Matching rule

A source unit is matched only when its rebuilt bytes compare equal with the
corresponding original range. `make verify` currently verifies the supplied original image and the individual
matching units; it does not link or hash a rebuilt image. Whole-image completion
still requires a source-linked ROM build and comparison with the expected SHA-1.

## Source-built resident pieces

`make source-link-plan` compiles the matching units and freezes reviewed section
placements, symbol addresses, ownership lengths, and input hashes in
`config/link_units.json`. Discovery uses the original ROM; `make source-pieces`
then builds from the frozen plan without reading it or inferring addresses.
`make source-image-verify` rebuilds and compares the resulting owned bytes against
the original only after compilation and relocation. `make source-image-test`
checks ownership, conflicting overlaps, stale plans, and strict symbol lookup.

The generated `build/source_image/resident.partial.bin` covers ROM
`0x1000..0x69070`. Its ownership bitmap and `source_image.json` distinguish
source-emitted zeros from unowned holes. Equal overlaps are permitted;
conflicting bytes fail. Unreferenced extra sections remain explicitly unowned.
This partial artifact excludes header/IPL3, runtime images, overlays, and assets;
it cannot satisfy whole-ROM completion.

After changing matched source, manifests, or normalizers, refresh the frozen plan
before the data ledger, then verify:

```sh
make source-link-plan
make data-ledger
make verify
make report
```

The data-ledger refresh also builds the frozen source pieces and compares them
against the ROM. It now includes two exact 32-byte initialized sections that the
older per-unit data comparison omitted.

The mapped-input function `func_80007384` now matches all 1,256 bytes with SN
GCC without normalization. The queued-texture reconstruction is still nonmatching.
`make validate-mapped-inputs` checks controller consumption, virtual callbacks,
pass accumulation, and event-ring updates against the original with deterministic
external helper stubs. `make validate-texture-sheets` checks emitted commands,
capacity exits, alpha modes, layer selection, and halfwidth queue-coordinate
mutation under the integer MIPS interpreter. These checks do not add matching
credit or establish physical hardware correctness.

## Archive directory reconstruction

`make archive-directory` packs all 6,955 archive-directory records from the typed
fields in `config/inventory/archive_records.tsv`, without reading the ROM. It
reconstructs 528,584 bytes at ROM `0x1A3AB0..0x224B78`, including big-endian count,
size/offset/auxiliary words and terminated 64-byte names. Record addresses,
32-bit widths, payload bounds and duplicate aliases are checked before output.

`make verify-archive-directory` compares the completed component against the
original afterward. `make archive-directory-test` checks packing and rejects
invalid metadata. Outputs live in `build/rom_components/file_directory.bin` and
its provenance JSON. No payloads or executable blobs are copied, and these
metadata bytes add no code-decompilation credit.
