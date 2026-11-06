typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern void *D_80071148[];
extern u8 *D_800FC270;
typedef struct { u8 b[12]; } Ent;
#define E(base, i) ((u8 *)((Ent *)(base) + (i)))
extern u8 D_80077660[];
extern u8 D_8007789C[];
extern u8 D_80077854[];
extern u8 D_80077878[];
extern u8 D_80077768[];
extern u32 D_800779C0;
extern u8 D_800F1AE0[];
extern u8 D_800F2AD8[];
extern void func_8007A5CC(s32, s32, s32, s32, s32);
extern void func_800A9BE8(u8 *, s32);
extern void func_800770C4(u8 *, s32, s32, s32);
extern void func_800762D8(u8 *);
extern void func_800D1574(u8 *, u32);
extern void func_800D6F80(u8 *, u8 *);
extern void func_800ADC38(u8 *);
extern s32 func_8001D4B8(u8 *, s32, s32, s32);
extern void func_8001D640(u8 *, s32, s32);
extern void func_8001D5D8(u8 *, s32, s32, s32, s32, s32);
extern void func_800D33A0(u8 *, u8 *, s32, s32);
extern void func_800A6308(u8 *);
extern void func_800BBD78(void *, s32, s32, void *, s32);
extern void func_800BC180(void *);

static inline s32 play(s32 id, s32 a3, s32 vol)
{
    s32 snd = func_8001D4B8(D_800F1AE0, id, 0, a3);
    func_8001D640(D_800F1AE0, snd, 0);
    func_8001D5D8(D_800F1AE0, snd, (W(D_800F1AE0, 104) * vol) >> 15, 60, 0, 0);
    return snd;
}

static inline s32 chk(s32 x, s32 a, s32 b)
{
    return x == a || x == b;
}

static inline s32 eqm(u32 w, u32 m, u32 k)
{
    return (w & m) == k;
}

static inline void f2u_to(u32 *d, f32 f, f32 c)
{
    u32 r;
    if (!(c <= f)) {
        r = (s32)f;
    } else {
        r = (s32)(f - c) | 0x80000000;
    }
    *d = r;
}

static inline s32 isLit(u8 *o)
{
    return B(o, 426) == 3 || B(o, 426) == 2;
}

static inline u32 f2u(f32 f, f32 c)
{
    if (!(c <= f)) {
        return (s32)f;
    }
    return (s32)(f - c) | 0x80000000;
}

void func_800B1D28(u8 *g)
{
    static void *const keep[] = { &&body, &&end };
    s32 s5;
    u8 s4, s3;
    u8 *p;
    s32 snd;
    s32 v;
    u32 st;

    st = B(g, 0x5b7f);
    if (st >= 6)
        return;
    goto *D_80071148[st];
body:
    s5 = W(D_800FC270, 2560);
    if (B(g, 0x5b7f) == 5) {
        W(g, 0x5b84) = 0x3c00;
    } else {
        W(g, 0x5b84) = 0xb400;
    }
    if (s5 == 4) {
        s4 = eqm(W(g, 0x5b78), 0xff00ffff, 0x07000401);
    } else {
        s4 = eqm(W(g, 0x5b78), 0xff0000ff, 0x07000001);
    }
    W(g, 0x5b74) = 8;
    s3 = (u8)(D_80077660[B(g, 0x5b7b) + B(g, 0x5b78) * 4] - 1) < 2;
    func_8007A5CC(W(g, 21292), B(g, 0x5b8c), B(g, 0x5b8d), s3, s4);
    if (s3 && !s4) {
        func_800A9BE8(g + 22984, 10);
    } else {
        func_800A9BE8(g + 22984, 12);
    }
    if (B(g, 0x5b7f) != 5) {
        func_800770C4(g, B(g, 0x5b8c), B(g, 0x5b8d), s3);
        func_800762D8(g);
        { u8 *q = E(D_800FC270, B(g, 0x5b79));
        F(q, 2580) += SB(g, 0x5b8c); }
        p = D_800FC270 + B(g, 0x5b79) * 12;
        H(p, 2578) = (s32)F(p, 2580) * 60;
        if ((u8)(B(g, 0x5b7f) - 3) < 2) {
            B(g + B(g, 0x5b78), 0x5bcd) += B(g, 0x5b8c);
        }
        {
            u8 *a = g + 23512;
            u8 *q = E(D_800FC270, B(g, 0x5b79));
            f32 ff = F(q, 2580);
            f32 c = *(f32 *)0x80071160;
            u32 r;
            if (!(c <= ff)) {
                r = (s32)ff;
            } else {
                r = (s32)(ff - c);
                r |= 0x80000000;
            }
            func_800D1574(a, r);
        }
        if (B(g, 0x5b8d) == 0) {
            func_800D6F80(g + 11784, D_8007789C);
            func_800ADC38(g + 21916);
            func_800ADC38(g + 22128);
            func_800ADC38(g + 22340);
        } else if (SB(g, 0x5b8c) == 1) {
            func_800D6F80(g + 11784, D_80077854);
            func_800ADC38(g + 21916);
            func_800ADC38(g + 22128);
            func_800ADC38(g + 22340);
            if (B(g, 0x5b7f) != 4) {
                play(114, 1, 32767);
            }
        } else if (SB(g, 0x5b8c) == 2) {
            func_800D6F80(g + 11784, D_80077878);
            func_800ADC38(g + 21916);
            func_800ADC38(g + 22128);
            func_800ADC38(g + 22340);
            if (B(g, 0x5b7f) != 4) {
                play(115, 1, 32767);
            }
        }
        if ((W(g, 0x5b78) & 0xff0000ff) == 0x07000001 && s5 == 5 && s4) {
            u8 *q;
            p = D_800FC270;
            q = E(p, B(g, 0x5b79));
            if (F(q, 2580) > F(p, 3572)) {
                F(p, 3572) = F(q, 2580);
                { u8 *q2 = E(p, B(g, 0x5b79)); B(q2, 2586) |= 2; }
                q = E(D_800FC270, B(g, 0x5b79));
                f2u_to(&D_800779C0, F(q, 2580), *(f32 *)0x80071164);
                func_800D33A0(g + 12020, D_80077768, 1, -1);
            }
        }
    }
    if (W(g, 23456) != 0 && B(g, 0x5b7f) != 4) {
        func_800A6308(g + 19020);
    }
    if (SB(g, 0x5b8c) > 0 && B(g, 0x5b7f) != 4) {
        W(g, 23480) = play(111, -1, 13106);
    }
    func_800BBD78(D_800F2AD8, SB(W(g, 21292), 427), 0, 0, 6);
    func_800BBD78(D_800F2AD8, SB(W(g, 21292), 427), 1, 0, 2);
    if (chk(B((u8 *)W(g, 21292), 426), 3, 2)) {
        func_800BC180(D_800F2AD8);
    }
end:
    func_800BBD78(D_800F2AD8, 13, 1, g, 2);
}
