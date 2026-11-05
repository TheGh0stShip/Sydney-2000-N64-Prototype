/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern unsigned char descriptorRefreshState;
void func_800BC3C4(unsigned char value) { descriptorRefreshState = value; }
