# Upstream reuse

The closest reusable local project is the matching decompilation of *Nagano
Winter Olympics '98*. Its gap-free ROM accounting, per-unit manifests, exact
comparison gates, SDK headers, and toolchain layout are applicable here.

Game-code transfer is not assumed: Nagano is a Konami/IDO title, while this
prototype is an Attention to Detail title whose game code fingerprints as KMC
GCC. Any transferred source must independently reproduce the Sydney bytes.

The program contains Nintendo SDK 2.0J `libgultra_rom`, libmus, and both the
normal and compact audio libraries. Exact library signatures provide the first
reusable source queue. The original upstream copyright and license must remain
attached to imported source collections.
