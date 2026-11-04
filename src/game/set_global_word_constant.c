#ifndef LEAF_NAME
#define LEAF_NAME setGlobalWordConstant
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

#ifndef WORD_VALUE
#define WORD_VALUE 0
#endif

void LEAF_NAME(void) {
    register volatile int *page asm("$3") = (volatile int *)WORD_PAGE;
    register int value asm("$2") = WORD_VALUE;

    asm volatile ("" : "=r" (page), "=r" (value) : "0" (page), "1" (value));
    page[WORD_INDEX] = value;
}
