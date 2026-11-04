#ifndef LEAF_NAME
#define LEAF_NAME getMaxPairValue
#endif
#ifndef VALUE_INDEX
#define VALUE_INDEX 0
#endif

typedef signed int s32;
typedef struct Pair {
    s32 values[2];
} Pair;

extern Pair *pairs[];

s32 LEAF_NAME(void)
{
    s32 maximum = 0;
    s32 index;

    for (index = 0; pairs[index] != 0; index++) {
        if (maximum < pairs[index]->values[VALUE_INDEX])
            maximum = pairs[index]->values[VALUE_INDEX];
    }
    return maximum;
}
