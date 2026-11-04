#ifndef LEAF_NAME
#define LEAF_NAME piFill
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

void LEAF_NAME(u32 address, u8 value, u32 length) {
    u32 word;

    while (length != 0 && (address & 3) != 0) {
        WRITE_BYTE_NAME(address++, value);
        length--;
    }
    if (length >= 4) {
        word = (value << 24) | (value << 16) | (value << 8) | value;
        do {
            WRITE_WORD_NAME(address, word);
            length -= 4;
            address += 4;
        } while (length >= 4);
    }
    while (length != 0) {
        WRITE_BYTE_NAME(address++, value);
        length--;
    }
}
