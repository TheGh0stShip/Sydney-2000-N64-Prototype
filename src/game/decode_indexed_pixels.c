#ifndef LEAF_NAME
#define LEAF_NAME decodeIndexedPixels
#endif
#ifndef DATA_NAME
#define DATA_NAME pixelData
#endif
#ifndef SCALE_NAME
#define SCALE_NAME pixelScale
#endif
#ifndef FORMAT_NAME
#define FORMAT_NAME pixelFormat
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 value;
    u32 unused04;
    u32 unused08;
    u32 dataOffset;
} PixelDecodeState;

extern u8 DATA_NAME[];
extern u32 SCALE_NAME;
extern u32 FORMAT_NAME;

void LEAF_NAME(
    PixelDecodeState *state,
    u32 *packedValues,
    u32 *multipliers,
    u32 *output,
    u32 bitIndex,
    u32 mode)
{
    u32 *end = output + 9;
    u32 shift = bitIndex - 1;

    do {
        u32 multiplier = *multipliers;
        u32 packed = *packedValues;
        u32 selector = ((packed & (3U << shift)) >> shift) ^ ((multiplier & 1) << 1);
        u32 offset = (((multiplier * state->value + packed) * SCALE_NAME) >> 4) * 8;
        u32 address = state->dataOffset + offset + selector * 2;

        if (mode == 0) {
            u32 low = packed & 1;
            u32 value = DATA_NAME[address + ((packed & 2) >> 1)];
            value &= 240U >> (low * 4);
            if (low == 0) {
                value >>= 4;
            }
            *output = value;
        } else if (mode == 1) {
            *output = DATA_NAME[address + (packed & 1)];
        } else if (mode == 2) {
            *output = ((u32)DATA_NAME[address] << 8) | DATA_NAME[address + 1];
        } else if (mode == 3) {
            FORMAT_NAME = 2;
        }

        output++;
        multipliers++;
        packedValues++;
    } while (output < end);
}
