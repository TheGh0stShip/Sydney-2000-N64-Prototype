/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[4]; unsigned short count, flags; } RuntimeList;
extern RuntimeList runtimeFreeList;
void func_800B3144(void) { runtimeFreeList.words[0]=0; runtimeFreeList.words[1]=0; runtimeFreeList.words[2]=0; runtimeFreeList.words[3]=0; runtimeFreeList.count=0; runtimeFreeList.flags=0; }
