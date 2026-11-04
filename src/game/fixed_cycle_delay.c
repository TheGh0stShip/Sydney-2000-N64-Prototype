#ifndef LEAF_NAME
#define LEAF_NAME fixedCycleDelay
#endif

void LEAF_NAME(void) {
    register int count asm("$2") = 11;

    asm volatile(
        ".set noreorder\n\t"
        "addiu %0,%0,-1\n"
        "1:\n\t"
        "bgez %0,1b\n\t"
        "addiu %0,%0,-1\n\t"
        ".set reorder"
        : "=r"(count)
        : "0"(count));
}
