#ifndef LEAF_NAME
#define LEAF_NAME appendGlobalPointer
#endif

#ifndef STATE_PAGE
#define STATE_PAGE 0x80000000
#endif

#ifndef COUNT_INDEX
#define COUNT_INDEX 0
#endif

#ifndef ARRAY_INDEX
#define ARRAY_INDEX 0
#endif

#ifndef ARRAY_LIMIT
#define ARRAY_LIMIT 1
#endif

void LEAF_NAME(void *value) {
    register volatile unsigned int *statePage asm("$6") =
        (volatile unsigned int *)STATE_PAGE;
    register unsigned int count asm("$5");

    asm volatile ("" : "=r" (statePage) : "0" (statePage));
    count = statePage[COUNT_INDEX];
    asm volatile ("" : "=r" (count) : "0" (count));
    if (count < ARRAY_LIMIT) {
        register volatile void **array asm("$2") =
            (volatile void **)STATE_PAGE;
        register unsigned int address asm("$3");
        volatile void **entry;
        register unsigned int next asm("$2");

        asm volatile ("" : "=r" (array) : "0" (array));
        array += ARRAY_INDEX;
        address = count << 2;
        asm volatile ("" : "=r" (address) : "0" (address));
        address += (unsigned int)array;
        asm volatile ("" : "=r" (address) : "0" (address));
        entry = (volatile void **)address;
        next = count + 1;
        asm volatile ("" : "=r" (next) : "0" (next));
        *entry = value;
        statePage[COUNT_INDEX] = next;
    }
}
