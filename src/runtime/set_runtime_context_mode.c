/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern unsigned short runtimeContextMode;
void func_800B3208(unsigned short value) { runtimeContextMode = value; }
