#ifndef ICACHE_NAME
#define ICACHE_NAME sweepInstructionCache
#endif

#ifndef DCACHE_NAME
#define DCACHE_NAME sweepDataCache
#endif

typedef unsigned int u32;

void ICACHE_NAME(void) {
    register u32 current asm("$8") = 0x80000000;
    register u32 end asm("$9");

    asm volatile("" : "=r"(current) : "0"(current));
    end = current + 0x1FF0;

    asm volatile(
        ".set noreorder\n\t"
        "1:\n\t"
        "cache 1,0(%0)\n\t"
        "bne %0,%1,1b\n\t"
        "addiu %0,%0,16\n\t"
        ".set reorder"
        : "=r"(current)
        : "r"(end), "0"(current));
}

void DCACHE_NAME(void) {
    register u32 current asm("$8") = 0x80000000;
    register u32 end asm("$9");

    asm volatile("" : "=r"(current) : "0"(current));
    end = current + 0x3FE0;

    asm volatile(
        ".set noreorder\n\t"
        "1:\n\t"
        "cache 0,0(%0)\n\t"
        "bne %0,%1,1b\n\t"
        "addiu %0,%0,32\n\t"
        ".set reorder"
        : "=r"(current)
        : "r"(end), "0"(current));
}
