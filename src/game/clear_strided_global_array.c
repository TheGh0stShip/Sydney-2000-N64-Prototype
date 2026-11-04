#ifndef LEAF_NAME
#define LEAF_NAME clearStridedGlobalArray
#endif

#ifndef ARRAY_PAGE
#define ARRAY_PAGE 0x80000000
#endif

#ifndef ARRAY_INDEX
#define ARRAY_INDEX 0
#endif

#ifndef LAST_INDEX
#define LAST_INDEX 0
#endif

#ifndef STRIDE_WORDS
#define STRIDE_WORDS 1
#endif

#ifndef FINAL_PAGE
#define FINAL_PAGE 0x80000000
#endif

#ifndef FINAL_INDEX
#define FINAL_INDEX 0
#endif

int LEAF_NAME(void) {
    register int count asm("$3") = LAST_INDEX;
    register volatile int *entry asm("$2") = (volatile int *)ARRAY_PAGE;

    asm volatile ("" : "=r" (count) : "0" (count));
    asm volatile ("" : "=r" (entry) : "0" (entry));
    entry += ARRAY_INDEX;
    asm volatile ("" : "=r" (entry) : "0" (entry));
    entry += LAST_INDEX * STRIDE_WORDS;
    do {
        *entry = 0;
        count--;
        entry -= STRIDE_WORDS;
    } while (count >= 0);

    asm volatile ("" : "=r" (entry));
    entry = (volatile int *)FINAL_PAGE;
    asm volatile ("" : "=r" (entry) : "0" (entry));
    entry[FINAL_INDEX] = 0;
    return 1;
}
