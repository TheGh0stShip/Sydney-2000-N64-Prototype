#ifndef LEAF_NAME
#define LEAF_NAME swapHalfword
#endif

void LEAF_NAME(unsigned short *value) {
    unsigned short current = *value;

    *value = (current >> 8) | (current << 8);
}
