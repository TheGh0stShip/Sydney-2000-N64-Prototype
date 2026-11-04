#ifndef LEAF_NAME
#define LEAF_NAME selectRuntimeBuffer
#endif

typedef unsigned char u8;

extern u8 *bufferBoundary;
extern void *defaultBuffer;
extern void *upperBuffer;
extern void *lowerBuffer;
extern int boundaryState;

void *LEAF_NAME(void *address)
{
    if (bufferBoundary + 0xB8 < (u8 *)address) {
        if (boundaryState != 0) {
            boundaryState = 0;
            return upperBuffer;
        }
    } else if ((u8 *)address < bufferBoundary) {
        if (boundaryState != 0) {
            boundaryState = 0;
            return lowerBuffer;
        }
    } else {
        boundaryState = 1;
    }
    return defaultBuffer;
}
