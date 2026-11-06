typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))

extern u32 D_800F2C14;
typedef struct { u8 b[32]; } E32;
#define EE ((u8 *)&((H *)(g + 0x8000))->arr[((H *)(g + 0x8000))->idx])
typedef struct { u8 pad[0x11c]; s8 idx; u8 p1; u8 st; u8 p2[0x1d]; E32 *arr; } H;

static inline u32 rnd(s32 n)
{
    D_800F2C14 = (D_800F2C14 * 16807) & 0x7fffffff;
    return (u32)((s32)(D_800F2C14 >> 15) * n) >> 16;
}

s32 func_800ADD20(u8 *g)
{
    s32 r = 0;
    u8 *e;
    u32 d;

    if (B(g + 0x8000, 0x11e) == 1)
        return r;
    if (W(EE, 0x18) == W(g, 0x35cc))
        return 1;
    if ((u32)W(EE, 0x1c) >= (u32)W(g, 0x35cc)) {
        d = ((u32)W(EE, 0x1c) - (u32)W(g, 0x35cc)) / 5;
        if (d == 0) {
            if (rnd(100) < 15)
                r = 1;
        } else if (d == 1) {
            if (rnd(100) < 20)
                r = 1;
        } else if (d == 2) {
            if (rnd(100) < 30)
                r = 1;
        } else {
            if (rnd(100) < 50)
                r = 1;
        }
        if (r) {
            W((u8 *)W(g + 0x8000, 0x13c) + SB(g + 0x8000, 0x11c) * 32, 0x18) = W(g, 0x35cc);
        }
}
    return r;
}
