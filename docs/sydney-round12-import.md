# Sydney 2000 overlay source import

This repository imported a conservative subset of the November 2026 Sydney 2000
handoff. The import is intentionally smaller than the handoff's headline count:
only functions that survived independent recompilation **and** replaced one
complete existing ownership row were admitted.

## Published result

| Result | Functions | Text bytes |
|---|---:|---:|
| Imported C | 88 | — |
| Imported C++ | 22 | — |
| Total imported | 110 | 52,256 |
| Handoff candidates not imported | 39 | — |
| Explicitly unverified candidates | 14 | — |

The per-function provenance is in `config/imported_round12.tsv`. Sources are in
`src/decompiled/`; ordinary C uses the SN manifests and C++ uses the
`custom:sydney_cxx` pipeline.

## Gates applied

1. Recompile each candidate with its recorded compiler recipe.
2. Compare its complete text bytes against the supplied prototype image.
3. Require an exact, whole-row replacement in the repository's existing ROM
   ownership manifests. Partial and shared-wrapper overlaps are withheld.
4. Regenerate all five frozen source-link plans.
5. Compose the complete ROM from source providers and extracted assets.
6. Compare all 33,554,432 bytes and the final SHA-1 against the accepted image.

The final image has SHA-1 `711c79790a713e65cc2ecb4857f35898b8e92985`,
with zero unowned bytes.

## Exclusions

- 13 candidates did not reproduce under independent replay.
- Four candidates relied on a looser address mask.
- 22 reproduced individually but overlap or split a larger existing wrapper;
  importing them without first preserving the wrapper's remaining ranges would
  create conflicting or missing ownership.
- 14 files in the handoff's unverified tier are not counted or published as
  matches.

This pass proves byte reproduction, not source polish. Some imported sources are
still machine-shaped and may use explicit register constraints. Structural type,
name, translation-unit, and portability cleanup remains separate work and must
preserve the byte gates above.
