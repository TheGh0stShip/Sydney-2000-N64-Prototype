#ifndef LEAF_NAME
#define LEAF_NAME singleSquareRoot
#endif

float LEAF_NAME(float value) {
    return __builtin_sqrtf(value);
}

#ifdef TRAILING_PADDING
asm(".word 0\n.word 0");
#endif
