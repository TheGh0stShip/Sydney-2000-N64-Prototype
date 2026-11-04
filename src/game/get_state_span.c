#ifndef LEAF_NAME
#define LEAF_NAME getStateSpan
#endif

typedef unsigned int u32;
extern u32 stateSpanStart;
extern u32 stateSpanEnd;

u32 LEAF_NAME(void)
{
    return stateSpanEnd - stateSpanStart;
}
