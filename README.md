# Sydney 2000 Nintendo 64 prototype

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
matching currently covers 133 functions, 22,700 code bytes, and 604 initialized
data bytes.

Generated analysis lives in `config/`. It is evidence for source splitting and
symbol naming; addresses remain provisional until each unit is linked and
compared against the original image.

## Matching rule

A source unit is matched only when its rebuilt bytes compare equal with the
corresponding original range. Whole-image completion requires `make verify` to
report the expected SHA-1 for the rebuilt image.
