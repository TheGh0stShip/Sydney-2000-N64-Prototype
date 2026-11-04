#ifndef LEAF_NAME
#define LEAF_NAME allocateHandlePair
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocate
#endif

#ifndef CONTEXT_NAME
#define CONTEXT_NAME allocationContext
#endif

#ifndef HANDLES_NAME
#define HANDLES_NAME handles
#endif

#ifndef COUNT_NAME
#define COUNT_NAME handleCount
#endif

#ifndef TAG_NAME
#define TAG_NAME allocationTag
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern void ALLOCATE_NAME(void *context, void **output, u32 size, char *tag);

void LEAF_NAME(u32 count) {
    register u32 countValue __asm__("$3") = count;
    register void **handles __asm__("$17") = (void **)0x8005AA90;
    register u8 *contextBase __asm__("$19") = (u8 *)0x80060000;
    register char *tag __asm__("$16") = (char *)0x80000C5C;
    register u8 *countBase __asm__("$18") = (u8 *)0x80060000;

    __asm__("" : "=r"(countValue), "=r"(handles), "=r"(contextBase),
            "=r"(tag), "=r"(countBase)
            : "0"(countValue), "1"(handles), "2"(contextBase),
              "3"(tag), "4"(countBase));
    handles[1] = 0;
    handles[0] = 0;
    *(u32 *)(countBase - 0x535C) = countValue;
    ALLOCATE_NAME(*(void **)(contextBase - 0x5618), &handles[1], countValue << 3, tag);
    ALLOCATE_NAME(*(void **)(contextBase - 0x5618), &handles[0],
                  *(u32 *)(countBase - 0x535C) << 3, tag);
}
