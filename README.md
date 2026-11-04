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
Automated analysis currently identifies 761 functions, including 261 Nintendo
SDK functions. The game and most libraries were built with KMC GCC. Exact C
matching currently covers 576 functions, 92,168 code bytes, and 3,480 initialized
data bytes.

## Progress trackers

[ByteMatch](https://bytematch.dev/TheGh0stShip/Sydney-2000-N64-Prototype)
consumes the `SYD2K_report` artifact published by every successful push to
`main`. The `us_report` artifact carries the same objdiff v2 report for
compatibility with established N64 decompilation project tooling. Run
`make report` to generate the report locally at `build/report.json`.

The root [`.recomp.json`](.recomp.json) records the prototype identity and live
project links for recomp.fyi-compatible directories. Code, functions, and
initialized data remain separate measures; surveyed or merely identified bytes
are not credited as matching source.

Generated analysis lives in `config/`. It is evidence for source splitting and
symbol naming; addresses remain provisional until each unit is linked and
compared against the original image.

## Matching rule

A source unit is matched only when its rebuilt bytes compare equal with the
corresponding original range. Whole-image completion requires `make verify` to
report the expected SHA-1 for the rebuilt image.
