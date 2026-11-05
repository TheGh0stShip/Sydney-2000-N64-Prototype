/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void func_8001D964(void *);
void func_800A3218(unsigned char *state) { func_8001D964(state); *(unsigned int *)(state+0x28)=0; }
