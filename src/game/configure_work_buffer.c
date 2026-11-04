#ifndef LEAF_NAME
#define LEAF_NAME configureWorkBuffer
#endif

#ifndef CONFIGURE_NAME
#define CONFIGURE_NAME configureBuffer
#endif

#ifndef CALLBACK_NAME
#define CALLBACK_NAME bufferCallback
#endif

#ifndef MODE_NAME
#define MODE_NAME mode
#endif

#ifndef CONTEXT_NAME
#define CONTEXT_NAME context
#endif

#ifndef BUFFER_NAME
#define BUFFER_NAME buffer
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 MODE_NAME;
extern u8 CONTEXT_NAME[];
extern u8 BUFFER_NAME[];

extern void CALLBACK_NAME(void);
extern void CONFIGURE_NAME(void *context, void *buffer, u32 size,
                           void (*callback)(void));

void LEAF_NAME(void) {
    if (MODE_NAME != 0) {
        register u8 *limitBase __asm__("$3") = (u8 *)0x80040000;

        __asm__("" : "=r"(limitBase) : "0"(limitBase));
        *(u32 *)(limitBase + 0x7988) = 128;
        CONFIGURE_NAME(CONTEXT_NAME, BUFFER_NAME, 0x1800, CALLBACK_NAME);
    } else {
        register u8 *limitBase __asm__("$3") = (u8 *)0x80040000;

        __asm__("" : "=r"(limitBase) : "0"(limitBase));
        *(u32 *)(limitBase + 0x7988) = 10;
        CONFIGURE_NAME(CONTEXT_NAME, BUFFER_NAME, 0x240, CALLBACK_NAME);
    }
}
