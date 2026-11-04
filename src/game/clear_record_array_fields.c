#ifndef LEAF_NAME
#define LEAF_NAME clearRecordArrayFields
#endif

#ifndef ARRAY_PAGE
#define ARRAY_PAGE 0x80000000
#endif

#ifndef ARRAY_OFFSET
#define ARRAY_OFFSET 0
#endif

#ifndef RECORD_COUNT
#define RECORD_COUNT 1
#endif

#ifndef RECORD_STRIDE
#define RECORD_STRIDE 4
#endif

#ifndef FIRST_OFFSET
#define FIRST_OFFSET 0
#endif

#ifndef SECOND_OFFSET
#define SECOND_OFFSET 4
#endif

void LEAF_NAME(void) {
    register unsigned int index asm("$4") = 0;
    register volatile char *page asm("$2") = (volatile char *)ARRAY_PAGE;
    register volatile char *record asm("$3");

    asm volatile ("" : "=r" (index) : "0" (index));
    asm volatile ("" : "=r" (page) : "0" (page));
    record = page + ARRAY_OFFSET;
    asm volatile ("" : "=r" (record) : "0" (record));
    do {
        *(volatile int *)(record + FIRST_OFFSET) = 0;
        *(volatile int *)(record + SECOND_OFFSET) = 0;
        asm volatile ("" : : : "memory");
        index++;
        record += RECORD_STRIDE;
    } while (index < RECORD_COUNT);
}
