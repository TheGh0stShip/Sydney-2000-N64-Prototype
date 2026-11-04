#ifndef LEAF_NAME
#define LEAF_NAME readWordAddress
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

int LEAF_NAME(void) {
    volatile int *page = (volatile int *)WORD_PAGE;

    return page[WORD_INDEX];
}
