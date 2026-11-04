#ifndef LEAF_NAME
#define LEAF_NAME getFunctionAddress
#endif
#ifndef TARGET_NAME
#define TARGET_NAME targetFunction
#endif

extern void TARGET_NAME(void);

void *LEAF_NAME(void)
{
    return TARGET_NAME;
}
