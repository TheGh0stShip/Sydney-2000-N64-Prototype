#ifndef LEAF_NAME
#define LEAF_NAME synthesizeGsmFrame
#endif
#ifndef RPE_NAME
#define RPE_NAME decodeRpeSequence
#endif
#ifndef LONG_TERM_NAME
#define LONG_TERM_NAME synthesizeLongTerm
#endif
#ifndef LAR_NAME
#define LAR_NAME decodeLarParameters
#endif

typedef short s16;
typedef int s32;
typedef struct GsmState GsmState;

extern void RPE_NAME(s16 xmax, s16 mc, s16 *xmc, s16 *erp);
extern void LONG_TERM_NAME(GsmState *state, s16 nc, s16 bc, s16 *erp);
extern void LAR_NAME(GsmState *state, s16 *lar, GsmState *samples, s16 *output);

void LEAF_NAME(GsmState *state, s16 *lar, s16 *nc, s16 *bc, s16 *mc,
               s16 *xmax, s16 *xmc, s16 *output)
{
    s32 index;
    s16 erp[40];

    for (index = 0; index <= 3;
         index++, xmax++, bc++, nc++, mc++, xmc += 13) {
        RPE_NAME(*xmax, *mc, xmc, erp);
        LONG_TERM_NAME(state, *nc, *bc, erp);
    }
    LAR_NAME(state, lar, state, output);
}
