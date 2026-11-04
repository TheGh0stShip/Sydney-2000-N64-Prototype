#ifndef LEAF_NAME
#define LEAF_NAME copyOverlappingBytes
#endif

typedef unsigned char u8;
typedef unsigned int u32;

void LEAF_NAME(u8 *destination, u8 *source, u32 count)
{
    if (source < destination) {
        destination += count;
        source += count;
        while (count-- != 0) {
            *--destination = *--source;
        }
    } else {
        while (count-- != 0) {
            *destination++ = *source++;
        }
    }
}
