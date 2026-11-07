typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define q (o + 0x8000)
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern u8 *D_800FC270;
extern u32 D_800F2C14[];
extern u8 D_800F3BC0[];
extern s8 func_8009B670(s32 a);
extern void func_800C0110(u8 *a, s32 b, s32 c, s32 d);

static inline u32 rnd(u32 n)
{
    D_800F2C14[0] = (D_800F2C14[0] * 16807) & 0x7FFFFFFF;
    return ((D_800F2C14[0] >> 15) * n) >> 16;
}

void func_800AE0A0(u8 *o, s32 arg)
{
    s32 a, b, res, i;
    s8 k[2];
    s8 t;
    s32 m;
    u8 *g, *d;

    if (q[286] >= 2) {
        return;
    }
    b = 0;
    a = b;
    res = -1;
    g = D_800FC270;
    if (W(g, 2560) == 5) {
        if ((u32)F(g, 3584) < (u32)W(o, 13772)) {
            b = 1;
        }
    } else {
        if (W(g, 2560) == 4) {
            if ((u32)F(g, 1348) < (u32)W(o, 13772)) {
                a = 1;
            }
        }
        if ((u32)F(D_800FC270, 1304) < (u32)W(o, 13772)) {
            b = 1;
        }
    }
    k[0] = func_8009B670(W(o, 11704));
    t = 32;
    for (i = 0; i < D_800FC270[2572]; i++) {
        if ((u32)W(o, 13772) >= (u32)W((u8 *)W(q, 316) + i * 32, 20)) {
            if ((s8)D_800FC270[i * 12 + 2584] < t) {
                t = D_800FC270[i * 12 + 2584];
            }
        }
    }
    m = t;
    d = (u8 *)((s8)q[284] * 32 + W(q, 316));
    if (d[3] == 0) {
        if (b) {
            res = 486;
        } else if (a) {
            res = 463;
            if (rnd(100) < 70) {
                res = 467;
            }
        } else {
            res = 481;
            if (m < k[0] && m < 4 && rnd(100) >= 21) {
                res = m + 24;
            }
        }
    } else if (d[3] == 1) {
        if ((u32)W(o, 13772) != (u32)W(d, 16)) {
            res = 483;
        } else if (b) {
            res = 487;
        } else if (a) {
            res = 463;
            if (rnd(100) < 70) {
                res = 468;
            }
        } else {
            res = 482;
            if (m < k[0] && m < 4 && rnd(100) >= 21) {
                res = m + 24;
            }
        }
    } else if (d[3] == 2) {
        if ((u32)W(o, 13772) != (u32)W(d, 16)) {
            res = 485;
        } else if (b) {
            res = 488;
        } else if (a) {
            res = 463;
            if (rnd(100) < 70) {
                res = 469;
            }
        } else {
            res = 484;
        }
    }
    if (res != -1 && W(D_800FC270, 2564) != 0) {
        func_800C0110(D_800F3BC0, res, arg, 0);
    }
    W((u8 *)W(q, 316) + (s8)q[284] * 32, 16) = W(o, 13772);
}
