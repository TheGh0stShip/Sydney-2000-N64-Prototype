#ifndef LEAF_NAME
#define LEAF_NAME packColorGlobal
#endif

#ifndef WORD_PAGE
#define WORD_PAGE 0x80000000
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

void LEAF_NAME(int red, int green, int blue) {
    register volatile unsigned int *page asm("$2") =
        (volatile unsigned int *)WORD_PAGE;
    unsigned int packed;

    asm volatile ("" : "=r" (page) : "0" (page));
    packed = ((red << 8) & 0xF800) |
             ((green << 3) & 0x07C0) |
             ((blue >> 2) & 0x003E) |
             1;
    page[WORD_INDEX] = packed;
}
