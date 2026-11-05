/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void func_800AED48(void *);
void *func_800AED80(unsigned int *object) { object[3]=0; object[1]=0; object[2]=0; func_800AED48(object); return object; }
