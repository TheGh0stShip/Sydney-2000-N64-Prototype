/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern unsigned char descriptorRefreshState;
unsigned int func_800BC3B0(void) { unsigned int value = descriptorRefreshState; value++; descriptorRefreshState = value; return value; }
