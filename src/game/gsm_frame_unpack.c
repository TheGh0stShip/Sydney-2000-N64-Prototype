#ifndef LEAF_NAME
#define LEAF_NAME unpackGsmFrame
#endif
#ifndef SYNTHESIZE_NAME
#define SYNTHESIZE_NAME synthesizeGsmFrame
#endif

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct GsmState GsmState;

extern void SYNTHESIZE_NAME(GsmState *, s16 *, s16 *, s16 *, s16 *, s16 *,
                            s16 *, s16 *);

s32 LEAF_NAME(GsmState *state, u8 *data, s16 *samples)
{
    s16 lar[8], nc[4], mc[4], bc[4], xmax[4], xmc[52];
    s32 index;
    u8 *cursor = data;
    s16 *ncCursor;

    lar[0] = ((data[0] & 0xF) << 2) | ((data[1] >> 6) & 3);
    lar[1] = data[1] & 0x3F;
    lar[2] = (data[2] >> 3) & 0x1F;
    lar[3] = ((data[2] & 7) << 2) | ((data[3] >> 6) & 3);
    lar[4] = (data[3] >> 2) & 0xF;
    lar[5] = ((data[3] & 3) << 2) | ((data[4] >> 6) & 3);
    lar[6] = (data[4] >> 3) & 7;
    lar[7] = data[4] & 7;

    for (index = 0, ncCursor = nc; index < 4;
         ncCursor++, cursor += 7, index++) {
        *ncCursor = (cursor[5] >> 1) & 0x7F;
        bc[index] = ((cursor[5] & 1) << 1) | ((cursor[6] >> 7) & 1);
        mc[index] = (cursor[6] >> 5) & 3;
        xmax[index] = ((cursor[6] & 0x1F) << 1) | ((cursor[7] >> 7) & 1);
        xmc[index * 13 + 0] = (cursor[7] >> 4) & 7;
        xmc[index * 13 + 1] = (cursor[7] >> 1) & 7;
        xmc[index * 13 + 2] = ((cursor[7] & 1) << 2) | ((cursor[8] >> 6) & 3);
        xmc[index * 13 + 3] = (cursor[8] >> 3) & 7;
        xmc[index * 13 + 4] = cursor[8] & 7;
        xmc[index * 13 + 5] = (cursor[9] >> 5) & 7;
        xmc[index * 13 + 6] = (cursor[9] >> 2) & 7;
        xmc[index * 13 + 7] = ((cursor[9] & 3) << 1) | ((cursor[10] >> 7) & 1);
        xmc[index * 13 + 8] = (cursor[10] >> 4) & 7;
        xmc[index * 13 + 9] = (cursor[10] >> 1) & 7;
        xmc[index * 13 + 10] = ((cursor[10] & 1) << 2) | ((cursor[11] >> 6) & 3);
        xmc[index * 13 + 11] = (cursor[11] >> 3) & 7;
        xmc[index * 13 + 12] = cursor[11] & 7;
    }

    SYNTHESIZE_NAME(state, lar, nc, bc, mc, xmax, xmc, samples);
    return 0;
}
