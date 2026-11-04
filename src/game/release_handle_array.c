#ifndef LEAF_NAME
#define LEAF_NAME releaseHandleArray
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

extern unsigned char CONTEXT_NAME[];
extern u32 HANDLES_NAME[4];
extern void RELEASE_NAME(void *context, u32 *handle);

void LEAF_NAME(void) {
    register int index __asm__("$17");
    register u8 *contextBase __asm__("$18");
    register u8 *handlesBase __asm__("$2");
    register u32 *handle __asm__("$16");

    contextBase = (u8 *)0x800F0000;
    handlesBase = (u8 *)0x80060000;
    __asm__("" : "=r"(handlesBase) : "0"(handlesBase));
    handle = (u32 *)(handlesBase + 0x24B4);
    __asm__("" : "=r"(contextBase), "=r"(handle)
            : "0"(contextBase), "1"(handle));
    for (index = 0; index < 4; index++) {
        if (*handle != 0) {
            RELEASE_NAME(contextBase + 0x2758, handle);
            *handle = 0;
        }
        handle++;
    }
}
