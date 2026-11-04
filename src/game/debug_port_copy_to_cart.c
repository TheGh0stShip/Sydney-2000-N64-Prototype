#ifndef LEAF_NAME
#define LEAF_NAME debugPortCopyToCart
#endif

#ifndef WRITE_WORD_NAME
#define WRITE_WORD_NAME writeWord
#endif

#ifndef READ_WORD_NAME
#define READ_WORD_NAME readWord
#endif

#ifndef DELAY_NAME
#define DELAY_NAME delay
#endif

typedef unsigned int u32;
typedef int s32;

extern void WRITE_WORD_NAME(u32 address, u32 value);
extern u32 READ_WORD_NAME(u32 address);
extern void DELAY_NAME(s32 count);

void LEAF_NAME(void) {
    u32 source;
    u32 size;
    u32 i;

    source = READ_WORD_NAME(0xB1FFFFF4) & 0xB1FFFFFC;
    size = READ_WORD_NAME(0xB1FFFFF8) & 0x01FFFFFC;
    WRITE_WORD_NAME(0xB1FFFFFC, 0);
    while (READ_WORD_NAME(0xB0000010) == 0) {
        DELAY_NAME(500);
    }
    for (i = 0; i < size / 4; i++) {
        WRITE_WORD_NAME((source & 0xB07FFFFF) + i * 4,
                        READ_WORD_NAME(source + i * 4));
    }
    DELAY_NAME(2000);
    WRITE_WORD_NAME(0xB1FFFFF4, 0);
}
