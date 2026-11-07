typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad0[0x68];
    s32 vol;
} Snd;

extern Snd D_800F1AE0;
extern u32 D_800F2714;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_8001D680(Snd *, s32);

#define PL(o) (*(u8 **)((o) + 21356))

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

f32 func_800760C0(u8 *o)
{
    u8 *q;
    u8 *p;
    s32 h;
    f32 r;

    if (PL(o)[426] == 1) {
        h = func_8001D4B8(&D_800F1AE0, 224, 0, 1);
        func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
        q = o + 31156;
        q[452] = 1;
        func_8001D680(&D_800F1AE0, *(s32 *)(q + 468));
        r = *(f32 *)(q + 464);
        if (PL(o)[896] == 0) {
            p = o + 0x87EC;
            p[185] = 0;
            p[184] = 1;
            p[186] = 1;
            p[187] = 0;
        }
    } else {
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        r = (f32)(D_800F2714 >> 19) * 0.000244140625f * 600.0f + 400.0f;
        {
            u8 *t = o + 31156;
            t[452] = 1;
            func_8001D680(&D_800F1AE0, *(s32 *)(t + 468));
        }
    }
    return r;
}
