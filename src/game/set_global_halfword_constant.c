#ifndef LEAF_NAME
#define LEAF_NAME setGlobalHalfwordConstant
#endif

#ifndef HALFWORD_PAGE
#define HALFWORD_PAGE 0x80000000
#endif

#ifndef HALFWORD_INDEX
#define HALFWORD_INDEX 0
#endif

#ifndef HALFWORD_VALUE
#define HALFWORD_VALUE 0
#endif

void LEAF_NAME(void) {
    register volatile unsigned short *page asm("$3") =
        (volatile unsigned short *)HALFWORD_PAGE;
    register int value asm("$2") = HALFWORD_VALUE;

    asm volatile ("" : "=r" (page), "=r" (value) : "0" (page), "1" (value));
    page[HALFWORD_INDEX] = value;
}
