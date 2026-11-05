/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[4]; unsigned short count; } OutputContext;
OutputContext *func_800AB800(OutputContext *context) { context->words[0]=0; context->words[1]=0; context->words[2]=0; context->words[3]=0; context->count=0; return context; }
