/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void *func_800AB4B0(void *); extern void *func_800ABA9C(void *);
extern unsigned char runtimeOutputContext[]; extern unsigned char runtimeExtendedOutputContext[]; extern unsigned int runtimeOutputCookie;
void func_800B4718(void) { func_800AB4B0(runtimeOutputContext); func_800ABA9C(runtimeExtendedOutputContext); runtimeOutputCookie=1234; }
