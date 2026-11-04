#ifndef LEAF_NAME
#define LEAF_NAME swapWord
#endif

void LEAF_NAME(unsigned int *value) {
    unsigned int current = *value;

    *value = (current >> 24) |
             (current << 24) |
             ((current & 0x0000FF00) << 8) |
             ((current >> 8) & 0x0000FF00);
}
