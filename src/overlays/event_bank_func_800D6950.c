typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 pad[0x68];
    s32 vol;
} Snd;

extern Snd D_800F1AE0;

extern void func_80076334(u8 *p, s32 a, s32 b);
extern void func_800755FC(u8 *p);
extern u8 func_80076940(u8 *p);
extern void func_800A9BE8(u8 *p, s32 a);
extern s32 func_8001D4B8(Snd *s, s32 a, s32 b, s32 c);
extern void func_8001D640(Snd *s, s32 h, s32 v);
extern void func_8009B9EC(s32 a, s32 b);

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
typedef struct Obj {
    u8 pad[0x4EDC];
    s32 tbl[8];
} Obj;

#define TBL(i) (((Obj *)p)->tbl[i])

void func_800D6950(u8 *p)
{
    s32 n;
    s32 m;
    s32 h;

    n = B(0x60C);
    W(0x6164) += 256;
    m = n + 1;
    if (m * 23040 < W(0x6164)) {
        if (n < B(0x613) - 1) {
            B(0x60C) = m;
            func_80076334(p, TBL(B(0x60C)), 0);
            func_800755FC(p);
        } else {
            func_80076334(p, TBL(func_80076940(p)), 1);
            func_800A9BE8(p + 0x45C, 3);
            W(0x6164) = 30720;
            B(0x60F) = 4;
            h = func_8001D4B8(&D_800F1AE0, 210, 0, 1);
            func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
        }
    }
    func_8009B9EC(15360, 0);
}
