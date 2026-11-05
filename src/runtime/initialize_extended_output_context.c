/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
extern void *func_800AB800(void *);
void *func_800ABA9C(unsigned int *context) { func_800AB800(context); context[5]=0; context[6]=0; return context; }
