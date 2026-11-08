typedef struct { unsigned int unused[3]; void *asset; } RuntimeAsset;
extern RuntimeAsset runtimeAssets[];
extern unsigned char runtimeDefaultAsset[];

void *func_800D98FC(unsigned short index)
{
    unsigned int i = index;
    RuntimeAsset *p;
    void *asset;
    if (i >= 0x3A5) return runtimeDefaultAsset;
    p = &runtimeAssets[i];
    asset = p->asset;
    if (asset) return asset;
    return runtimeDefaultAsset;
}
