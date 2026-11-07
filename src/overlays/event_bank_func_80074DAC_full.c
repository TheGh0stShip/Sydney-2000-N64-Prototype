typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 h0;
    s16 h2;
    float best;
    s32 pad8;
} Elem;

extern u8 *D_800FC270;

#define PB(o) (*(u8 *)(obj + 0x8000 + (o)))
#define PS(o) (*(s8 *)(obj + 0x8000 + (o)))
#define TBL (*(float **)(obj + 0x8000 + 0x44C))

void func_80074DAC(u8 *obj, float v)
{
    Elem *e;
    s32 c;

    if (PB(0x417) == 5) {
        return;
    }
    e = (Elem *)(D_800FC270 + 0xA10) + PS(0x415);
    c = PS(0x414);
    if (c >= 3) {
        TBL[PS(0x415) * 3] = TBL[PS(0x415) * 3 + 1];
        TBL[PS(0x415) * 3 + 1] = TBL[PS(0x415) * 3 + 2];
        TBL[PS(0x415) * 3 + 2] = v;
    } else {
        TBL[PS(0x415) * 3 + c] = v;
    }
    if (e->best < v) {
        e->best = v;
    }
    if (e->best > 0.0f) {
        e->h2 = e->best * 15.0f;
    }
}
