/* Runtime-stage C reconstruction; no matching credit until verified manifest entry. */
typedef unsigned short u16; typedef unsigned int u32; typedef unsigned char u8;
typedef struct { u8 *records; u32 unused; u8 **pointers; u16 unknown, count; } OutputContext;
void func_800AB534(OutputContext *context) { u16 index; u8 **cursor=context->pointers; for(index=0;index<context->count;index++) { *cursor++ = context->records + index * 24; } }
