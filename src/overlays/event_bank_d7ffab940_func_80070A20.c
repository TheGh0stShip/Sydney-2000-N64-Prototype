typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Msg {
    s32 type;
    s32 time;
    s32 pad8;
    s32 padC;
    u32 val;
} Msg;

typedef struct Ent {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0C;
    u8 kind;
    u16 h;
    f32 w;
} Ent;

extern u8 *D_800FC270;
extern u8 D_800F2AD8[];
extern u8 D_800F26E0[];
extern u8 D_800F2758[];
extern u8 D_800723E0[];
extern u8 D_800723EC[];

extern void func_80015EAC(s32);
extern void func_80017D84(const char *, s32);
extern void func_80081F08(void *, void *, void *, s32, s32);
extern void func_80037F30(void *, s32, s32);
extern void func_8008393C(void *, s32, void *);
extern void func_800839DC(void *, s32, s32, s32);
extern void func_800BBD78(void *, s32, s32, void *, s32);
extern void func_80082A84(void *, s32, s32, s32, s32, s32);
extern void func_80082764(void *, s32);
extern void func_800AB2A4(void *, s32, s32, void *, s32, s32);
extern void func_800177AC(void);
extern void func_80072208(void *);
extern void func_800AA658(void *, void *);
extern void func_800828B4(void *, s32);
extern void func_80083700(void *, s32);
extern void func_800BC07C(void *, u8);
extern void func_80071544(void *);
extern void func_80083A0C(void *);
extern void func_800717FC(void *);
extern s32 func_80013E7C(const char *, void *, s32);
extern s32 func_8000EB20(const char *);
extern void func_80013208(void *, f32, f32, u16, s32);
extern void func_800ADC54(void *, s32);
extern void func_800AD890(void *, s32);
extern void func_800ADC38(void *);
extern void func_800AD4E0(f32 *, f32, s32);
extern void func_800AD434(f32 *, f32, s32);
extern void func_800AD9E8(void *);
extern void func_80071F90(void *);
extern void func_80083004(void *, f32 *, u8);
extern void func_80083064(void *, f32 *, u8, s32);

#define B(o) (*(u8 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define W(o) (*(s32 *)(p + (o)))
#define F(o) (*(f32 *)(p + (o)))
#define E(o) (*(Ent **)(p + (o)))
static inline void setf(f32 *d, f32 v)
{
    *d = v;
}

#define SF(o, v) setf((f32 *)(p + (o)), v)
#define G_F(o) (*(f32 *)(D_800FC270 + (o)))

static inline void vset(f32 *v, f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

static inline void ident(f32 *m)
{
    m[9] = 0.0f;
    m[8] = 0.0f;
    m[6] = 0.0f;
    m[4] = 0.0f;
    m[2] = 0.0f;
    m[1] = 0.0f;
    m[18] = 0.0f;
    m[17] = 0.0f;
    m[16] = 0.0f;
    m[10] = 1.0f;
    m[5] = 1.0f;
    m[0] = 1.0f;
}

void func_80070A20(u8 *p)
{
    f32 mt[19];
    u8 *o;
    f32 *m;
    u8 v;
    u32 t;

    W(0x42FC) = 0;
    W(0x42F4) = func_80013E7C("GRAPHICS__VIRTUALGYM__DUCKSHOOT__SHOTGUN_OBB", p + 0x42FC, 0);
    W(0x42EC) = func_80013E7C("GRAPHICS__VIRTUALGYM__RECOIL__TARGET_OBB", p + 0x42FC, 0);
    W(0x42F8) = 0;
    W(0x42F0) = 0;
    func_80013208(p + 0x42F8, 6.5533996f, 6.5533996f, func_8000EB20("MUZZLE_FLASH"), 2);
    func_80013208(p + 0x42F0, 6.5533996f, 6.5533996f, func_8000EB20("GUNSIGHT2"), 2);
    {
        u8 *o1 = p + 0x4300;
        W(0x43C4) = W(0x42F0);
        func_800ADC54(o1, 1);
        func_800AD890(o1, 1);
        *(s32 *)(o1 + 0xC0) |= 0xA;
        func_800ADC38(o1);
    }
    {
        u8 *o2 = p + 0x4578;
        *(s32 *)(o2 + 0xC0) |= 0x400002;
        W(0x463C) = W(0x42F8);
        func_800ADC54(o2, 1);
        func_800AD890(o2, 1);
    }
    o = p + 0x43D4;
    W(0x4660) = 0;
    W(0x4498) = W(0x42EC);
    func_800ADC54(o, 1);
    *(s32 *)(o + 0xC0) |= 8;
    func_800AD890(o, 1);
    m = (f32 *)(p + 0x43E8);
    F(0x43E8) = 0.375f;
    F(0x4410) = 0.375f;
    func_800AD4E0(m, -1.5707961f, 3);
    func_800AD434(m, -3.1415923f, 3);
    m[16] = 0.0f;
    m[17] = 39.3204f;
    m[18] = -9.8301f;
    func_800AD9E8(o);
    ((f32 *)*(u8 **)(*(u8 **)(o + 0xD0) + 8))[10] = 21.298548f;
    func_80071F90(o);
    func_800ADC38(o);
    ident(mt);
    mt[16] = 58.980595f;
    mt[18] = 32.767f;
    func_800AD434(mt, 0.3839724f, 3);
    *(u32 *)(p + 0x46C0) = B(0x46B9) * 4;
    func_80083004(p, mt, (B(0x46B9) * 100) / *(u32 *)(p + 0x46C0));
    ident(mt);
    mt[16] = -58.980595f;
    mt[18] = 32.767f;
    func_800AD434(mt, -0.3839724f, 3);
    func_80083064(p, mt, H(0x46BC) / *(u32 *)(p + 0x46C0), W(0x4654));
}

void func_80070D50(u8 *p, Msg *m)
{
    s32 n;
    u8 sp18[4];
    u8 a;
    u8 b;
    u8 c;
    Ent *e;
    Ent *e2;
    u8 *q;
    u8 v;
    f32 f;
    f32 z;
    f32 k;
    f32 y;
    u8 *g;
    f32 x;

    n = (m->time - W(0x10)) >> 8;
    switch (m->type) {
    case 3:
        func_80015EAC(12);
        func_80017D84("GRAPHICS__VIRTUALGYM__RECOIL__RECOIL_BGP", -1);
        func_80081F08(p, D_800723E0, D_800723EC, 0, 0);
        a = D_800FC270[0xD1B];
        b = D_800FC270[0xD1F];
        func_80037F30(sp18, 0, 4);
        sp18[3] = 3;
        c = sp18[a] + b;
        W(0x42E8) = 0;
        func_8008393C(p, 11, p + 0x42E8);
        e = (Ent *)(W(0x42E8) + c * 20);
        E(0x42E4) = e;
        B(0x46B9) = e->kind;
        W(0x465C) = e->x * 7680.0f;
        e2 = E(0x42E4);
        W(0x4654) = e2->y * 7680.0f;
        e2->z += e2->z;
        F(0x4664) = e2->z * 32.767f / 30.0f;
        H(0x46BC) = E(0x42E4)->h;
        F(0x4668) = E(0x42E4)->w * 32.767f;
        W(0x4658) = 0;
        z = 0.0f;
        F(0x46EC) = z;
        F(0x46F0) = z;
        B(0x46BA) = B(0x46B9);
        func_80070A20(p);
        F(0x1148) = 39.3204f;
        func_800839DC(p, 125, 125, 125);
        func_800BBD78(D_800F2AD8, 0, 0, p, 6);
        B(0x46D8) = 0;
        ident((f32 *)(p + 0x4314));
        vset((f32 *)(p + 0x4354), z, -6.5533996f, 6.5533996f);
        F(0x46E0) = z;
        F(0x46DC) = z;
        F(0x46E8) = z;
        F(0x46E4) = z;
        W(0x46D0) = 0;
        W(0x46CC) = 0;
        W(0x46C8) = 0;
        W(0x46C4) = 0;
        W(0x4650) = 0;
        W(0xF14) = 0;
        W(0xF0C) = 0x3C00;
        func_80082A84(p, 11, 0, 0, 0, 0);
        f = (f32)W(0x4654) / 30.0f * 0.00390625f;
        func_80082A84(p, 26, (u32)f, 0, 0, 0);
        func_80082A84(p, 38, H(0x46BC), 0, 0, 0);
        func_80082764(p, 11);
        g = D_800FC270;
        k = 0.013333334f;
        F(0x46F8) = k;
        y = *(f32 *)(g + 0x2C) * k;
        x = F(0x4664) * 0.5f;
        F(0x46F4) = 4.91505f;
        F(0x4664) = x;
        F(0x46F8) = y + k;
        F(0x4664) = x + (1.0f - *(f32 *)(g + 0x28)) * x;
        func_800AB2A4(D_800F26E0, m->time + 256, 11, p, 0, 0);
        func_800177AC();
        break;
    case 7:
        switch (m->val) {
        case 8:
        case 15:
            func_800BBD78(D_800F2AD8, 12, 1, p, 0);
            break;
        case 7:
        case 57:
            func_80072208(p + 0x43D4);
            func_800AA658(D_800F2758, p + 0x42E8);
            func_800828B4(p, m->val);
            break;
        }
        break;
    case 12:
        break;
    case 1:
        func_80083700(p, m->val);
        break;
    case 2:
        q = (u8 *)&m->val;
        if ((u32)(W(0x4650) - 1) < 2) {
            func_800BC07C(*(void **)(p + 0xF1C), q[1]);
            v = (*(u8 **)(p + 0xF1C))[3];
            if (v & 4) W(0x46C4) = 1;
            if (v & 8) W(0x46C8) = 1;
            if (v & 1) W(0x46CC) = 1;
            if (v & 2) W(0x46D0) = 1;
            if ((v & 0x10) && W(0x4650) == 2) {
                func_80071544(p);
            }
            v = (*(u8 **)(p + 0xF1C))[2];
            if (v & 4) W(0x46C4) = 0;
            if (v & 8) W(0x46C8) = 0;
            if (v & 1) W(0x46CC) = 0;
            if (v & 2) W(0x46D0) = 0;
            if (W(0x46C4) != 0 && W(0x46C8) == 0) {
                B(0x46D8) |= 1;
            } else if (W(0x46C4) == 0 && W(0x46C8) != 0) {
                B(0x46D8) |= 2;
            } else {
                B(0x46D8) &= 0xFC;
            }
            if (W(0x46CC) != 0 && W(0x46D0) == 0) {
                B(0x46D8) |= 4;
            } else if (W(0x46CC) == 0 && W(0x46D0) != 0) {
                B(0x46D8) |= 8;
            } else {
                B(0x46D8) &= 0xF3;
            }
        } else {
            func_800BC07C(*(void **)(p + 0xF1C), q[1]);
            if ((*(u8 **)(p + 0xF1C))[3] != 0) {
                W(0xF14) = 1;
            }
        }
    case 5:
        if (n == 0) {
            return;
        }
        func_80083A0C(p);
        func_800717FC(p);
        break;
    }
    W(0x10) = m->time;
}
