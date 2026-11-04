#ifndef LEAF_NAME
#define LEAF_NAME clearGlobalAndCallConstant
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

#ifndef ARGUMENT_VALUE
#define ARGUMENT_VALUE 0
#endif

extern void HELPER_NAME(int value);

void LEAF_NAME(void) {
    register volatile int *page asm("$2") = (volatile int *)WORD_PAGE;
    register int argument asm("$4") = ARGUMENT_VALUE;

    asm volatile ("" : "=r" (page), "=r" (argument) :
                  "0" (page), "1" (argument));
    page[WORD_INDEX] = 0;
    HELPER_NAME(argument);
}
