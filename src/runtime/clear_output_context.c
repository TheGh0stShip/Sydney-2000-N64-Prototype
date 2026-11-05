/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int words[3]; unsigned short count, unused, flags; } OutputContext;
OutputContext *func_800AB4B0(OutputContext *context) { context->words[0]=0; context->words[1]=0; context->words[2]=0; context->count=0; context->flags=0; return context; }
