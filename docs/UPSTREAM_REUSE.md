# Upstream reuse survey

A 35-round public-source survey was completed on 2026-11-04. Candidate code
must still compile with Sydney's identified toolchain and compare equal to the
prototype bytes before it enters a matching manifest.

## Priority sources

1. [BattleTanx: Global Assault](https://github.com/TheGh0stShip/BattleTanx-Global-Assault)
   is the strongest donor. It uses the same KMC GCC 2.7.2 and libmus/n_audio
   lineage, has complete byte-verified library source, and is pinned as the
   `tools/battletanx_ga` submodule.
2. [Dr. Mario 64](https://github.com/AngheloAlf/drmario64) preserves the full
   Software Creations libmus 3.14 source tree. It is the best semantic and type
   reference when the BattleTanx source has been split or adapted.
3. [Mario Golf 64](https://github.com/monde-lointain/mariogolf64) uses KMC GCC
   2.7.2 and contains matching work for the n_audio libmus variant. Its symbol
   catalogue is useful for naming the scheduler, heap, DMA, and synthesis
   interfaces.
4. [Frogger 2 N64](https://github.com/HighwayFrogs/frogger2-n64) preserves
   original cancelled-port source and identifies its audio library as libmus
   3.14. Its SN GCC 2.8.1 build is not a direct code-generation donor, but its
   headers and API types are authoritative version evidence.
5. [THPS64](https://github.com/andrewnakas/thps64) is a broad late-era N64
   reference with Sound Tools assets and runtime work. Use it mainly for bank,
   cue, and asset-format comparisons.
6. [Nagano Winter Olympics '98](https://github.com/TheGh0stShip/Nagano-Winter-Olympics-98-N64)
   remains useful for generic game helpers and structural comparisons. A
   normalized whole-program scan found exact SDK and assembly leaf routines,
   but no proven game-engine C donor yet. Nagano was developed by Konami rather
   than Sydney developer Attention to Detail, so its measured overlap is lower
   than initially expected.

## Shared foundations

- [ultralib](https://github.com/decompals/ultralib) and
  [libreultra](https://github.com/n64decomp/libreultra) are the primary SDK
  references. Sydney's exact SDK revision and per-file optimization level must
  be checked rather than assumed.
- [decompals/mips-gcc-2.7.2](https://github.com/decompals/mips-gcc-2.7.2)
  documents and preserves the KMC compiler family used by Sydney.
- Public project directories are discovery aids, not source authority. The
  repository and its byte-verification evidence take precedence.

## Reuse procedure

For each unmatched span:

1. Search the priority sources by known API name, instruction shape, constants,
   calls, and exact compiled size.
2. Prefer the original translation unit unchanged. If Sydney reordered
   functions, create the smallest local unit containing the upstream bodies in
   Sydney order.
3. Map only symbols proven by Sydney disassembly or an already matched unit.
4. Compile with the identified KMC flags and the correct assembler lane.
5. Add the unit only after its relocated text and owned data compare exactly.
6. Run the complete ROM verifier before committing.
