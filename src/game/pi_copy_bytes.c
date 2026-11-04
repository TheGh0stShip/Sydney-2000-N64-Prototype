#ifndef LEAF_NAME
#define LEAF_NAME piCopyBytes
#endif

#ifndef READ_BYTE_NAME
#define READ_BYTE_NAME readByte
#endif

#ifndef WRITE_BYTE_NAME
#define WRITE_BYTE_NAME writeByte
#endif

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 READ_BYTE_NAME(u32 address);
extern void WRITE_BYTE_NAME(u32 address, u8 value);

void LEAF_NAME(u32 destination, u32 source, u32 size) {
    while (size--) {
        WRITE_BYTE_NAME(destination++, READ_BYTE_NAME(source++));
    }
}
