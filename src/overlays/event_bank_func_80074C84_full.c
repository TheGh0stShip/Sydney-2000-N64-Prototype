typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 count;
    s16 n;
    u8 miss;
    u8 pad5[3];
    s32 last;
    u8 pad0C[0x10];
} Rec;

typedef struct {
    s16 h0;
    s16 h2;
    float best;
    s32 pad8;
} Elem;

extern u8 *D_800FC270;

#define B(o) (*(u8 *)(obj + (o)))
#define SB(o) (*(s8 *)(obj + (o)))
#define W(o) (*(s32 *)(obj + (o)))
#define REC (*(Rec **)(obj + 0x75FC))
#define TBL (*(float **)(obj + 0x75F8))

void func_80074C84(u8 *obj, s32 n)
{
    s32 k;
    float f;
    u8 *p;
    Elem *e;

    e = (Elem *)(D_800FC270 + 0xA10) + SB(0x75A8);
    {
        s32 h = REC[SB(0x75A8)].n;
        if (h < 3) {
            k = h;
        } else {
            TBL[SB(0x75A8) * 3] = TBL[SB(0x75A8) * 3 + 1];
            TBL[SB(0x75A8) * 3 + 1] = TBL[SB(0x75A8) * 3 + 2];
            k = 2;
        }
    }
    p = *(u8 **)(obj + 0x59CC);
    if (p != 0 && *(s32 *)(p + 0x2FC) == 1) {
        n = 0;
    }
    if (n == 0) {
        REC[SB(0x75A8)].count++;
        if ((u8)(B(0x75AB) - 3) >= 2) {
            REC[SB(0x75A8)].miss++;
        }
        if (REC[SB(0x75A8)].miss >= 3) {
            W(0x75D8) = 1;
            B(0x75E8) += 1;
        }
        TBL[SB(0x75A8) * 3 + k] = 0;
    } else {
        TBL[SB(0x75A8) * 3 + k] = f = (float)n / 100.0f + 0.0005f;
        REC[SB(0x75A8)].last = n;
        REC[SB(0x75A8)].miss = 0;
        if (e->best < f) {
            e->best = f;
        }
    }
    if (n != 0 && e->best > 0.0f) {
        e->h2 = (s16)(e->best * 1000.0f) / 2;
    }
}
