#ifndef LEAF_NAME
#define LEAF_NAME clearTwoGlobalWords
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef FIRST_INDEX
#define FIRST_INDEX 0
#endif

#ifndef SECOND_INDEX
#define SECOND_INDEX 1
#endif

void LEAF_NAME(void) {
    register volatile int *page asm("$2") = (volatile int *)WORD_PAGE;

    asm volatile ("" : "=r" (page) : "0" (page));
    page[FIRST_INDEX] = 0;
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[SECOND_INDEX] = 0;
}
