#ifndef LEAF_NAME
#define LEAF_NAME initGlobalStateConstants
#endif

#ifndef STATE_PAGE
#define STATE_PAGE 0x80000000
#endif

#ifndef FIRST_HALF_INDEX
#define FIRST_HALF_INDEX 0
#endif

#ifndef SECOND_HALF_INDEX
#define SECOND_HALF_INDEX 1
#endif

#ifndef FIRST_WORD_INDEX
#define FIRST_WORD_INDEX 0
#endif

#ifndef SECOND_WORD_INDEX
#define SECOND_WORD_INDEX 1
#endif

void LEAF_NAME(void) {
    register volatile unsigned short *halfPage asm("$3") =
        (volatile unsigned short *)STATE_PAGE;
    register int value asm("$2");
    register volatile int *wordPage asm("$2");

    asm volatile ("" : "=r" (halfPage) : "0" (halfPage) : "memory");
    value = 2;
    asm volatile ("" : "=r" (value) : "0" (value));
    halfPage[FIRST_HALF_INDEX] = value;

    asm volatile ("" : "=r" (halfPage));
    halfPage = (volatile unsigned short *)STATE_PAGE;
    asm volatile ("" : "=r" (halfPage) : "0" (halfPage) : "memory");
    value = 4;
    asm volatile ("" : "=r" (value) : "0" (value));
    halfPage[SECOND_HALF_INDEX] = value;

    wordPage = (volatile int *)STATE_PAGE;
    asm volatile ("" : "=r" (wordPage) : "0" (wordPage));
    wordPage[FIRST_WORD_INDEX] = 0;
    asm volatile ("" : "=r" (wordPage));
    wordPage = (volatile int *)STATE_PAGE;
    asm volatile ("" : "=r" (wordPage) : "0" (wordPage));
    wordPage[SECOND_WORD_INDEX] = 0;
}
