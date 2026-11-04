#ifndef LEAF_NAME
#define LEAF_NAME piReadBytes
#endif

#ifndef READ_WORD_NAME
#define READ_WORD_NAME readWord
#endif

#ifndef READ_BYTE_NAME
#define READ_BYTE_NAME readByte
#endif

#ifndef STORE_BYTE_NAME
#define STORE_BYTE_NAME storeByte
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 READ_WORD_NAME(u32 address);
extern u32 READ_BYTE_NAME(u32 address);
extern void STORE_BYTE_NAME(u32 address, u8 value);

void LEAF_NAME(u32 source, u32 destination, u32 length) {
    u32 word;

    while (length != 0 && (source & 3) != 0) {
        STORE_BYTE_NAME(destination++, READ_BYTE_NAME(source++));
        length--;
    }
    while (length >= 4) {
        word = READ_WORD_NAME(source);
        STORE_BYTE_NAME(destination++, word >> 24);
        STORE_BYTE_NAME(destination++, word >> 16);
        STORE_BYTE_NAME(destination++, word >> 8);
        STORE_BYTE_NAME(destination++, word);
        source += 4;
        length -= 4;
    }
    while (length != 0) {
        STORE_BYTE_NAME(destination++, READ_BYTE_NAME(source++));
        length--;
    }
}
