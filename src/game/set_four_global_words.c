#ifndef LEAF_NAME
#define LEAF_NAME setFourGlobalWords
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

#ifndef THIRD_INDEX
#define THIRD_INDEX 2
#endif

#ifndef FOURTH_INDEX
#define FOURTH_INDEX 3
#endif

void LEAF_NAME(int first, int third, int second, int fourth) {
    register volatile int *page asm("$2") = (volatile int *)WORD_PAGE;

    asm volatile ("" : "=r" (page) : "0" (page));
    page[FIRST_INDEX] = first;
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[SECOND_INDEX] = second;
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[THIRD_INDEX] = third;
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[FOURTH_INDEX] = fourth;
}
