#ifndef LEAF_NAME
#define LEAF_NAME debugDelay
#endif

#ifndef COUNTER_ADDRESS
#define COUNTER_ADDRESS 0x8006BBD0
#endif

void LEAF_NAME(int count) {
    register char *page asm("$3") =
        (char *)((COUNTER_ADDRESS + 0x8000) & 0xFFFF0000);

    asm volatile("" : "=r"(page) : "0"(page));
    *(volatile int *)(page + (short)COUNTER_ADDRESS) = 0;
    while (*(volatile int *)(page + (short)COUNTER_ADDRESS) < count) {
        *(volatile int *)(page + (short)COUNTER_ADDRESS) =
            *(volatile int *)(page + (short)COUNTER_ADDRESS) + 1;
    }
}
