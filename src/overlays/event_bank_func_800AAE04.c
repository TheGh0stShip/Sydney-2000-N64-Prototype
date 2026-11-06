typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define X8(o) (*(u8 *)(obj + 0x8000 + (o)))
#define XS8(o) (*(s8 *)(obj + 0x8000 + (o)))
#define X32(o) (*(s32 *)(obj + 0x8000 + (o)))
#define XP(o) (*(u8 **)(obj + 0x8000 + (o)))
#define S32(o) (*(s32 *)(obj + (o)))
#define F32(o) (*(f32 *)(obj + (o)))
#define CTX (*(u8 **)(obj + 11704))
typedef struct {
    s16 h0;
    s8 b2;
    u8 b3;
    s32 slot[3];
    s32 w16;
    s32 w20;
    s32 w24;
    s32 w28;
} Ent;

typedef struct {
    s32 a;
    f32 b;
    s32 c;
} Slot12;

#define ENTS (*(Ent **)(obj + 0x8000 + 316))
#define ENTP (&ENTS[XS8(284)])
typedef struct { u8 pad[2576]; Slot12 slot[4]; } Game;
#define SLOT (((Game *)D_800FC270)->slot[XS8(284)])

typedef struct {
    u8 pad[16];
    s16 off;
    s16 pad2;
    void (*fn)(u8 *p, u8 *arg);
} VTab;

#define VCALL(p, a) ((*(VTab **)((p) + 180))->fn((p) + (*(VTab **)((p) + 180))->off, (a)))

extern s32 D_800F2780;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern s32 D_800F1270[2];
extern u8 D_80077B88[];
extern u8 D_80077B58[];
extern u8 D_80077B70[];
extern s32 D_80077B80;
extern s32 D_80077C78;
extern u8 D_800F4D00[];
extern volatile s32 D_800F2728;
extern volatile s32 D_800F2724;
extern u8 D_800F1280[];
extern u8 *D_800FC270;
extern u8 D_800F1AE0[];
extern s32 D_800F13F0;
extern u8 D_800F2AD8[];

extern void func_800AB2A4(u8 *p, s32 a, s32 b, u8 *obj, s32 c, s32 d);
extern void func_800773AC(u8 *obj);
extern void func_8007542C(u8 *obj, s32 a);
extern void func_800B31EC(s32 a);
extern void func_800D33A0(u8 *p, u8 *q, s32 a, s32 b);
extern void func_800ADC38(u8 *p);
extern void func_800ADC54(u8 *p, s32 mask);
extern void func_800B360C(u8 *p, u8 *q);
extern void func_800B2158(u8 *p, s32 a);
extern void func_800B3254(u8 *p, s32 a);
extern s32 func_80076F30(u8 *obj);
extern void func_80076390(u8 *obj, s32 a);
extern void func_80075BD0(u8 *obj);
extern void func_800D29E0(u8 *p);
extern void func_800A9BE8(u8 *p, s32 a);
extern s32 func_8009BFE8(s32 a, u8 *p, s32 b, f32 c);
extern s32 func_8001D4B8(u8 *p, s32 a, s32 b, s32 c);
extern void func_8001D640(u8 *p, s32 a, s32 b);
extern void func_800768AC(u8 *obj);
extern void func_80097FAC(u8 *p, s32 a, f32 b, u8 *c, s32 d, s32 e);
extern void func_80096860(u8 *p, s32 a, s32 b, s32 c);
extern void func_800758C8(u8 *obj);
extern void func_8009BD48(s32 a);
extern void func_800D771C(u8 *p);
extern void func_800A3394(u8 *p, s32 a, s32 b, s32 c);
extern void func_800A31BC(u8 *p);
extern void func_800770AC(u8 *obj);
extern void func_800A62EC(u8 *p);
extern void func_800AC334(u8 *p);
extern void func_800AC37C(u8 *p, u8 *obj);
extern void func_800AC25C(u8 *obj, s32 a, s32 b, s32 c);
extern s32 func_8007704C(u8 *obj);
extern void func_800759C8(u8 *obj);
extern s32 func_80076FDC(u8 *obj);
extern void func_8009B0E4(s32 a, s32 b, u8 *p, s32 c, s32 d, s32 e, s32 f);
extern void func_80076BE0(u8 *obj);
extern void func_800BC180(u8 *p);
extern void func_800BBD78(u8 *p, s32 a, s32 b, u8 *obj, s32 c);
extern void func_8009B9EC(s32 a, s32 b);
extern void func_80097770(u8 *p);

static __inline__ s32 scale15(s32 x, s32 k)
{
    return (x * k) >> 15;
}

static __inline__ void play_sfx(s32 id)
{
    u8 *snd = D_800F1AE0;
    s32 h = func_8001D4B8(snd, id, 0, 0);
    func_8001D640(snd, h, scale15(*(s32 *)(snd + 104), 32767));
}

void func_800AAE04(u8 *obj, s32 arg)
{
    s32 flag;
    u8 *p;
    u8 *pa;
    u8 *pb;
    u8 *pc;
    u8 *pd;
    u8 *q;
    u8 *qb;
    u8 sel;
    u8 res;
    u32 v;
    f32 fv;
    s32 i;
    u32 k;
    s32 r;
    s32 r2;
    Ent *e;
    u8 *m;
    u8 sv;
    u8 *p2;
    u8 *q2;

    flag = 1;
    if (arg == 0)
        return;
    if (X32(332) != 0) {
        D_800F2780 -= 256;
        if (D_800F2780 <= 0) {
            S32(32616) = 15;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 9);
        }
    }
    switch (X8(285)) {
    case 0:
        break;
    case 1:
        if (X32(304) > 0) {
            X32(304) -= 256;
            if (X32(304) <= 0) {
                func_800773AC(obj);
                X32(348) = 0;
                func_8007542C(obj, 0);
            }
        }
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        if (X8(286) != 2) {
            D_800F1270[0] = S32(13772);
            D_800F1270[1] = 0;
            if (CTX[426] == 1 && S32(13772) != 300) {
                func_800B31EC(3);
                if (X8(286) == 3)
                    func_800D33A0(obj + 11928, D_80077B88, 0, -1);
                else
                    func_800D33A0(obj + 11928, D_80077B88, 0, 35);
                pa = obj + 11928;
                func_800ADC38(pa);
                q = D_800F4D00;
                VCALL(pa, q);
                func_800ADC54(pa, 1 << *(s32 *)(q + 216));
                pa[176] = 1;
                if (X8(286) != 3 && S32(13772) != 300) {
                    pb = obj + 13328;
                    func_800B360C(pb, D_80077B58);
                    func_800B2158(pb, 1);
                    func_800ADC38(pb);
                    func_800B3254(pb, 0x80000);
                    VCALL(pb, q);
                    func_800ADC54(pb, 1 << *(s32 *)(q + 216));
                    pb[176] = 1;
                    if (func_80076F30(obj) != 0)
                        D_80077B80 = 7;
                    else
                        D_80077B80 = 9;
                    pc = obj + 13548;
                    func_800B360C(pc, D_80077B70);
                    func_800B2158(pc, 1);
                    func_800ADC38(pc);
                    qb = D_800F4D00;
                    VCALL(pc, qb);
                    func_800ADC54(pc, 1 << *(s32 *)(qb + 216));
                    pc[176] = 1;
                    pd = obj + 30776;
                    S32(30972) = S32(29924);
                    *(u32 *)(pd + 192) |= 0x20000;
                    pd[201] = 1;
                    F32(30936) = 301.0f;
                    F32(30940) = 172.0f;
                    func_800ADC38(pd);
                    VCALL(pd, qb);
                    func_800ADC54(pd, 1 << *(s32 *)(qb + 216));
                    pd[176] = 1;
                }
            }
            S32(13768) = 0;
            func_8007542C(obj, 1);
        }
        if (CTX[426] == 1 || D_80077C78 != 0) {
            if (X8(286) != 2 && S32(13772) != 300)
                goto skip1;
        }
        func_800AB2A4(D_800F26E0, D_800F2744 + 15360, 17, CTX, 0, 1);
        func_80076390(obj, 15360);
    skip1:
        X8(285) = 2;
        break;
    case 4:
        func_80075BD0(obj);
        flag = 0;
        if (X32(308) != 0) {
            X32(300) -= 256;
            if (X32(300) > 0)
                break;
            X32(300) = 0;
            X32(308) = 0;
            S32(7212) = 0;
            func_800D29E0(obj + 696);
        } else {
            if (D_800F2728 != 0)
                break;
            D_800F2724 = 1;
        }
        break;
    case 5:
        func_80075BD0(obj);
        flag = 0;
        if (X32(308) == 0)
            break;
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        X32(300) = 0;
        X32(308) = 0;
        S32(7212) = 0;
        func_800D29E0(obj + 696);
        func_800A9BE8(obj + 32620, 4);
        break;
    case 11:
        flag = 0;
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        switch (X8(286)) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            X32(300) = 0x9600;
            X8(285) = 18;
            break;
        case 2:
            X32(300) = 15360;
            X8(285) = 20;
            break;
        }
        break;
    case 18:
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        sel = ENTP->b2;
        res = 0;
        if (sel < 3)
            v = ENTP->slot[sel];
        else
            v = ENTP->slot[2];
        if (v != 0) {
            D_800F1270[0] = v;
            D_800F1270[1] = 0;
            m = D_800F1280;
            *(s32 *)(m + 16) = 616;
            fv = v;
            if (func_8009BFE8(9, (u8 *)&SLOT, X8(286), fv) != 0) {
                *(s32 *)(m + 16) = 623;
                res = 1;
            }
            if (*(s32 *)(D_800FC270 + 2560) == 4 && *(f32 *)(D_800FC270 + 1348) < fv) {
                *(s32 *)(m + 16) = 622;
                res = 1;
            }
            if (*(s32 *)(D_800FC270 + 2560) == 5 && *(f32 *)(D_800FC270 + 3584) < fv) {
                *(s32 *)(D_800F1280 + 16) = 624;
                res = 1;
            }
            i = *(s32 *)(D_800FC270 + 2560);
            if (i == 4 || i == 0 || i == 1 || i == 2) {
                if (X8(286) != 4 && *(f32 *)(D_800FC270 + 1304) < fv) {
                    *(s32 *)(D_800F1280 + 16) = 621;
                    res = 1;
                }
            }
        } else {
            *(s32 *)(D_800F1280 + 16) = 566;
            res = 2;
        }
        func_800D33A0(obj + 696, D_800F1280, 1, -1);
        if (res == 0)
            play_sfx(192);
        else if (res == 1)
            play_sfx(220);
        else
            play_sfx(200);
        func_800768AC(obj);
        switch (X8(286)) {
        case 5:
            X8(285) = 19;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            if (CTX[426] != 3) {
                func_80097FAC(obj + 13784, 9, SLOT.b, (u8 *)ENTP->slot, sel, 0);
                func_80096860(obj + 13784, 9, *(s32 *)(CTX + 420), 0);
            }
            X8(285) = 19;
            break;
        }
        break;
    case 19:
        switch (X8(286)) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
            func_800A9BE8(obj + 32620, 5);
            X32(300) = 0x9600;
            X32(304) = 30720;
            break;
        case 2:
            break;
        }
        X8(285) = 20;
        break;
    case 20:
        if (X32(304) > 0) {
            X32(304) -= 256;
            if (X32(304) <= 0)
                func_800D29E0(obj + 696);
        }
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        func_800758C8(obj);
        switch (X8(286)) {
        case 0:
        case 1:
            X8(285) = 22;
            break;
        case 5:
            X8(285) = 23;
            break;
        case 2:
            X8(286) = 3;
            X8(285) = 0;
            func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
            SLOT.b = -1.0f;
            ENTP->w20 = 0;
            ENTP->w16 = 0;
            ENTP->b3 = 0;
            ENTP->h0 = 0;
            ENTP->b2 = -1;
            ENTP->w24 = 0;
            for (k = 0; k < 3; k++)
                ENTP->slot[k] = -1;
            S32(13772) = 150;
            func_8009BD48(X8(286));
            break;
        case 3:
        case 4:
            func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
            break;
        }
        D_800F2728 = 0;
        break;
    case 22:
        sv = X8(286);
        X8(286) = 5;
        X8(287) = sv;
        func_800758C8(obj);
        q2 = D_800F4D00;
        p2 = obj + 32392;
        VCALL(p2, q2);
        func_800ADC54(p2, 1 << *(s32 *)(q2 + 216));
        p2[176] = 1;
        func_800ADC38(p2);
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
    case 23:
        func_800770AC(obj);
        func_800A62EC(obj + 6296);
        func_800AC334(obj + 7244);
        func_800AC37C(obj + 7244, obj);
        func_800AC25C(obj, 100, 18, 0);
        r2 = X32(328);
        if (r2 == 0)
            r2 = 1;
        D_800F13F0 = r2;
        X32(300) = 0;
        X8(285) = 2;
        break;
    case 24:
        r = func_8007704C(obj);
        func_800759C8(obj);
        if (func_80076FDC(obj) != 0 || r != 0) {
        if (r != 0)
            func_8009B0E4(234, 1, obj + 19048, 2, 1, 0, 0);
        else
            func_8009B0E4(234, 1, obj + 19048, 2, 0, 0, 0);
        func_80076BE0(obj);
        func_800A9BE8(obj + 32620, 6);
        func_800D29E0(obj + 696);
        X32(300) = 0x1C200;
        func_800BC180(D_800F2AD8);
        func_800BBD78(D_800F2AD8, 13, 1, obj, 2);
        X8(285) = 21;
        break;
        }
        X8(285) = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
        break;
    case 21:
        X32(300) -= 256;
        if (X32(300) > 0)
            break;
        func_800D771C(obj + 19048);
        X8(285) = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 24, obj, 0, 0);
        break;
    }
    if (flag)
        func_8009B9EC(15360, 0);
    {
        u8 *t = obj + 13784;
        if (*(s32 *)(t + 5260) != 0)
            func_80097770(t);
    }
}
