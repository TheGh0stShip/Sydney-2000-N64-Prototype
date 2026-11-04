#ifndef LEAF_NAME
#define LEAF_NAME piWriteBytes
#endif

#ifndef WRITE_WORD_NAME
#define WRITE_WORD_NAME writeWord
#endif

#ifndef WRITE_BYTE_NAME
#define WRITE_BYTE_NAME writeByte
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern void WRITE_WORD_NAME(u32 address, u32 value);
extern void WRITE_BYTE_NAME(u32 address, u8 value);

void LEAF_NAME(u32 address, const u8 *source, u32 length)
{
    while (length != 0 && (address & 3) != 0) {
        WRITE_BYTE_NAME(address++, *source++);
        length--;
    }
    while (length >= 4) {
        u32 value = ((u32)source[0] << 24) |
                    ((u32)source[1] << 16) |
                    ((u32)source[2] << 8) |
                    source[3];
        WRITE_WORD_NAME(address, value);
        address += 4;
        source += 4;
        length -= 4;
    }
    while (length != 0) {
        WRITE_BYTE_NAME(address++, *source++);
        length--;
    }
}
