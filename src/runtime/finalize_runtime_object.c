/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern unsigned char runtimeObjectVtable[]; extern void func_80004380(void *);
void func_800AC3A4(unsigned char *object,unsigned int flags) { *(void **)(object+0xB4)=runtimeObjectVtable; if(flags&1)func_80004380(object); }
