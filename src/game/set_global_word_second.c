#ifndef LEAF_NAME
#define LEAF_NAME setGlobalWordSecond
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

void LEAF_NAME(int unused, int value) {
    register volatile int *page asm("$2") = (volatile int *)WORD_PAGE;

    asm volatile ("" : "=r" (page) : "0" (page));
    page[WORD_INDEX] = value;
}
