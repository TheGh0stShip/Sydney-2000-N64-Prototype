#ifndef LEAF_NAME
#define LEAF_NAME createStateSpan
#endif
#ifndef CREATE_NAME
#define CREATE_NAME createRuntimeSpan
#endif

typedef signed int s32;
extern s32 stateSpanStart;
extern void CREATE_NAME(s32, s32, s32 *, s32, s32);

void LEAF_NAME(s32 value)
{
    CREATE_NAME(0, 0, &stateSpanStart, 1, value);
}
