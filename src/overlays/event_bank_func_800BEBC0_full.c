typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define B(p, off) (*(u8 *)((u8 *)(p) + (off)))
#define F(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define P(p, off) (*(u8 **)((u8 *)(p) + (off)))

typedef struct VTable {
    char pad[0x8];
    s16 off2;
    void (*fn2)(void *, s32);
    s16 off;
    void (*fn)(void *, void *);
} VTable;

typedef struct Level {
    u8 count;
    s8 dist;
    s8 time;
    u8 shots;
    f32 speed;
    s32 seed;
} Level;

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Xform {
    f32 m[16];
    f32 t[3];
} Xform;

extern u8 *D_800FC270;
extern s32 D_800F2714;
extern u8 D_800F26E0[];
extern u8 D_800F2758[];
extern u8 D_800F2AD8[];
extern u8 D_80070A40[];
extern u8 D_80070A90[];
extern f32 D_80070B00[];

extern void func_80015EAC(s32 a);
extern void func_8008393C(void *obj, s32 a, void *b, s32 c);
extern void func_80017D84(const char *name, s32 a);
extern void func_80081F08(void *obj, Vec3 *pos, Vec3 *rot, s32 a, s32 b);
extern void func_800839DC(void *obj, s32 r, s32 g, s32 b);
extern void func_800BBD78(void *a, s32 b, s32 c, void *d, s32 e);
extern void func_800AA804(void *a, void *b, s32 size, const char *name);
extern void func_800AAA60(const char *file, s32 line, const char *msg);
extern void *func_800AAA58(s32 size, void *p);
extern void func_800ADED4(void *a);
extern void func_800AED80(void *a);
extern void func_800ADC54(void *a, s32 b);
extern void func_80071E58(void *a);
extern s32 func_8000EB20(const char *name);
extern void func_80013208(void *a, f32 b, f32 c, s32 d, s32 e);
extern void func_800ADC38(void *a);
extern void func_800AC37C(void *a, void *b);
extern void func_800AD890(void *a, s32 b);
extern s32 func_80013E7C(const char *name, void *b, s32 c);
extern void func_800AD4E0(void *a, f32 b, s32 c);
extern void func_800AD9E8(void *a);
extern float sqrtf(float);
extern void func_80082A84(void *obj, s32 a, u32 b, s32 c, s32 d, s32 e);
extern void func_80082764(void *obj, s32 a);
extern void func_800AB2A4(void *a, s32 b, s32 c, void *d, s32 e, s32 f);
extern void func_800177AC(void);
extern void func_800AA658(void *a, void *b);
extern void func_800E5E0C(void *a);
extern void func_800E5F58(void *a);
extern void func_800828B4(void *obj, s32 a);
extern void func_80083700(void *obj, s32 a);
extern void func_800BC07C(void *a, s32 b);
extern void func_80083A0C(void *obj);
extern void func_80071900(void *obj);
extern void func_80071460(void *obj);
extern void func_80083624(void *obj, s32 a, s32 b, s32 c, s32 d, s32 e);

static inline void vcall1(u8 *s, void *a)
{
    VTable *vt = *(VTable **)(s + 0xB4);
    vt->fn(s + vt->off, a);
}
static inline void vcall2(u8 *s, s32 a)
{
    VTable *vt = *(VTable **)(s + 0xB4);
    vt->fn2(s + vt->off2, a);
}
static inline void vset(Vec3 *v, f32 x, f32 y, f32 z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void xident(Xform *x, f32 one)
{
    x->m[9] = 0.0f;
    x->m[8] = 0.0f;
    x->m[6] = 0.0f;
    x->m[4] = 0.0f;
    x->m[2] = 0.0f;
    x->m[1] = 0.0f;
    x->t[2] = 0.0f;
    x->t[1] = 0.0f;
    x->t[0] = 0.0f;
    x->m[10] = one;
    x->m[5] = one;
    x->m[0] = one;
}

void func_800BEBC0(u8 *obj, s32 *msg)
{
    s32 dt = (msg[1] - W(obj, 0x10)) >> 8;
    u8 i;

    switch (msg[0]) {
    case 3: {
        Vec3 pos;
        Vec3 rot;
        s32 diff;
        s16 mode;
        Level *lv;
        u8 idx;
        s32 seed;
        u8 *p;
        Xform *x;
        f32 base;
        f32 k0;
        f32 k1;
        f32 k2;
        f32 one;
        f32 yoff;
        f32 f;

        func_80015EAC(12);
        mode = D_800FC270[0xD1B];
        diff = D_800FC270[0xD1F];
        {
            u8 order[4] = { 0, 1, 3, 6 };

            idx = order[mode] + diff;
        }
        W(obj, 0x42E8) = 0;
        func_8008393C(obj, 0, obj + 0x42E8, diff);
        lv = (Level *)P(obj, 0x42E8) + idx;
        *(Level **)(obj + 0x42E4) = lv;
        B(obj, 0x44F5) = B(obj, 0x44F4) = lv->count;
        B(obj, 0x44F7) = lv->shots;
        F(obj, 0x44D8) = lv->dist;
        W(obj, 0x44D4) = lv->time * 7680.0f;
        F(obj, 0x44F0) = (*(Level **)(obj + 0x42E4))->speed * 32.767f * 0.25f;
        seed = (*(Level **)(obj + 0x42E4))->seed;
        if (seed == 0) {
            seed = 1;
        }
        D_800F2714 = seed;
        func_80017D84("GRAPHICS__VIRTUALGYM__ARCINTERCEPT__INTERCEPT_BGP", -1);
        vset(&pos, 122.87624f, 81.917496f, -262.136f);
        vset(&rot, 0.0f, 0.0f, -147.45149f);
        func_80081F08(obj, &pos, &rot, 0, 0);
        F(obj, 0x1148) = 98.300995f;
        func_800839DC(obj, 160, 160, 160);
        func_800BBD78(D_800F2AD8, 0, 0, obj, 6);
        W(obj, 0x43D4) = 0;
        func_800AA804(D_800F2758, obj + 0x43D4, 2784, "ESKEETS");
        if (W(obj, 0x43D4) == 0) {
            func_800AAA60("c:/dev/olympics_2000/code/common/VG_Intercept.cpp", 469,
                          "Could not allocate Electro Skeets in VG_Intercept\n");
        }
        for (i = 0;; i++) {
            u8 *o;
            VTable *vt;
            u8 *s;

            if (i >= 8) {
                break;
            }
            o = func_800AAA58(348, P(obj, 0x43D4) + i * 348);
            func_800ADED4(o);
            *(u8 **)(o + 0xB4) = D_80070A90;
            W(o, 0) = 65;
            W(o, 0xD4) = 0;
            W(o, 0xDC) = 0;
            *(u8 **)(o + 0xB4) = D_80070A40;
            func_800AED80(o + 0x110);
            func_800ADC54(P(obj, 0x43D4) + i * 348, 1);
            func_80071E58(P(obj, 0x43D4) + i * 348);
            vcall1(i * 348 + P(obj, 0x43D4), obj);
        }
        base = F(P(P(P(obj, 0x43D4), 0xD0), 8), 0x28);
        {
            u8 *g = D_800FC270;

            F(obj, 0x44B4) = base;
            F(obj, 0x44B4) = base + base * F(g, 0x30);
        }
        W(obj, 0x42EC) = 0;
        func_80013208(obj + 0x42EC, 16.3835f, 16.3835f, func_8000EB20("GUNSIGHT") & 0xFFFF, 2);
        W(obj, 0x43C0) = W(obj, 0x42EC);
        p = obj + 0x42FC;
        func_800ADC54(p, 1);
        W(p, 0xC0) |= 0x10;
        func_800ADC38(p);
        func_800AC37C(p, obj);
        func_800AD890(p, 1);
        k0 = 139.25974f;
        W(p, 0xC0) |= 2;
        k1 = 0.5f;
        k2 = -0.089290075f;
        one = 1.0f;
        yoff = 81.917496f;
        F(obj, 0x44B0) = F(P(P(p, 0xD0), 8), 0x28) * 0.075f;
        x = (Xform *)(obj + 0x4310);
        xident(x, one);
        x->t[0] = F(obj, 0x44F0);
        x->t[1] = yoff;
        x->t[2] = 0.0f;
        W(obj, 0x42F4) = 0;
        W(obj, 0x42F4) = func_80013E7C("GRAPHICS__VIRTUALGYM__ARCINTERCEPT__ARCBOX_OBB", obj + 0x42F8, 0);
        W(obj, 0x449C) = W(obj, 0x42F4);
        p = obj + 0x43D8;
        func_800ADC54(p, 1);
        func_800ADC38(p);
        func_800AC37C(p, obj);
        func_800AD890(p, 1);
        W(p, 0xC0) |= 2;
        xident((Xform *)(obj + 0x43EC), one);
        x = (Xform *)(obj + 0x43EC);
        F(obj, 0x43EC) = 3.5f;
        F(obj, 0x4414) = 4.0f;
        x->t[0] = 0.0f;
        x->t[1] = yoff;
        x->t[2] = 4.9150496f;
        func_800AD4E0(x, -1.5707961f, 3);
        func_800AD9E8(p);
        W(obj, 0x44FC) = 0;
        W(obj, 0x44F8) = 0;
        vset((Vec3 *)(obj + 0x44BC), -122.87624f, yoff, 0.0f);
        B(obj, 0x44F6) = 0;
        i = 0;
        while (1) {
            if (i >= B(obj, 0x44F7)) {
                break;
            }
            {
                u8 *q = obj + i * 4;
                f32 v;

                v = -((k0 - D_80070B00[i]) * k1);
                v *= k2;
                F(q, 0x44DC) = sqrtf(v);
            }
            i++;
        }
        B(obj, 0x4500) = 0;
        W(obj, 0x4504) = 0;
        W(obj, 0x44B8) = 0;
        W(obj, 0x43D0) = 0;
        W(obj, 0xF0C) = 0x3C00;
        W(obj, 0xF14) = 0;
        func_80082A84(obj, 0, 0, 0, 0, 0);
        func_80082A84(obj, 34, F(obj, 0x44D8), 0, 0, 0);
        func_80082764(obj, 0);
        {
            u8 *g = D_800FC270;

            F(obj, 0x4510) = 0.01f;
            F(obj, 0x4510) = F(g, 0x2C) * F(obj, 0x4510) + F(obj, 0x4510);
        }
        f = 16.3835f;
        F(obj, 0x450C) = F(D_800FC270, 0x28) * f * 0.5f + f;
        func_800AB2A4(D_800F26E0, msg[1] + 0x100, 11, obj, 0, 0);
        func_800177AC();
        break;
    }
    case 7:
        switch ((u32)msg[4]) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, obj, 0);
            break;
        case 7:
        case 57:
            func_800AA658(D_800F2758, obj + 0x42E8);
            if (P(obj, 0x43D4) != 0) {
                for (i = 0;; i++) {
                    u8 *s;
                    VTable *vt;

                    if (i >= 8) {
                        break;
                    }
                    func_800E5E0C(P(obj, 0x43D4) + i * 348);
                    func_800E5F58((void *)(i * 348 + (u32)P(obj, 0x43D4)));
                    vcall2(i * 348 + P(obj, 0x43D4), 2);
                }
                func_800AA658(D_800F2758, obj + 0x43D4);
            }
            func_800828B4(obj, msg[4]);
            break;
        }
        break;
    case 1:
        func_80083700(obj, msg[4]);
        break;
    case 2: {
        u8 *m = (u8 *)(msg + 4);
        u8 b;

        if (W(obj, 0x44B8) == 1 || W(obj, 0x44B8) == 2) {
            func_800BC07C(P(obj, 0xF1C), m[1]);
            b = P(obj, 0xF1C)[3];
            if (b & 4) {
                W(obj, 0x44F8) = 1;
            }
            if (b & 8) {
                W(obj, 0x44FC) = 1;
            }
            b = P(obj, 0xF1C)[2];
            if (b & 4) {
                W(obj, 0x44F8) = 0;
            }
            if (b & 8) {
                W(obj, 0x44FC) = 0;
            }
            if (W(obj, 0x44F8) != 0) {
                if (W(obj, 0x44FC) != 0) {
                    B(obj, 0x4500) = 0;
                } else {
                    B(obj, 0x4500) = 1;
                }
            } else if (W(obj, 0x44FC) != 0) {
                B(obj, 0x4500) = 2;
            } else {
                B(obj, 0x4500) = 0;
            }
        } else {
            func_800BC07C(P(obj, 0xF1C), m[1]);
            if (P(obj, 0xF1C)[3] != 0) {
                W(obj, 0xF14) = 1;
            }
        }
    }
    case 5:
        if (dt == 0) {
            return;
        }
        func_80083A0C(obj);
        func_80071900(obj);
        break;
    case 12:
        if (B(obj, 0x44F5) != 0) {
            B(obj, 0x44F5)--;
            func_80071460(obj);
            func_80083624(obj, 36, B(obj, 0x44F5), 0, 0, 0);
            W(obj, 0xF0C) = W(obj, 0x44D4);
        }
        break;
    }
    W(obj, 0x10) = msg[1];
}
