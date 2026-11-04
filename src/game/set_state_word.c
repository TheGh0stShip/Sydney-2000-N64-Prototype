#ifndef LEAF_NAME
#define LEAF_NAME setStateWord
#endif

typedef unsigned int u32;
extern u32 stateWord;

void LEAF_NAME(u32 value)
{
    stateWord = value;
}
