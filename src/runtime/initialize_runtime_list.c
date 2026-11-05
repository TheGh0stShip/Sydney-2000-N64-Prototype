/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[4]; unsigned short count, flags; } RuntimeList;
extern RuntimeList runtimeList;
void func_800B1880(void) { runtimeList.words[0]=0; runtimeList.words[1]=0; runtimeList.words[2]=0; runtimeList.words[3]=0; runtimeList.count=0; runtimeList.flags=0; }
