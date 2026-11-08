typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { u32 seed; } Rng;
extern Rng D_800F13F0;
extern s32 func_800B9E9C(u8 *o, s32 a, s32 b, s32 c, s32 d);
static inline u32 rnd(Rng *g, u32 n)
{
    g->seed = (g->seed * 16807) & 0x7FFFFFFF;
    return ((g->seed >> 15) * n) >> 16;
}

void func_801045D8(u8 *o, s32 mode)
{
    s16 *p = (s16 *)(o + 430);
    u32 r, i;

    if (rnd(&D_800F13F0, 100) < 75) {
        *p = 32;
    } else {
        *p = 49;
    }
    p++;
    r = rnd(&D_800F13F0, 20);
    i = rnd(&D_800F13F0, 6);
    for (; i != 0; i--) {
        if (i != r) {
            *p = 23;
        } else {
            *p = 48;
        }
        p++;
    }
    r = rnd(&D_800F13F0, 100);
    if (r < 55) {
        *p = 24;
    } else if (r < 80) {
        *p = 46;
    } else {
        *p = 47;
    }
    p++;
    D_800F13F0.seed = (D_800F13F0.seed * 16807) & 0x7FFFFFFF;
    for (i = D_800F13F0.seed >> 30; i != 0; i--) {
        *p++ = 22;
    }
    *p++ = 53;
    switch (mode) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 30;
        break;
    case 2:
        r = 90;
        break;
    }
    if (rnd(&D_800F13F0, 100) < r) {
        *p++ = 52;
    }
    *p = -1;
    o[429] = 0;
    func_800B9E9C(o, *(s16 *)(o + 430), -1, *(s32 *)(o + 632), 0);
    *(f32 *)(o + 632) = *(f32 *)(o + 788);
}
