typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { u32 seed; } Rng;
extern Rng D_800F13F0;
extern u16 D_8007C378[];
extern s32 func_800B9E9C(u8 *o, s32 a, s32 b, s32 c, s32 d);

static inline u32 rnd(Rng *g, u32 n)
{
    g->seed = (g->seed * 16807) & 0x7FFFFFFF;
    return ((g->seed >> 15) * n) >> 16;
}

static inline s32 more(u32 i)
{
    return i != 0;
}

void func_8007B910(u8 *o)
{
    s16 *p;
    u32 a, i;

    *(s16 *)(o + 430) = 32;
    *(s16 *)(o + 432) = 21;
    p = (s16 *)(o + 434);
    a = rnd(&D_800F13F0, 10);
    for (i = rnd(&D_800F13F0, (8 - o[1228]) >> 1); i != 0; i--) {
        if (i != a) {
            *p = 19;
        } else {
            *p = 50;
        }
        p++;
    }
    *p++ = 53;
    D_800F13F0.seed = (D_800F13F0.seed * 16807) & 0x7FFFFFFF;
    i = D_800F13F0.seed >> 30;
    while (more(i)) {
        i--;
        D_800F13F0.seed = (D_800F13F0.seed * 16807) & 0x7FFFFFFF;
        *p++ = D_8007C378[D_800F13F0.seed >> 29];
    }
    if (rnd(&D_800F13F0, 10) == 0) {
        *p++ = 40;
        for (i = rnd(&D_800F13F0, 15); i != 0; i--) {
            *p++ = 41;
        }
        *p++ = 42;
    }
    *p = -1;
    o[429] = 0;
    func_800B9E9C(o, *(s16 *)(o + 430), -1, *(s32 *)(o + 632), 0);
    *(f32 *)(o + 632) = *(f32 *)(o + 788);
}
