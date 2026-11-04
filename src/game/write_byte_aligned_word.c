#ifndef LEAF_NAME
#define LEAF_NAME writeByteAlignedWord
#endif

void LEAF_NAME(void *address, unsigned int value) {
    register unsigned int shift asm("$6") = (~(unsigned int)address & 3) << 3;
    register unsigned int temporary asm("$2") = ~3U;
    register unsigned int current asm("$3");
    unsigned int *word;

    asm volatile ("" : "=r" (shift), "=r" (temporary)
                  : "0" (shift), "1" (temporary));
    word = (unsigned int *)((unsigned int)address & temporary);
    temporary = 0xFF;
    temporary <<= shift;
    temporary = ~temporary;
    value &= 0xFF;
    asm volatile ("" : : : "memory");
    current = *word;
    asm volatile ("" : "=r" (temporary), "=r" (current)
                  : "0" (temporary), "1" (current));
    value <<= shift;
    current &= temporary;
    asm volatile ("" : "=r" (current) : "0" (current));
    current |= value;
    *word = current;
}
