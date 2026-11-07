typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define S32(o) (*(s32 *)(obj + (o)))
#define F32(o) (*(f32 *)(obj + (o)))

extern s32 D_800F2744;
extern s32 D_800F2778;
extern u8 D_800F26E0[];
extern u8 D_800F1AE0[];

extern void func_80070CEC(u8 *obj);
extern void func_80083AD8(u8 *obj);
extern void func_8008350C(u8 *obj);
extern void func_80082A84(u8 *obj, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_80082BEC(u8 *obj, s32 a, s32 b);
extern void func_80082618(u8 *obj);
extern void func_800B9E9C(u8 *p, s32 a, s32 b, f32 c, s32 d);
extern void func_800B9FA4(u8 *p, s32 a, s32 b, f32 c, s32 d, s32 e);
extern s32 func_800B9BD4(u8 *p, s32 a, f32 *b, f32 *c, f32 *d, s32 e);
extern void func_800B9964(u8 *p, f32 *b, f32 *c, f32 *d);
extern void func_800BB9C0(u8 *p, s32 a, u8 *b);
extern void func_800BB8E0(u8 *p);
extern f32 func_800BB8C0(u8 *p);
extern s32 func_8001D4B8(u8 *p, s32 a, s32 b, s32 c);
extern void func_8001D640(u8 *p, s32 a, s32 b);
extern void func_800AB2A4(u8 *p, s32 a, s32 b, u8 *obj, s32 c, s32 d);

static __inline__ s32 scale15(s32 x, s32 k)
{
    return (x * k) >> 15;
}

static inline f32 integ(f32 *p, f32 d) { f32 v = *p + d; *p = v; return v; }
void func_800CF6A4(u8 *obj, s32 arg)
{
    s32 dt;
    s32 t;
    s32 v;
    f32 f;
    f32 g;
    f32 h;
    f32 a[4];
    f32 b[4];
    f32 c[2];

    if (arg == 0)
        return;
    dt = D_800F2744 - D_800F2778;
    func_80070CEC(obj);
    switch (S32(17124)) {
    case 0:
        S32(3852) -= 256;
        func_800B9E9C(obj + 4552, 3, -1, 1.0f, 0);
        t = S32(3860);
        if (t == 1 && S32(3852) <= 0) {
            func_80083AD8(obj);
            func_8008350C(obj);
            func_80082A84(obj, 18, 0, 0, 0, 0);
            func_80082A84(obj, 31, 0, 0, 0, 0);
            S32(4168) = 0;
            S32(17124) = t;
            S32(3852) = 23040;
        }
        func_80070CEC(obj);
        break;
    case 1:
        v = S32(3852) - 256;
        S32(3852) = v;
        if (v <= 0) {
            (*(u8 **)(obj + 3868))[3] = 0;
            (*(u8 **)(obj + 3868))[2] = 0;
            S32(10836) = 1;
            S32(17124) = 4;
            S32(17396) = 0;
            S32(3852) = S32(3856);
        } else if (v < 3841) {
            if (v < 3073)
                func_80082BEC(obj, 31, 32);
        }
        func_80070CEC(obj);
        break;
    case 4:
        S32(3852) -= 256;
        func_800BB9C0(obj + 4968, dt, *(u8 **)(obj + 3868));
        func_800BB8E0(obj + 4968);
        F32(17396) += func_800BB8C0(obj + 4968) * F32(17392) * 60.0f / 30.0f;
        if (3.0f < F32(17396))
            F32(17396) = 3.0f;
        F32(9588) = F32(17396);
        func_80070CEC(obj);
        if (S32(3852) > 0)
            break;
        S32(17124) = 5;
        S32(17872) = 0;
        break;
    case 5:
        F32(9588) = F32(17396);
        F32(17396) /= 1.4f;
        S32(17872) = 1;
        S32(17124) = 6;
        F32(17400) = 100.0f * (F32(17396) / 3.0f);
        if (F32(17356) <= F32(17400)) {
            func_800B9FA4(obj + 4552, 3, -1, 1.0f, 0, 1);
            func_800B9E9C(obj + 4552, 4, -1, 1.0f, 0);
        } else {
            func_800B9FA4(obj + 4552, 1, -1, 1.0f, 0, 1);
            func_800B9E9C(obj + 4552, 2, -1, 1.0f, 0);
        }
        F32(17376) = 0.0f;
        F32(17368) = F32(17396) * 135.0f / F32(17388) / 30.0f;
        func_80070CEC(obj);
        break;
    case 6:
        if (func_800B9BD4(obj + 4552, arg, a, c, b, 0) != 0) {
            v = func_8001D4B8(D_800F1AE0, 249, 0, 1);
            func_8001D640(D_800F1AE0, v, scale15(*(s32 *)(D_800F1AE0 + 104), 32767));
            S32(17124) = 7;
        }
        func_800B9964(obj + 4552, a, c, b);
        F32(4644) = 16.3835f;
        func_80070CEC(obj);
        break;
    case 7:
        g = F32(17376);
        h = F32(17368);
        g = integ((f32 *)(obj + 17376), h);
        h = integ((f32 *)(obj + 17368), -0.7143206f);
        if (g <= 0.0f) {
            f = 0.25f; F32(17368) = -(h * f);
            F32(17376) = 0.0f;
            if (obj[17862] == 3)
                S32(17124) = 2;
            obj[17862]++;
        }
        F32(17232) = F32(17376) + 6.5534f;
        if (F32(17408) < F32(17376))
            F32(17408) = F32(17376);
        if (S32(17864) == 1) {
            if (func_800B9BD4(obj + 4552, arg, a, c, b, 0) != 0)
                S32(17864) = 0;
            func_800B9964(obj + 4552, a, c, b);
            F32(4644) = 16.3835f;
            func_80070CEC(obj);
        }
        break;
    case 2:
        func_8008350C(obj);
        F32(17412) = F32(17408) / 750.0f * 100.0f;
        if (100.0f < F32(17412))
            F32(17412) = 100.0f;
        func_80082A84(obj, 20, 0, 0, 0, 0);
        func_80082A84(obj, 18, 0, 0, 0, 0);
        func_80082A84(obj, 34, (u32)F32(17356), 0, 0, 0);
        func_80082A84(obj, 33, (u32)F32(17412), 0, 0, 0);
        f = F32(17412);
        if (f >= F32(17364))
            *(s16 *)(obj + 4548) = 100;
        else if (f >= F32(17360))
            *(s16 *)(obj + 4548) = 90;
        else if (f >= F32(17356))
            *(s16 *)(obj + 4548) = 80;
        else
            *(s16 *)(obj + 4548) = 0;
        func_80082618(obj);
        S32(3852) = 30720;
        S32(17124) = 3;
        S32(3860) = 0;
        break;
    case 3:
        S32(3852) -= 256;
        if (S32(3860) != 0 && S32(3852) <= 0)
            func_800AB2A4(D_800F26E0, D_800F2744, 7, obj, 0, 7);
        break;
    }
}
