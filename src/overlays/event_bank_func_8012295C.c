typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;

typedef struct Def {
    u16 a;
    u16 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
} Def;

typedef struct Spr {
    u16 a;
    u16 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    void *tex;
    s32 x;
    s32 y;
    s32 z;
    s16 h;
    s16 w;
} Spr;

typedef struct SO { u8 pad[3816]; u16 ids[10]; } SO;
typedef struct Q { s32 a, b, c, d; } Q;

extern u16 D_80083CD0[];
extern s32 D_800F4758;
typedef struct {
    u8 pad[0x68];
    s32 vol;
} Snd;
typedef struct G { u8 pad[3361]; u8 lv; } G;
extern Snd D_800F1AE0;
extern G *D_800FC270;
extern u8 D_800F2AD8[];
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F4D00[];
extern Q D_800F4760;
extern Def D_800F4178[];
extern u32 D_800F2714;

extern void func_800DB010(s32, char *, s32, s32, s32, s32);
extern u16 func_800B31F8(void);
extern void func_800B3208(u16);
extern void func_8001D550(Snd *, s32);
extern void func_800A3240(Snd *);
extern void func_800A32CC(Snd *);
extern void func_800CA634(u8 *);
extern void func_800C9B3C(u8 *);
extern void func_800CB6BC(u8 *);
extern void func_800BC274(u8 *);
extern void func_800AACB0(u8 *, u8 *, s32);
extern void func_800B35F0(u8 *);
extern void func_800D29E0(u8 *);
extern void func_800AC334(u8 *);
extern void func_800DB124(s32);
extern void func_800BAC24(void);
extern void func_80017B24(s32);
extern void func_80006A18(u8 *);
extern void func_800D52A8(u8 *);
extern void func_800ADC1C(u8 *);
extern void func_8000F420(void);
extern void func_800137FC(void);
extern void func_80014384(void);
extern void func_800AB2A4(u8 *, s32, s32, s32, u8 *, s32);
extern void func_800D33A0(u8 *p, Spr *s, s32 a, s32 b);
extern void func_800B2158(u8 *e, s32 a);
extern void func_800B31EC(s32 a);
extern void func_800B360C(u8 *p, Def *d);
extern s32 func_80017C4C(s32, s32, u8 **);
extern s32 func_80017C3C(s32);
extern void func_80083494(u8 *);

void func_80082A84(u8 *p, u16 b, s32 w, s32 x, s32 y, s32 z);

extern void func_8000673C(u8 *);
extern void func_800AD6D0(f32 *, f32 *);
extern u16 func_8000EB20(char *);
extern s32 func_80013208(s32 *, f32, f32, u16, s32);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800AD890(u8 *, s32);
extern void func_800ADC54(u8 *, s32);
extern void func_8000F42C(u8 *p);
extern void func_800CB1B0(u8 *p);
extern s32 func_8001D4B8(Snd *s, s32 a, s32 b, s32 c);
extern void func_8001D640(Snd *s, s32 h, s32 v);

void func_8008234C(u8 *o)
{
    f32 f;
    f = -32.767f;
    o[10880] = 0;
    *(s32 *)(o + 10884) = 4;
    o[10881] = 255;
    o[10882] = 255;
    o[10883] = 255;
    *(s32 *)(o + 10920) = 1;
    *(f32 *)(o + 10900) = f;
    *(f32 *)(o + 10904) = f;
    *(f32 *)(o + 10908) = 16.3835f;
    func_8000673C(o + 10880);
    *(s32 *)(o + 10972) = 2;
    o[10968] = 0;
    o[10969] = 50;
    o[10970] = 50;
    o[10971] = 50;
    *(s32 *)(o + 11008) = 1;
    *(s32 *)(o + 11012) = o[10883] | (o[10882] << 8) | (o[10881] << 16) | 0xFF000000;
    func_8000673C(o + 10968);
    o[10926] = 128;
    o[10924] = 0;
    *(s32 *)(o + 10928) = 4;
    o[10925] = 50;
    o[10927] = 255;
    *(f32 *)(o + 10952) = f;
    *(s32 *)(o + 11020) = o[10971] | (o[10970] << 8) | (o[10969] << 16) | 0xFF000000;
    *(f32 *)(o + 10944) = 32.767f;
    *(f32 *)(o + 10948) = 32.767f;
    func_800AD6D0((f32 *)(o + 10944), (f32 *)(o + 10944));
    *(s32 *)(o + 10964) = 1;
    func_8000673C(o + 10924);
    *(s32 *)(o + 11016) = o[10927] | (o[10926] << 8) | (o[10925] << 16) | 0xFF000000;
}

static inline void ident(u8 *q)
{
    *(s32 *)(q + 36) = 0;
    *(s32 *)(q + 32) = 0;
    *(s32 *)(q + 24) = 0;
    *(s32 *)(q + 16) = 0;
    *(s32 *)(q + 8) = 0;
    *(s32 *)(q + 4) = 0;
    *(s32 *)(q + 72) = 0;
    *(s32 *)(q + 68) = 0;
    *(s32 *)(q + 64) = 0;
    ((f32 *)q)[10] = 1.0f;
    ((f32 *)q)[5] = 1.0f;
}
void func_800824C0(u8 *o)
{
    s32 a;
    u8 *b;
    u8 *p;
    f32 f;
    a = 0;
    b = 0;
    f = 10.0f;
    if (func_80013208(&a, 49.1504974365234375f, 32.767f, func_8000EB20("FUZZ"), 2) != 0) return;
    p = o + 13300;
    func_800AC37C(p, o + 3872);
    *(u8 *)(o + 13476) = 1;
    ident(o + 13396);
    {
    f32 t = *(f32 *)(o + 13512);
    *(s32 *)(o + 13496) = a;
    *(f32 *)(o + 13396) = 1.0f;
    *(s32 *)(o + 13464) = 0;
    *(f32 *)(o + 13468) = 16.3835f;
    *(f32 *)(o + 13416) = t;
    }
    *(s32 *)(p + 192) |= 0x12;
    func_800AD890(p, 1);
    func_800ADC54(p, 1);
    func_800AC37C(p, o);
    if (func_80017C4C(*(s32 *)(o + 13496), 0, &b) < 0) return;
    *(f32 *)(b + 64) = f;
    *(f32 *)(b + 100) = f;
    *(f32 *)(b + 104) = f;
    *(f32 *)(b + 140) = f;
    {
        s32 h = *(s32 *)(o + 13496);
        u16 v = *(u16 *)(b + 24);
        *(s32 *)(o + 13520) = 0;
        *(u8 *)(o + 13516) = v;
        func_80017C3C(h);
    }
}

static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}

#define W(o) (*(s32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

void func_80082618(u8 *p)
{
    s32 h;
    s32 n;

    func_8000F42C(p);
    func_800CB1B0(p + 13956);
    if (H(4548) == 100) {
        func_80082A84(p, 30, 0, 0, 0, 0);
    } else if (H(4548) == 90) {
        func_80082A84(p, 29, 0, 0, 0, 0);
    } else if (H(4548) == 80) {
        func_80082A84(p, 28, 0, 0, 0, 0);
    } else if (H(4548) == 0) {
        func_80082A84(p, 27, 0, 0, 0, 0);
    }
    if (H(4548) >= 91) {
        h = func_8001D4B8(&D_800F1AE0, 189, 0, 1);
        func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
    } else if (H(4548) != 0) {
        h = func_8001D4B8(&D_800F1AE0, 196, 0, 1);
        func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
    } else {
        h = func_8001D4B8(&D_800F1AE0, 132, 0, 1);
        func_8001D640(&D_800F1AE0, h, scl(D_800F1AE0.vol, 32767));
    }
    D_800FC270->lv = B(4549);
    if (D_800FC270->lv > 100) {
        D_800FC270->lv = 100;
    }
    W(3852) = 30720;
    *(s16 *)(p + 3848) = 5;
    if (W(13524) & 4) {
        W(10836) = 0;
    }
}
#undef W
#undef H
#undef B

const char D_80081AE8[] = "GRAPHICS__VIRTUALGYM__COMMON__VGMALE_SKB";

void func_80082764(u8 *o, s32 i)
{
    u16 s;
    func_800DB010(0, "ICON_UP", 0, 0, 20, 20);
    func_800DB010(1, "ICON_DOWN", 0, 0, 20, 20);
    func_800DB010(2, "ICON_LEFT", 0, 0, 20, 20);
    func_800DB010(3, "ICON_RIGHT", 0, 0, 20, 20);
    func_800DB010(4, "ICON_SELECT", 0, 0, 20, 20);
    func_800DB010(5, "ICON_SELECT", 0, 0, 20, 20);
    D_800F4758 = D_80083CD0[i];
    s = func_800B31F8();
    func_800B3208(310);
    func_80082A84(o, 62, 0, 0, 0, 0);
    func_800B3208(s);
}

void func_800828B4(u8 *o, s32 b)
{
    u8 i;
    func_8001D550(&D_800F1AE0, 1);
    func_800A3240(&D_800F1AE0);
    func_800A32CC(&D_800F1AE0);
    *(s32 *)(o + 3864) = 0;
    if (*(s32 *)(o + 13524) & 2) func_800CA634(o + 4996);
    if (*(s32 *)(o + 13524) & 4) func_800C9B3C(o + 10248);
    if (*(s32 *)(o + 13524) & 8) func_800C9B3C(o + 9624);
    func_800CB6BC(o + 13956);
    *(s32 *)(o + 13524) = 1;
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    for (i = 0; i < 10; i++) {
        func_800B35F0(o + 1616 + i * 220);
    }
    func_800D29E0(o + 216);
    func_800AC334(o + 216);
    func_800DB124(1);
    func_800BAC24();
    func_800AC334(o + 3872);
    func_80017B24(0);
    func_80006A18(o + 10880);
    func_80006A18(o + 10924);
    func_800D52A8(D_800F4D00);
    func_800ADC1C(o + 4552);
    func_800AC334(o + 4552);
    func_800AACB0(D_800F26E0, o, 0);
    func_8000F420();
    func_800137FC();
    func_80014384();
    {
        s32 y = D_800F2744;
        s32 x = *(s32 *)(o + 4);
        func_800AB2A4(D_800F26E0, y, 20, x, o, b);
    }
}

void func_80082A84(u8 *p, u16 b, s32 w, s32 x, s32 y, s32 z)
{
    Spr s;
    Def *d;
    s32 k;

    D_800F4760.a = w;
    D_800F4760.b = x;
    D_800F4760.c = y;
    D_800F4760.d = z;
    if (b == 31) {
        s.tex = &D_800F4760;
        s.h = 3;
        s.w = 602;
        s.x = 0;
        s.z = 0;
        d = &D_800F4178[b];
        s.a = d->a;
        s.b = d->b;
        s.e = d->e;
        s.f = d->f;
        s.d = d->d;
        s.y = 15360;
        func_800D33A0(p + 216, &s, 1, -1);
        return;
    }
    if (b == 62) {
        func_800B31EC(3);
    } else {
        func_800B31EC(0);
    }
    func_800B360C(p + (p[3846] * 220 + 1616), &D_800F4178[b]);
    func_800B2158(p + (p[3846] * 220 + 1616), 1);
    ((SO *)p)->ids[p[3846]] = b;
    p[3846]++;
}

void func_80082BEC(u8 *p, u16 a, u16 b)
{
    Spr s;
    u8 i;
    u8 *e;
    Def *d;

    if (b == 32) {
        s.tex = &D_800F4760;
        s.h = 3;
        s.w = 602;
        s.x = 0;
        s.z = 0;
        d = &D_800F4178[b];
        s.a = d->a;
        s.b = d->b;
        s.e = d->e;
        s.f = d->f;
        s.d = d->d;
        s.y = 3840;
        func_800D33A0(p + 216, &s, 0, -1);
        func_8000F420();
        return;
    }
    for (i = 0; i < p[3846]; i++) {
        e = p + i * 2;
        if (*(u16 *)(e + 3816) == a) {
            func_800B31EC(0);
            func_800B360C(p + (i * 220 + 1616), &D_800F4178[b]);
            *(u16 *)(e + 3816) = b;
            return;
        }
    }
}

void func_80082D40(u8 *o)
{
    f32 d;
    u8 c;
    switch (*(u16 *)(o + 3848)) {
    case 2: {
        u8 *a;
        f32 f = *(f32 *)(o + 13512) + 0.04f;
        a = 0;
        *(f32 *)(o + 13512) = f;
        if (f >= 1.0f) {
            *(u16 *)(o + 3848) = 3;
            *(f32 *)(o + 13512) = 1.0f;
            func_80083494(o);
        }
        if (func_80017C4C(*(s32 *)(o + 13496), 0, &a) < 0) return;
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        d = ((f32)(D_800F2714 >> 19) * 0.000244140625f + 1.0f) * 0.2f;
        {u8 *q = a;
        {u8 i; for (i = 0; i < 4; i++) {
            *(f32 *)(q + i * 36 + 28) += d;
            *(f32 *)(q + i * 36 + 32) += d;
        }}}
        if (func_80017C3C(*(s32 *)(o + 13496)) < 0) return;
        *(f32 *)(o + 13416) = *(f32 *)(o + 13512);
        break;
    }
    case 3: {
        u8 *b;
        s32 h = *(s32 *)(o + 13496);
        b = 0;
        if (func_80017C4C(h, 0, &b) < 0) return;
        *(u8 *)(o + 13516) -= 2;
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        d = ((f32)(D_800F2714 >> 19) * 0.000244140625f + 1.0f) * 0.2f;
        {u8 *q = b;
        {u8 i; for (i = 0; i < 4; i++) {
            c = *(u8 *)(o + 13516);
            *(s32 *)(q + i * 36 + 24) = c | (c << 8) | (c << 16) | 0xFF000000;
            *(f32 *)(q + i * 36 + 28) += d;
            *(f32 *)(q + i * 36 + 32) += d;
        }}}
        if (func_80017C3C(*(s32 *)(o + 13496)) < 0) return;
        if (*(u8 *)(o + 13516) < 3) {
            func_800ADC1C(o + 13300);
            *(u16 *)(o + 3848) = 4;
        }
        break;
    }
    }
}
