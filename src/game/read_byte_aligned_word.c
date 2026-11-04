#ifndef LEAF_NAME
#define LEAF_NAME readByteAlignedWord
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

extern unsigned int HELPER_NAME(void *address);

unsigned int LEAF_NAME(void *address) {
    unsigned int shift = (~(unsigned int)address & 3) << 3;
    unsigned int *word = (unsigned int *)((unsigned int)address & ~3);

    return (HELPER_NAME(word) >> shift) & 0xFF;
}
