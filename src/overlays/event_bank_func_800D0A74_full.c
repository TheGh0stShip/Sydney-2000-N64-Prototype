typedef int s32; typedef unsigned int u32; typedef float f32;
typedef signed char s8; typedef unsigned char u8; typedef unsigned short u16; typedef short s16;

#define I(o) (*(s32 *)((u8 *)p + (o)))
#define U(o) (*(u32 *)((u8 *)p + (o)))
#define F(o) (*(f32 *)((u8 *)p + (o)))
#define B(o) (*(s8 *)((u8 *)p + (o)))
#define H(o) (*(u16 *)((u8 *)p + (o)))
#define K(a) (*(f32 *)(a))
#define CVT(x, c) (!(K(c) <= (x)) ? (s32)(x) : ((s32)((x) - K(c)) | 0x80000000))

extern s32 D_800F2744;
extern s32 D_800F2778;
extern u8 D_800F1AE0[];
extern u8 D_800F26E0[];

extern s32 func_800B9BD4(void *, s32, void *, void *, void *, s32);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_80083AD8(void *);
extern void func_8008350C(void *);
extern void func_80082A84(void *, s32, s32, s32, s32, s32);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_80083580(void *, s32);
extern void func_800B9FA4(void *, s32, s32, f32, s32, s32);
extern void func_80082BEC(void *, s32, s32);
extern void func_800BB9C0(void *, s32, s32);
extern void func_800BB8E0(void *);
extern f32 func_800BB8C0(void *);
extern void func_80083624(void *, s32, s32, s32, s32, s32);
extern void func_800C9EF8(void *, u8);
extern void func_800B8C70(void *, f32);
extern void func_800B9E9C(void *, s32, s32, f32, s32);
extern void func_80071A7C(void *);
extern void func_80082618(void *);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);

static __inline__ s32 scale_vol(s32 v, s32 m)
{
    return (v * m) >> 15;
}

void func_800D0A74(u8 *p, s32 arg1)
{
    f32 a[4];
    f32 g;
    f32 b[4];
    f32 c[2];
    s32 d;
    s32 k;
    s32 v;
    s32 s0;
    s32 st;
    f32 f;
    u8 *q;

    if (arg1 == 0) {
        return;
    }
    d = D_800F2744 - D_800F2778;
    switch (I(17124)) {
    case 0: goto L0;
    case 1: goto L1;
    case 2: goto L2;
    case 3: goto L3;
    case 4: goto L4;
    case 5: goto L5;
    case 6: goto L6;
    case 7: goto L7;
    }
    return;

L0:
    {
    u8 *q0 = p + 4552;
    func_800B9BD4(q0, arg1, a, c, b, 0);
    func_800B9964(q0, a, c, b);
    }
    {
    s32 t0 = I(3852) - 256;
    s0 = I(3860);
    I(3852) = t0;
    if (s0 == 1 && t0 <= 0) {
        func_80083AD8(p);
        func_8008350C(p);
        func_80082A84(p, 19, 0, 0, 0, 0);
        func_80082A84(p, 31, 0, 0, 0, 0);
        I(4168) = 0;
        I(17124) = s0;
        I(3852) = 23040;
    }
    }
    goto L_c64;

L1:
    {
    s32 t1 = I(3852) - 256;
    I(3852) = t1;
    if (t1 <= 0) {
        u8 *snd = D_800F1AE0;
        s32 h = func_8001D4B8(snd, 87, 0, 1);
        func_8001D640(snd, h, scale_vol(*(s32 *)(snd + 104), 32767));
        ((u8 *)I(3868))[3] = 0;
        ((u8 *)I(3868))[2] = 0;
        func_80083580(p, 32);
        I(18336) = 0;
        I(10836) = 1;
        I(17124) = 5;
        I(3852) = I(3856);
        F(18292) = F(4928);
        func_800B9FA4(p + 4552, 1, -1, 0.8f, 0, 1);
        B(18310) = 1;
        B(18312) = 5;
    } else if (t1 < 3841) {
        if (t1 < 3073) {
            func_80082BEC(p, 31, 32);
        }
    }
    }
L_c64:
    F(4924) = 9.8301f;
    return;

L5:
    q = p + 4968;
    I(3852) -= 256;
    func_800BB9C0(q, d, I(3868));
    func_800BB8E0(q);
    F(18248) = func_800BB8C0(q) * 20.0f;
    if (F(18248) <= 0.1f) {
        F(18248) = 0.1f;
    }
    F(18264) -= F(18248) * 0.125f;
    if (I(18344) == 0) {
        F(18272) -= F(18248) * 0.125f;
    }
    g = F(18264); U(18296) = (u32)(g);
    func_80083624(p, 58, I(18296), 0, 0, 0);
    {
        f32 tot = F(18268);
        tot = (tot - F(18272)) / tot;
        func_800C9EF8(p + 9624, (u32)(tot * 10.0f));
    }
    q = p + 4552;
    func_800B8C70(q, F(18248));
    F(18240) = func_800BB8C0(p + 4968);
    if (0.04f <= F(18240) && I(18324) == 1) {
        B(18312) = 1;
        func_800B9E9C(q, 3, -1, F(18248), 0);
        I(18324) = 0;
    }
    q = p + 4552;
    if (func_800B9BD4(q, arg1, a, c, b, 0) == 0) {
        goto tail;
    }
    I(18324) = 0;
    switch (B(18312)) {
    case 5:
        B(18312) = -1;
        break;
    case 1:
    M_1:
        I(18316) = 0;
        B(18312) = 2;
        break;
    case -1:
        func_800B9E9C(q, 2, -1, F(18248), 0);
        I(18324) = 1;
        break;
    case 2:
        goto M_2b;
    }
    goto tail;

L6:
    q = p + 4968;
    I(3852) -= 256;
    func_800BB9C0(q, d, I(3868));
    func_800BB8E0(q);
    F(18248) = func_800BB8C0(q) * 10.0f;
    if (F(18248) <= 0.35f) {
        F(18248) = 0.35f;
    }
    F(18264) -= F(18248) * 0.25f;
    if (I(18344) == 0) {
        F(18272) -= F(18248) * 0.25f;
    }
    g = F(18264); U(18296) = (u32)(g);
    func_80083624(p, 58, I(18296), 0, 0, 0);
    {
        f32 tot = F(18268);
        tot = (tot - F(18272)) / tot;
        func_800C9EF8(p + 9624, (u32)(tot * 10.0f));
    }
    q = p + 4552;
    func_800B8C70(q, F(18248));
    F(18240) = func_800BB8C0(p + 4968);
    if (0.08f <= F(18240) && I(18324) == 1) {
        B(18312) = 1;
        func_800B9E9C(q, 5, -1, F(18248), 0);
        I(18324) = 0;
    }
    if (F(18240) <= 0.04f && I(18324) == 1) {
        B(18312) = 3;
        func_800B9E9C(p + 4552, 8, -1, F(18248), 0);
        I(18324) = 0;
    }
    if (func_800B9BD4(p + 4552, arg1, a, c, b, 0) == 0) {
        goto tail;
    }
    I(18324) = 0;
    switch (B(18312)) {
    case 1:
        goto M_1;
    case 0: goto tail;
    case 2: goto M_2;
    case -1: goto M_m1;
    case 3: goto M_3;
    case 4: goto M_4;
    }
    goto tail;
M_2:
    B(18312) = -1;
    st = 7;
    goto set_state;
M_m1:
    func_800B9E9C(p + 4552, 4, -1, F(18248), 0);
    I(18324) = 1;
    goto tail;
M_3:
    B(18312) = 4;
    goto tail;
M_4:
    B(18312) = -1;
    st = 5;
    goto set_state;

L7:
    q = p + 4968;
    I(3852) -= 256;
    func_800BB9C0(q, d, I(3868));
    func_800BB8E0(q);
    F(18248) = func_800BB8C0(q);
    F(18248) *= F(18244);
    f = 0.5f;
    if (F(18248) <= f) {
        F(18248) = f;
    }
    F(18264) -= F(18248) * f;
    if (I(18344) == 0) {
        F(18272) -= F(18248) * f;
    }
    g = F(18264); U(18296) = (u32)(g);
    func_80083624(p, 58, I(18296), 0, 0, 0);
    {
        f32 tot = F(18268);
        tot = (tot - F(18272)) / tot;
        func_800C9EF8(p + 9624, (u32)(tot * 10.0f));
    }
    q = p + 4552;
    func_800B8C70(q, F(18248));
    F(18240) = func_800BB8C0(p + 4968);
    if (F(18240) <= 0.08f && B(18312) == -1) {
        B(18312) = 1;
        func_800B9E9C(q, 7, -1, F(18248), 0);
    }
    q = p + 4552;
    if (func_800B9BD4(q, arg1, a, c, b, 0) == 0) {
        goto tail;
    }
    switch (B(18312)) {
    case 1:
        B(18312) = 2;
        break;
    case 2:
    M_2b:
        B(18312) = -1;
        st = 6;
    set_state:
        I(17124) = st;
        break;
    case -1:
        func_800B9E9C(q, 6, -1, F(18248), 0);
        break;
    }
tail:
    func_800B9964(p + 4552, a, c, b);
    func_80071A7C(p);
    return;

L2:
    func_8008350C(p);
    func_80082A84(p, 19, 0, 0, 0, 0);
    func_80082A84(p, 20, 0, 0, 0, 0);
    func_80082A84(p, 38, (u32)(F(18268)), 0, 0, 0);
    if (I(18328) != 0) {
        k = (u32)F(18268);
    } else if (F(18272) > 0.0f) {
        k = (u32)(F(18268) - F(18272));
    } else {
        k = (u32)F(18268);
    }
    func_80082A84(p, 39, k, 0, 0, 0);
    if (I(18328) == 1) {
        f32 pct = F(18276) / F(18280) * 100.0f;
        if ((f32)(s32)H(18232) <= pct) {
            *(s16 *)(p + 4548) = 100;
        } else if ((f32)(s32)H(18230) <= pct) {
            *(s16 *)(p + 4548) = 90;
        } else {
            *(s16 *)(p + 4548) = 80;
        }
    } else {
        *(s16 *)(p + 4548) = 0;
    }
    func_80082618(p);
    I(3852) = 30720;
    I(17124) = 3;
    I(3860) = 0;
    return;

L3:
    v = I(3852) - 256;
    I(3852) = v;
    if (I(3860) != 0 && v <= 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 7);
    }
L4:
    return;
}
