#ifndef LEAF_NAME
#define LEAF_NAME setGlobalAroundCall
#endif

#ifndef HELPER_NAME
#define HELPER_NAME helper
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

#ifndef FRAME_SIZE
#define FRAME_SIZE 1
#endif

extern int HELPER_NAME(void);

void LEAF_NAME(void) {
    volatile unsigned char frame[FRAME_SIZE];
    register volatile int *page asm("$16") = (volatile int *)WORD_PAGE;
    register int active asm("$2") = 1;

    asm volatile ("" : "=r" (page), "=r" (active) :
                  "0" (page), "1" (active));
    page[WORD_INDEX] = active;
    if (HELPER_NAME() != 0) {
        page[WORD_INDEX] = 0;
    }
}
