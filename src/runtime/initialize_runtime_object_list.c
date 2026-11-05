/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[4]; unsigned short count, flags; } RuntimeList;
extern RuntimeList runtimeObjectList;
void func_800DAF88(void) { runtimeObjectList.words[0]=0; runtimeObjectList.words[1]=0; runtimeObjectList.words[2]=0; runtimeObjectList.words[3]=0; runtimeObjectList.count=0; runtimeObjectList.flags=0; }
