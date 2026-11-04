#ifndef LEAF_NAME
#define LEAF_NAME setTwoGlobalFloats
#endif

#ifndef FLOAT_PAGE
#define FLOAT_PAGE 0x80000000
#endif

#ifndef FIRST_INDEX
#define FIRST_INDEX 0
#endif

#ifndef SECOND_INDEX
#define SECOND_INDEX 1
#endif

void LEAF_NAME(float first, float second) {
    register volatile float *page asm("$2") = (volatile float *)FLOAT_PAGE;

    asm volatile ("" : "=r" (page) : "0" (page));
    page[FIRST_INDEX] = first;
    asm volatile ("" : "=r" (page));
    page = (volatile float *)FLOAT_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[SECOND_INDEX] = second;
}
