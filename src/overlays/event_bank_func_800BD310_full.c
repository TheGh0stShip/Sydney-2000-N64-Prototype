/* Event-bank state-machine update (link VRAM 0x80070D10), ROM 0xBD310..0xBDC00. */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

extern volatile s32 D_800F2744;
extern volatile s32 D_800F2778;
extern char D_800F26E0[];
extern void *D_80070808[];

extern void func_80072064(u8 *);
extern void func_800720A8(u8 *);
extern void func_80071FE8(u8 *, f32);
extern void func_8008350C(u8 *);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);
extern void func_80083AD8(u8 *);
extern void func_80082BEC(u8 *, s32, s32);
extern void func_800B9FA4(void *, s32, s32, f32, s32, s32);
extern void func_800B9E9C(void *, s32, s32, f32, s32);
extern s32 func_800B9BD4(void *, void *, void *, void *, void *, s32);
extern void func_800B9964(void *, void *, void *, void *);
extern void func_800AD9E8(void *);
extern void func_800BB9C0(void *, s32, u8 *);
extern void func_800BB8E0(void *);
extern f32 func_800BB8C0(void *);
extern void func_80082618(u8 *);
extern void func_800AB2A4(char *, s32, s32, u8 *, s32, s32);
extern void func_800CA354(void *);
extern void func_800AD58C(void *, f32, f32, f32);

#define F32(o) (*(s32 *)(obj + (o)))
#define FF(o) (*(f32 *)(obj + (o)))
#define U8(o) (*(u8 *)(obj + (o)))
#define S16(o) (*(s16 *)(obj + (o)))
#define FPTR(o) (*(u8 **)(obj + (o)))
#define K(a) (*(f32 *)(a))

static __inline__ void setf(u8 *p, f32 v) { *(f32 *)(p + 0xC) = v; }
static __inline__ void orflag(u8 *p) { *(s32 *)(p + 0xC0) |= 4; }

void func_800BD310(u8 *obj, void *arg)
{
    f32 a[4];
    f32 c[4];
    f32 b[2];
    s32 dt;
    u8 *o;
    f32 spd = 0.0f;
    f32 v, lim;

    if (arg == 0) return;
    {
        static void *const unused_tbl[] = { &&L0, &&L1, &&L2, &&L3, &&L4, &&L5, &&L6 };
        unsigned int i;
        dt = D_800F2744 - D_800F2778;
        i = F32(0x44D8);
        if (i >= 7) goto end;
        goto *D_80070808[i];
    }
L0:
    {
        s32 t;
        F32(0xF0C) -= 0x100;
        func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0);
        func_800B9964((obj + 0x11C8), a, b, c);
        func_80072064(obj);
        func_800B9E9C((obj + 0x11C8), 0, -1, 1.0f, 0);
        t = F32(0xF14);
        if (t == 1 && F32(0xF0C) <= 0) {
            func_80083AD8(obj);
            func_8008350C(obj);
            func_80082A84(obj, 6, 0, 0, 0, 0);
            func_80082A84(obj, 31, 0, 0, 0, 0);
            F32(0x1048) = 0;
            F32(0x44D8) = t;
            F32(0xF0C) = 0x5A00;
        }
    }
    goto end;
L1:
    {
        s32 t1;
        F32(0xF0C) -= 0x100;
        func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0);
        func_800B9964((obj + 0x11C8), a, b, c);
        func_800B9E9C((obj + 0x11C8), 0, -1, 1.0f, 0);
        t1 = F32(0xF0C);
        if (t1 <= 0) {
            FPTR(0xF1C)[3] = 0;
            FPTR(0xF1C)[2] = 0;
            F32(0x2A54) = 1;
            F32(0x44D8) = 2;
            F32(0xF0C) = F32(0xF10);
        } else if (t1 < 0xF01) {
            if (t1 < 0xC01) {
                func_80082BEC(obj, 31, 32);
            }
        }
    }
    goto end;
L2:
    F32(0xF0C) -= 0x100;
    if (F32(0x4920) == 0) {
        u8 *q = obj + 0x1368;
        func_800BB9C0(q, dt, FPTR(0xF1C));
        func_800BB8E0(q);
        spd = func_800BB8C0(q) * FF(0x48A4);
    }
    if (F32(0x4920) == 1 && F32(0x4914) == 1) {
        F32(0x4920) = 0;
        switch (U8(0x48FC)) {
        case 0:
            spd -= K(0x80070824);
            break;
        case 1:
            {
            s8 *p = (s8 *)FPTR(0x44D0);
            s32 i = U8(0x45F4);
            F32(0x489C) = 0;
            spd = K(0x80070828);
            if ((p + i)[2] == 1) {
                U8(0x45F4) = i + 1;
                func_800720A8(obj);
                if (F32(0x4918) == 1) {
                    func_800B9E9C((obj + 0x11C8), 7, -1, 1.0f, 0);
                    F32(0x4918) = 0;
                } else {
                    func_800B9E9C((obj + 0x11C8), 14, -1, 1.0f, 0);
                }
                U8(0x48FC) = 0;
                F32(0x4910) = 1;
            } else {
                spd = K(0x80070830);
            }
            }
            break;
        case 2:
            {
            u8 *p = FPTR(0x44D0);
            s32 i = U8(0x45F4);
            F32(0x489C) = 0;
            spd = K(0x8007082C);
            if ((u8)((p + i)[2] - 1) < 2) {
                U8(0x45F4) = i + 1;
                func_800720A8(obj);
                if (F32(0x4918) == 1) {
                    func_800B9E9C((obj + 0x11C8), 8, -1, 1.0f, 0);
                    F32(0x4918) = 0;
                } else {
                    func_800B9E9C((obj + 0x11C8), 13, -1, 1.0f, 0);
                }
                U8(0x48FC) = 0;
                F32(0x4910) = 1;
            } else {
                spd = K(0x80070830);
            }
            }
            break;
        case 3:
            F32(0x489C) = 0;
            U8(0x45F4)++;
            func_800720A8(obj);
            spd = K(0x80070834);
            if (F32(0x4918) == 1) {
                func_800B9E9C((obj + 0x11C8), 9, -1, 1.0f, 0);
                F32(0x4918) = 0;
            } else {
                func_800B9E9C((obj + 0x11C8), 12, -1, 1.0f, 0);
            }
            U8(0x48FC) = 0;
            F32(0x4910) = 1;
            break;
        }
        {
            u8 *q = obj + 0x1368;
            v = spd;
            if (spd < (lim = 0.0f) || (lim = K(0x80070838)) < spd) {
                v = lim;
            }
            *(f32 *)(q + 0xC) = v;
            if (spd < 0.0f) spd = 0.0f;
        }
    }
    if (F32(0x4910) == 0) {
        if (FF(0x489C) > K(0x8007083C) && U8(0x48FC) == 2 && F32(0x4914) == 1) {
            U8(0x48FC) = 3;
            F32(0x4914) = 0;
            if (F32(0x4918) == 1) {
                func_800B9E9C((obj + 0x11C8), 6, -1, 2.1f, 0);
            } else {
                func_800B9E9C((obj + 0x11C8), 11, -1, 1.5f, 0);
            }
        } else if (FF(0x489C) > K(0x80070840) && U8(0x48FC) == 1 && F32(0x4914) == 1) {
            U8(0x48FC) = 2;
            F32(0x4914) = 0;
            if (F32(0x4918) == 1) {
                func_800B9E9C((obj + 0x11C8), 5, -1, 2.1f, 0);
            } else {
                func_800B9E9C((obj + 0x11C8), 10, -1, 1.5f, 0);
            }
        } else if (FF(0x489C) > K(0x80070844) && U8(0x48FC) == 0) {
            s32 one;
            U8(0x48FC) = 1;
            F32(0x4914) = 0;
            one = F32(0x4918);
            if (one == 1) {
                func_800B9FA4((obj + 0x11C8), 4, -1, 2.1f, 0, one);
            } else {
                func_800B9E9C((obj + 0x11C8), 1, -1, 0.2f, 0);
            }
        }
    }
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) != 0) {
        if (F32(0x4910) == 1) {
            F32(0x4910) = 0;
            F32(0x44D8) = 3;
        } else {
            F32(0x4914) = 1;
        }
    }
    o = obj + 0x11C8;
    func_800B9964(o, a, b, c);
    goto tail2;
L3:
    {
        u8 *q = obj + 0x1368;
        F32(0xF0C) -= 0x100;
        func_800BB9C0(q, dt, FPTR(0xF1C));
        func_800BB8E0(q);
        spd = func_800BB8C0(q) * FF(0x48A4);
    }
    if (func_800B9BD4((obj + 0x11C8), arg, a, b, c, 0) != 0) {
        F32(0x44D8) = 2;
        F32(0x4914) = 0;
        F32(0x4920) = 0;
        U8(0x4904)++;
        if (U8(0x45F4) == F32(0x4900)) {
            F32(0x44D8) = 4;
            F32(0x491C) = 1;
        }
    }
    o = obj + 0x11C8;
    func_800B9964(o, a, b, c);
    func_80071FE8(obj, -FF(0x121C));
tail2:
    FF(0x121C) = 0.0f;
    func_800AD9E8(o);
timer:
    if (F32(0xF0C) <= 0) {
        F32(0xF0C) = 0;
        F32(0x491C) = 0;
        F32(0x44D8) = 4;
    }
    goto end;
L4:
    F32(0x44D8) = 5;
    goto end;
L5:
    func_8008350C(obj);
    orflag(obj + 0x46F0);
    orflag(obj + 0x4618);
    func_80082A84(obj, 20, 0, 0, 0, 0);
    func_80082A84(obj, 6, 0, 0, 0, 0);
    func_80082A84(obj, 38, F32(0x4900), 0, 0, 0);
    func_80082A84(obj, 39, U8(0x4904), 0, 0, 0);
    if (F32(0x491C) == 1) {
        f32 r, t, u, spd2;
        r = (f32)F32(0xF0C) / K(0x80070848) * K(0x8007084C);
        t = (f32)F32(0xF10) / K(0x80070848) * K(0x8007084C);
        lim = r / t * K(0x80070850);
        if (FF(0x44E4) <= lim) {
            S16(0x11C4) = 100;
        } else if (FF(0x44E0) <= lim) {
            S16(0x11C4) = 90;
        } else {
            S16(0x11C4) = 80;
        }
    } else {
        S16(0x11C4) = 0;
    }
    func_80082618(obj);
    F32(0xF0C) = 0x7800;
    F32(0x44D8) = 6;
    F32(0xF14) = 0;
    goto end;
L6:
    {
        s32 t3 = F32(0xF0C) - 0x100;
        F32(0xF0C) = t3;
        if (F32(0xF14) != 0 && t3 <= 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
        }
    }
end:
    {
        f32 f;
        f32 m = K(0x8007085C);
        FF(0x489C) = f = FF(0x489C) + spd * K(0x80070854) / K(0x80070858);
        if (m < f) {
            FF(0x489C) = m;
        }
    }
    {
        u8 *r = obj + 0x1384;
        *(f32 *)(r + 0x11F0) = FF(0x489C);
        func_800CA354(r);
    }
    {
        f32 f;
        f32 m = K(0x80070864);
        FF(0x4924) = f = FF(0x4924) + K(0x80070860);
        if (m < f) {
            FF(0x4924) = f - m;
        }
    }
    func_800AD58C(obj + 0x47DC, FF(0x4924), 0.0f, 0.0f);
}
