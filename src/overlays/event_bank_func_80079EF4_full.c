typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define U8(o) (*(u8 *)(a + (o)))
#define S8(o) (*(s8 *)(a + (o)))
#define S16(o) (*(s16 *)(a + (o)))
#define S32(o) (*(s32 *)(a + (o)))
#define F32(o) (*(f32 *)(a + (o)))
typedef struct Obj { char pad[0x1AE]; s16 anim[1]; } Obj;
#define ANIM(i) (((Obj *)a)->anim[i])
#define PTR(o) (*(char **)(a + (o)))

typedef struct Vec4 { f32 x, y, z, w; } Vec4;
typedef struct St { s32 v; u16 anim; } St;
#define U16(o) (*(u16 *)(a + (o)))

extern s32 D_800F2728;
extern s32 D_800F2744;
extern s32 D_800F2778;
extern u32 D_800F13F0;
extern char D_800F26E0[];
extern char D_800F1AE0[];
extern char D_80077470[];
extern f32 D_8007747C;
extern u16 D_8007DD44[];

extern void func_80017B04(s32, f32);
extern s32 func_8001D4B8(char *, s32, s32, s32);
extern void func_8001D5C8(char *, s32, f32, f32, f32);
extern void func_8001D5D8(char *, s32, s32, s32, s32, s32);
extern void func_800764EC(char *);
extern void func_80076560(char *);
extern s8 func_80076C1C(char *, s32);
extern void func_800794D0(char *, Vec4 *, St *, Vec4 *, s32 *, f32 *);
extern void func_80079904(char *, s32 *, Vec4 *, Vec4 *, St *, f32 *);
extern void func_80079CA0(char *, Vec4 *, Vec4 *, St *, s32 *, f32 *);
extern void func_8007C738(char *);
extern void func_8007C914(char *, s32);
extern void func_8007CCCC(char *);
extern void func_8007D274(char *);
extern void func_8007D870(char *, s32);
extern void func_8007D910(char *);
extern void func_8007D9C0(char *, Vec4 *);
extern void func_8007DB20(char *, f32, f32);
extern void func_800AAB54(char *, s32, s32);
extern void func_800AB2A4(void *, s32, s32, void *, void *, s32);
extern void func_800AD4E0(char *, f32, s32);
extern void func_800B8C70(char *, f32);
extern void func_800B9830(char *, s32, Vec4 *, s32, s32);
extern void func_800B9964(char *, Vec4 *, St *, Vec4 *);
extern s32 func_800B9BD4(char *, s32, Vec4 *, St *, Vec4 *, s32);
extern void func_800B9E74(char *, s32);
extern void func_800B9E9C(char *, s32, s32, f32, s32);
extern void func_800B9FA4(char *, s32, s32, f32, s32, s32);
extern void func_800BB8E0(char *);
extern void func_800BB9C0(char *, s32, char *);
extern void func_800BE3AC(char *, char *, f32, s32, s32);
extern void func_800CB838(char *, f32);

static inline void sway(char *a, f32 prev)
{
    f32 t;
    f32 v;
    f32 cur;
    f32 d;

    if (PTR(0x2EC) != 0) {
        t = (F32(0x54) - prev) / 32.767f;
        if (t < 0.0f) {
            t = -t;
        }
        v = t * 30.0f;
        cur = F32(0x2F0);
        d = v - cur;
        if (d != 0.0f) {
            if (d > 0.0f) {
                if (d > 0.075f) {
                    v = cur + 0.075f;
                }
            } else if (d < -0.075f) {
                v = cur - 0.075f;
            }
        }
        *(f32 *)(PTR(0x2EC) + 0x77C) = v;
        F32(0x2F0) = v;
    }
}

static inline s32 vol(s32 v, s32 k)
{
    return (v * k) >> 15;
}

static inline void snap(char *a)
{
    char *p = a + 0x14;
    char *q;

    F32(0x170) = *(f32 *)(p + 0x40);
    q = a + 0x170;
    *(f32 *)(q + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(q + 8) = *(f32 *)(p + 0x48);
    F32(0x188) = *(f32 *)(p + 0x40);
    q = a + 0x188;
    *(f32 *)(q + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(q + 8) = *(f32 *)(p + 0x48);
}

void func_80079EF4(char *a, s32 mode)
{
    char *own;
    Vec4 sp18;
    Vec4 sp28;
    Vec4 sp38;
    St sp48;
    s32 sp50;
    f32 sp54;
    char *o;
    f32 f;

    if (mode != 1) {
        return;
    }
    own = PTR(0x4);
    if (D_800F2728 == mode) {
        sp50 = D_800F2744 - D_800F2778;
    } else {
        sp50 = 0;
    }
    if (*(s32 *)(own + 0xB8) == 1) {
        return;
    }
    switch (S32(0xAC)) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4: {
        Vec4 *v = &sp18;
        St *st = &sp48;
        u16 *an = &sp48.anim;
        char *o = PTR(0x4);
        func_80017B04(0, 0.425971f);
        S32(0xC0) = (S32(0xC0) | 0x600) & ~1;
        if (func_800B9BD4(a, 1, v, st, &sp28, 0) != 0) {
            U8(0x1AD)++;
            sp48.anim = ANIM(U8(0x1AD));
            if ((s16)sp48.anim < 0) {
                if ((s16)sp48.anim == -1) {
                    ANIM(U8(0x1AD)) = -2;
                    sp48.anim = ANIM((U8(0x1AD) + 1));
                    U8(0x1AD)--;
                } else {
                    S32(0xAC) = 5;
                    U8(0x1AD) += 2;
                    sp48.anim = ANIM(U8(0x1AD));
                    func_80076560(o);
                }
            }
            func_800B9E9C(a, (s16)*an, -1, F32(0x278), 0);
        }
        func_800B9964(a, v, st, &sp28);
        break;
    }
    case 5: {
        Vec4 *v = &sp18;
        St *st = &sp48;
        char *o = PTR(0x4);
        S32(0xC0) = (S32(0xC0) & ~0x600) | 0x02000000;
        if (func_800B9BD4(a, 1, v, st, &sp28, 0) != 0) {
            U8(0x1AD)++;
            sp48.anim = ANIM(U8(0x1AD));
            if ((s16)sp48.anim < 0) {
                if ((s16)sp48.anim == -1) {
                    ANIM(U8(0x1AD)) = -2;
                    U8(0x1AD)--;
                    func_800B9E9C(a, 0x25, -1, F32(0x278), 0);
                    func_800AB2A4(D_800F26E0, D_800F2744, 0xC, o, 0, U8(0x2DD));
                } else {
                    U8(0x2E8) = 1;
                    S32(0x4E8) = S32(0x31C);
                    func_800B9E74(a, 2);
                    S32(0xAC) = 7;
                }
            } else {
                func_800B9E9C(a, (s16)sp48.anim, -1, F32(0x278), 0);
            }
        }
        func_800B9964(a, v, st, &sp28);
        break;
    }
    case 7:
        S32(0xC0) = (S32(0xC0) & ~0x600) | 0x02000000;
        if (U8(0x2E8) != 0) {
            func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
            func_800B9964(a, &sp18, &sp48, &sp28);
            U8(0x2E8) = 0;
        }
        S32(0x4E8) -= 0x100;
        if (S32(0x4E8) <= 0) {
            {
                char *t = a + 0x4FC;
                *(s32 *)(t + 0xC0) |= 4;
            }
            func_800B8C70(a, F32(0x278));
            S32(0x5DC) = -1;
            S32(0xAC) = 8;
        }
        break;
    case 8:
        S32(0xC0) = (S32(0xC0) & ~0x600) | 0x02000000;
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 0xD, own, 0, U8(0x2DD));
            S32(0xAC) = 9;
            if (U8(0x5D1) != 0) {
                func_800AD4E0(a + 0x510, 3.1415923f, 3);
                U8(0x5D1) = 0;
            }
        }
        func_800B9964(a, &sp18, &sp48, &sp28);
        break;
    case 10: {
        s32 r;
        r = func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
        func_800B9964(a, &sp18, &sp48, &sp28);
        if (r != 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 0xE, own, 0, U8(0x2DD));
            F32(0x2F0) = 0.0f;
            S16(0x2EA) = 0xA;
            S8(0x2E9) = -2;
            U8(0x2DF) = 0;
            U8(0x2E1) = 0;
            func_800B9FA4(a, D_8007DD44[U8(0x2E2)], -1, 0.0f, 0, 1);
            F32(0x174) = 0.0f;
            func_800B8C70(a, 0.0f);
            func_800B9E9C(a, 0x2E, -1, 0.0f, 0);
            F32(0x4EC) = 0.1441748f;
            {
                char *t = a + 0x4EC;
                *(f32 *)(t + 4) = 0.0f;
                *(f32 *)(t + 8) = 0.0f;
            }
            {
                char *t = a + 0x2F4;
                *(f32 *)(t + 8) = 0.0f;
                *(f32 *)(t + 0x10) = 1.0f;
            }
            S32(0x4E4) = 0;
            S32(0xAC) = 0xC;
        }
        break;
    }
    case 15: {
        s32 hit = 0;
        char *t;
        if (*(s32 *)(own + 0x5428) < sp50 || (PTR(0x288)[3] & 3)) {
            hit = 1;
        }
        t = a + 0x2F4;
        if (hit != 0) {
            *(f32 *)(t + 8) = 0.05f;
            *(f32 *)(t + 0x10) = 0.95f;
            S32(0xAC) = 0x10;
        }
    }
    case 16:
        func_80079CA0(a, &sp18, &sp28, &sp48, &sp50, &sp54);
        break;
    case 26: {
        s32 r;
        func_8007CCCC(a);
        o = a + 0x2F4;
        func_800BB9C0(o, sp50, PTR(0x288));
        func_800BB8E0(o);
        func_8007DB20(a, 0.2f, 1.5f);
        r = func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
        sp54 = F32(0x54);
        func_800B9964(a, &sp18, &sp48, &sp28);
        sway(a, sp54);
        if (r != 0) {
            func_8007D910(a);
            if (U8(0x2DF) != 0) {
                func_800B9830(a, 0x2F, &sp38, 0, 0);
                F32(0x310) -= sp38.z;
            } else {
                f32 x, y, z;
                s32 id;
                func_800B9830(a, 0x2E, &sp38, 0, 0);
                x = F32(0x54);
                y = F32(0x58);
                z = F32(0x5C);
                F32(0x310) += sp38.z;
                id = func_8001D4B8(D_800F1AE0, 0xFE, 2, -1);
                func_8001D5C8(D_800F1AE0, id, x, y, z);
                func_8001D5D8(D_800F1AE0, id, vol(*(s32 *)(D_800F1AE0 + 0x68), 0x3FFF), 0xF, 0, 0);
                S32(0x5DC) = id;
            }
            func_8007D9C0(a, &sp18);
            sway(a, sp54);
            S32(0xAC) = 0x11;
        }
        break;
    }
    case 17:
        func_80079904(a, &sp50, &sp18, &sp28, &sp48, &sp54);
        break;
    case 24:
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            func_800B9FA4(a, 0x30, -1, F32(0x278), 0, 1);
        }
        f = F32(0x310);
        if (f <= 114.684494f) {
            if (f <= 91.7476f) {
                func_800B9FA4(a, 0x3A, -1, 1.0f, 0, 1);
                func_800B9E74(a, 2);
                S32(0xAC) = 0x19;
            } else {
                if (f <= F32(0x318)) {
                    func_800AAB54(a, 0x10, sp50);
                }
                if (PTR(0x288)[3] & 0x10) {
                    char *t = a + 0x2F4;
                    f32 v = *(f32 *)(t + 0xC) + 0.1f;
                    if (v < 0.0f) {
                        v = 0.0f;
                    } else if (v > 1.0f) {
                        v = 1.0f;
                    }
                    *(f32 *)(t + 0xC) = v;
                    func_8007DB20(a, 0.2f, 1.5f);
                    func_800B9FA4(a, 0x39, -1, 1.1f, 0, 1);
                    func_800B9E74(a, 2);
                    S32(0xAC) = 0x19;
                }
            }
        }
        sp54 = F32(0x54);
        func_8007D9C0(a, 0);
        sway(a, sp54);
        func_8007CCCC(a);
        break;
    case 25:
        func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
        func_800BE3AC(a, D_80077470, 1726.8208f, 1, 0);
        sp54 = F32(0x54);
        func_8007D9C0(a, 0);
        sway(a, sp54);
        func_8007CCCC(a);
        snap(a);
        break;
    case 20:
        func_800794D0(a, &sp18, &sp48, &sp28, &sp50, &sp54);
        break;
    case 23:
        func_8007CCCC(a);
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            S32(0xAC) = 0x15;
            func_800B9830(a, 0x31, &sp38, 0, 0);
            F32(0x310) += sp38.z;
        } else {
            sp54 = F32(0x54);
            func_800B9964(a, &sp18, &sp48, &sp28);
            sway(a, sp54);
            F32(0x54) += F32(0x330);
            F32(0x170) += F32(0x330);
        }
        break;
    case 21:
        func_8007CCCC(a);
        sp54 = F32(0x54);
        func_8007D9C0(a, 0);
        sway(a, sp54);
        if (F32(0x4EC) > 0.1441748f) {
            F32(0x4EC) -= 0.0065534003f;
        }
        func_800BE3AC(a, D_80077470, D_8007747C, 1, 0);
        break;
    case 22:
        func_8007CCCC(a);
        sp54 = F32(0x54);
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            func_800B9964(a, &sp18, &sp48, &sp28);
            func_8007D910(a);
            S32(0xAC) = 0x1A;
            snap(a);
            S32(0x174) = 0;
            F32(0x178) = F32(0x32C);
            func_8007CCCC(a);
            func_8007C914(a, 1);
            func_800B9830(a, 0x32, &sp38, 0, 0);
            F32(0x310) += sp38.z;
            func_800B9FA4(a, 0x2F, -1, F32(0x278), 0, 1);
            func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
        }
        func_800B9964(a, &sp18, &sp48, &sp28);
        sway(a, sp54);
        break;
    case 28:
        func_800CB838(a + 0x40C, 65.534f);
        func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0);
        func_800B9964(a, &sp18, &sp48, &sp28);
        snap(a);
        S32(0x174) = 0;
        S32(0x18C) = 0;
        S32(0xAC) = 0x1E;
        break;
    case 30:
        S8(0x2E5) = func_80076C1C(own, U8(0x2DD));
        func_8007C738(a);
        func_800B9E74(a, 4);
        sp48.anim = ANIM(U8(0x1AD));
        func_800B9FA4(a, (s16)sp48.anim, -1, F32(0x278), 0, 1);
        U8(0x1AD)++;
        sp48.anim = ANIM(U8(0x1AD));
        func_800B9E9C(a, (s16)sp48.anim, -1, F32(0x278), 0);
        snap(a);
        S32(0x174) = 0;
        S32(0xAC) = 0x1F;
    case 31:
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            U8(0x1AD)++;
            sp48.anim = ANIM(U8(0x1AD));
            if ((s16)sp48.anim >= 0) {
                func_800B9E9C(a, (s16)sp48.anim, -1, F32(0x278), 0);
            } else {
                func_8007D870(a, (s16)sp48.anim);
            }
        }
        func_800B9964(a, &sp18, &sp48, &sp28);
        break;
    case 37:
        if (S32(0x4E4) < 0x1200) {
            if (S32(0x4E4) > 0x600) {
                D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
                if ((D_800F13F0 >> 26) == 0) {
                    func_800B8C70(a, F32(0x324));
                    S32(0x4E4) = 0x1200;
                }
            }
            S32(0x4E4) += 0x100;
        }
        if (func_800B9BD4(a, 1, &sp18, &sp48, &sp28, 0) != 0) {
            func_800B8C70(a, F32(0x324));
            func_800B9E9C(a, 0x30, -1, F32(0x324), 0);
        } else if (F32(0x58) < -3.2766998f) {
            func_800764EC(own);
        }
        func_800B9964(a, &sp18, &sp48, &sp28);
        break;
    }
    func_8007D274(a);
}
