/* Exact SN GCC 2.8 runtime-stage N64 MIPS/o32 reconstruction.
 * Keep the byte offset in v1 across the bound check so the compiler places
 * its scale in the original branch delay slot. The empty constraint emits
 * no instructions. The ordinary SN relocation path verifies all 60 bytes.
 */
typedef struct { unsigned int unused[3]; void *asset; } RuntimeAsset;
typedef char check_runtime_asset_size[sizeof(RuntimeAsset) == 16 ? 1 : -1];
extern RuntimeAsset runtimeAssets[];
extern unsigned char runtimeDefaultAsset[];
void *func_800D98FC(unsigned short index) {
    register unsigned int offset __asm__("$3") = index;
    void *asset;
    if (offset >= 0x3A5) return runtimeDefaultAsset;
    offset *= 16;
    __asm__("" : "+r"(offset));
    asset = ((RuntimeAsset *)((unsigned char *)runtimeAssets + offset))->asset;
    if (asset) return asset;
    return runtimeDefaultAsset;
}
