#ifndef LEAF_NAME
#define LEAF_NAME decodeGsmStreamFrame
#endif
#ifndef SYNTHESIZE_NAME
#define SYNTHESIZE_NAME synthesizeGsmFrame
#endif
#ifndef BZERO_NAME
#define BZERO_NAME bzero
#endif

typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct GsmStream {
    char unk000[0x18A];
    s16 voicedFrames;
    s16 silentFrames;
    char unk18E[0x12];
    u32 ring[0x400];
    char unk11A0[0x28];
    s32 bitPos;
} GsmStream;

extern void SYNTHESIZE_NAME(GsmStream *, s16 *, s16 *, s16 *, s16 *, s16 *,
                            s16 *, s16 *);
extern void BZERO_NAME(void *, u32);

/* Pull n bits (LSB first) from the 32-bit word ring into dst. */
#define GET_BITS(dst, n)                                                  \
    if (avail > (n)) {                                                    \
        dst = bits & ((1 << (n)) - 1);                                    \
        bits >>= (n);                                                     \
        avail -= (n);                                                     \
    } else {                                                              \
        dst = bits & ((1 << avail) - 1);                                  \
        pos += 32;                                                        \
        bits = stream->ring[(pos >> 5) & 0x3FF];                          \
        if (avail != (n)) {                                               \
            dst |= (bits & ((1 << ((n) - avail)) - 1)) << avail;          \
        }                                                                 \
        bits >>= (n) - avail;                                             \
        avail += 32 - (n);                                                \
    }

s32 LEAF_NAME(GsmStream *stream, s16 *samples)
{
    s16 lar[8], nc[4], mc[4], bc[4], xmax[4], xmc[13 * 4], pad[1];
    u32 bits;
    s32 avail;
    s32 pos;
    s32 flag;
    s32 index;

    pos = stream->bitPos;
    bits = stream->ring[(pos >> 5) & 0x3FF] >> (pos & 0x1F);
    avail = 32 - (pos & 0x1F);

    /* Each run header selects a count of coded frames or of silent frames. */
    if (stream->voicedFrames == 0 && stream->silentFrames == 0) {
        GET_BITS(flag, 1);
        if (flag) {
            GET_BITS(stream->silentFrames, 4);
            stream->silentFrames++;
        } else {
            GET_BITS(stream->voicedFrames, 7);
            stream->voicedFrames++;
        }
    }

    if (stream->silentFrames != 0) {
        BZERO_NAME(samples, 160 * sizeof(s16));
        stream->silentFrames--;
    } else {
        GET_BITS(lar[0], 6);
        GET_BITS(lar[1], 6);
        GET_BITS(lar[2], 5);
        GET_BITS(lar[3], 5);
        GET_BITS(lar[4], 4);
        GET_BITS(lar[5], 4);
        GET_BITS(lar[6], 3);
        GET_BITS(lar[7], 3);

        for (index = 0; index < 4; index++) {
            GET_BITS(nc[index], 7);
            GET_BITS(bc[index], 2);
            GET_BITS(mc[index], 2);
            GET_BITS(xmax[index], 6);
            GET_BITS(xmc[index * 13 + 0], 3);
            GET_BITS(xmc[index * 13 + 1], 3);
            GET_BITS(xmc[index * 13 + 2], 3);
            GET_BITS(xmc[index * 13 + 3], 3);
            GET_BITS(xmc[index * 13 + 4], 3);
            GET_BITS(xmc[index * 13 + 5], 3);
            GET_BITS(xmc[index * 13 + 6], 3);
            GET_BITS(xmc[index * 13 + 7], 3);
            GET_BITS(xmc[index * 13 + 8], 3);
            GET_BITS(xmc[index * 13 + 9], 3);
            GET_BITS(xmc[index * 13 + 10], 3);
            GET_BITS(xmc[index * 13 + 11], 3);
            GET_BITS(xmc[index * 13 + 12], 3);
        }

        stream->voicedFrames--;
        SYNTHESIZE_NAME(stream, lar, nc, bc, mc, xmax, xmc, samples);
    }

    stream->bitPos = (pos & ~0x1F) - avail + 32;
    return 0;
}
