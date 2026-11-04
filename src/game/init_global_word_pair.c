#ifndef LEAF_NAME
#define LEAF_NAME initGlobalWordPair
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef FIRST_INDEX
#define FIRST_INDEX 0
#endif

#ifndef WORD_VALUE
#define WORD_VALUE 0
#endif

void LEAF_NAME(void) {
    register volatile int *page asm("$4") = (volatile int *)WORD_PAGE;
    register volatile int *pair asm("$3");
    register int value asm("$2");

    asm volatile ("" : "=r" (page) : "0" (page));
    pair = page + FIRST_INDEX;
    asm volatile ("" : "=r" (pair) : "0" (pair) : "memory");
    value = WORD_VALUE;
    asm volatile ("" : "=r" (value) : "0" (value));
    pair[1] = value;
    page[FIRST_INDEX] = value;
}
