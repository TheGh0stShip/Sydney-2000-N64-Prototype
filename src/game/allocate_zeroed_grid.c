#ifndef LEAF_NAME
#define LEAF_NAME allocateZeroedGrid
#endif

#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateBytes
#endif

#ifndef HANDLE_NAME
#define HANDLE_NAME memoryHandle
#endif

typedef signed int s32;
typedef unsigned char u8;

extern s32 HANDLE_NAME;
extern u8 *ALLOCATE_NAME(s32 handle, s32 size);

u8 *LEAF_NAME(s32 width, s32 height) {
    u8 *buffer;
    u8 *cursor;
    s32 remaining;

    if (HANDLE_NAME == -1) {
        return 0;
    }

    buffer = ALLOCATE_NAME(HANDLE_NAME, width * height);
    if (buffer == 0) {
        return 0;
    }

    remaining = width * height - 1;
    cursor = buffer;
    while (remaining != -1) {
        *cursor++ = 0;
        remaining--;
    }
    return buffer;
}
