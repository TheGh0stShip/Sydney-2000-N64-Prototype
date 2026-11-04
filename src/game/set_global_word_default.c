#ifndef LEAF_NAME
#define LEAF_NAME setGlobalWordDefault
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

void LEAF_NAME(int value) {
    volatile int *page = (volatile int *)WORD_PAGE;

    page[WORD_INDEX] = value;
}
