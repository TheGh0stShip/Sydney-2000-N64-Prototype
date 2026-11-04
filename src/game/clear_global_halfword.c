#ifndef LEAF_NAME
#define LEAF_NAME clearGlobalHalfword
#endif

#ifndef HALFWORD_PAGE
#define HALFWORD_PAGE 0x80000000
#endif

#ifndef HALFWORD_INDEX
#define HALFWORD_INDEX 0
#endif

void LEAF_NAME(void) {
    register volatile unsigned short *page asm("$2") =
        (volatile unsigned short *)HALFWORD_PAGE;

    asm volatile ("" : "=r" (page) : "0" (page));
    page[HALFWORD_INDEX] = 0;
}
