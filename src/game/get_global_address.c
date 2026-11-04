#ifndef LEAF_NAME
#define LEAF_NAME getGlobalAddress
#endif

extern char globalObject[];

void *LEAF_NAME(void)
{
    return globalObject;
}
