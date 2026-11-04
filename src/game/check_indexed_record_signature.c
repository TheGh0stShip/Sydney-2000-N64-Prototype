#ifndef LEAF_NAME
#define LEAF_NAME checkIndexedRecordSignature
#endif

#ifndef COPY_NAME
#define COPY_NAME copyRecord
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

extern void COPY_NAME(void *source, void *destination, u32 length);
#ifdef RESOLVE_NAME
extern s32 RESOLVE_NAME(void *first, void *second, u32 mode);
#endif

s32 LEAF_NAME(void *first, void *second) {
    s32 index;
    s32 result = -1;

#ifdef RESOLVE_NAME
    index = RESOLVE_NAME(first, second, 0);
#else
    index = (s32)second;
#endif
    if (index != -1) {
        struct {
            u8 padding[16];
            u32 signature;
        } local;
        register u8 *buffer __asm__("$16") = (u8 *)0x80040000 + 0x36C0;

        __asm__("" : "=r"(buffer) : "0"(buffer));
        COPY_NAME(*(u8 **)0x80043674 + 4 + (u32)index * 76,
                  buffer, 76);
        COPY_NAME((u8 *)*(u32 *)0x80043684 + *(u32 *)(buffer + 4),
                  &local.signature, sizeof(local.signature));
        result = local.signature == 0x30325447;
    }

    return result;
}
