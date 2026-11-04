#ifndef LEAF_NAME
#define LEAF_NAME piReadToBuffer
#endif

#ifndef READ_WORD_NAME
#define READ_WORD_NAME readWord
#endif

#ifndef READ_BYTE_NAME
#define READ_BYTE_NAME readByte
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 READ_WORD_NAME(u32 address);
extern u8 READ_BYTE_NAME(u32 address);

void LEAF_NAME(u32 source, u8 *destination, u32 length) {
    u32 word;

    while (length != 0 && (source & 3) != 0) {
        *destination++ = READ_BYTE_NAME(source++);
        length--;
    }
    while (length >= 4) {
        word = READ_WORD_NAME(source);
        *destination++ = word >> 24;
        *destination++ = word >> 16;
        *destination++ = word >> 8;
        *destination++ = word;
        source += 4;
        length -= 4;
    }
    while (length != 0) {
        *destination++ = READ_BYTE_NAME(source++);
        length--;
    }
}
