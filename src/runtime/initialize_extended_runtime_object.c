/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void func_800B35F0(void *);
void func_800D6EA0(unsigned char *object) { func_800B35F0(object); *(unsigned int *)(object+0xE0)=0; *(unsigned int *)(object+0xDC)=0; *(unsigned int *)(object+0xE8)=0; }
