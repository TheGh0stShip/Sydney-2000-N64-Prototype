#ifndef LEAF_NAME
#define LEAF_NAME releaseTwoOptionalHandles
#endif

#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif

#ifndef CONTEXT_NAME
#define CONTEXT_NAME context
#endif

#ifndef HANDLES_NAME
#define HANDLES_NAME handles
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern void *CONTEXT_NAME;
extern u32 HANDLES_NAME[2];
extern void RELEASE_NAME(void *context, u32 *handle);

void LEAF_NAME(void) {
    register u8 *globalBase __asm__("$2");
    register u32 firstHandle __asm__("$3");
    register u32 *handles __asm__("$16");

    globalBase = (u8 *)0x80060000;
    __asm__("" : "=r"(globalBase) : "0"(globalBase));
    firstHandle = *(u32 *)(globalBase - 0x5570);
    handles = (u32 *)(globalBase - 0x5570);
    __asm__("" : "=r"(firstHandle), "=r"(handles)
            : "0"(firstHandle), "1"(handles));
    if (firstHandle != 0) {
        globalBase = (u8 *)0x80060000;
        __asm__("" : "=r"(globalBase) : "0"(globalBase));
        RELEASE_NAME(*(void **)(globalBase - 0x5618), &handles[0]);
    }
    if (handles[1] != 0) {
        globalBase = (u8 *)0x80060000;
        __asm__("" : "=r"(globalBase) : "0"(globalBase));
        RELEASE_NAME(*(void **)(globalBase - 0x5618), &handles[1]);
    }
}
