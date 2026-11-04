#ifndef LEAF_NAME
#define LEAF_NAME piWriteByte
#endif

#ifndef WRITE_WORD_NAME
#define WRITE_WORD_NAME writeWord
#endif

#ifndef READ_WORD_NAME
#define READ_WORD_NAME readWord
#endif

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void WRITE_WORD_NAME(u32 address, u32 value);
extern u32 READ_WORD_NAME(u32 address);

void LEAF_NAME(u32 address, u8 value) {
    s32 shift = (~address & 3) * 8;

    address &= ~3;
    WRITE_WORD_NAME(address, (READ_WORD_NAME(address) & ~(0xFF << shift)) |
                             ((u32)value << shift));
}
