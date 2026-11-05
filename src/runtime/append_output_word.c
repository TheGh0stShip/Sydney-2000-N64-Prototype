/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct { unsigned int unused[3]; unsigned int *cursor; } OutputContext;
void func_800AB66C(OutputContext *context, unsigned int value) { *context->cursor = value; context->cursor++; }
