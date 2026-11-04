#ifndef LEAF_NAME
#define LEAF_NAME clearAndCopyGlobal
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef CLEAR_INDEX
#define CLEAR_INDEX 0
#endif

#ifndef SOURCE_INDEX
#define SOURCE_INDEX 1
#endif

#ifndef DEST_INDEX
#define DEST_INDEX 2
#endif

int LEAF_NAME(void) {
    register volatile int *page asm("$2") = (volatile int *)WORD_PAGE;
    register int value asm("$3");

    asm volatile ("" : "=r" (page) : "0" (page));
    page[CLEAR_INDEX] = 0;
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    value = page[SOURCE_INDEX];
    asm volatile ("" : "=r" (value) : "0" (value));
    asm volatile ("" : "=r" (page));
    page = (volatile int *)WORD_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[DEST_INDEX] = value;
    return 0;
}
