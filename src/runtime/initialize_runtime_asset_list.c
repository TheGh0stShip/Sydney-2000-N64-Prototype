/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[4]; unsigned short count, flags; } RuntimeList;
extern RuntimeList runtimeAssetList;
void func_800DCB54(void) { runtimeAssetList.words[0]=0; runtimeAssetList.words[1]=0; runtimeAssetList.words[2]=0; runtimeAssetList.words[3]=0; runtimeAssetList.count=0; runtimeAssetList.flags=0; }
