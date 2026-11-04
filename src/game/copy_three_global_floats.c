#ifndef LEAF_NAME
#define LEAF_NAME copyThreeGlobalFloats
#endif

#ifndef FLOAT_PAGE
#define FLOAT_PAGE 0x80000000
#endif

#ifndef SOURCE_INDEX
#define SOURCE_INDEX 0
#endif

#ifndef DEST_INDEX
#define DEST_INDEX 0
#endif

void LEAF_NAME(volatile float *source) {
    register volatile float *page asm("$2") = (volatile float *)FLOAT_PAGE;
    float value;

    value = source[SOURCE_INDEX];
    asm volatile ("" : "=r" (page) : "0" (page));
    page[DEST_INDEX] = value;

    asm volatile ("" : "=r" (page));
    value = source[SOURCE_INDEX + 1];
    page = (volatile float *)FLOAT_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[DEST_INDEX + 1] = value;

    asm volatile ("" : "=r" (page));
    value = source[SOURCE_INDEX + 2];
    page = (volatile float *)FLOAT_PAGE;
    asm volatile ("" : "=r" (page) : "0" (page));
    page[DEST_INDEX + 2] = value;
}
