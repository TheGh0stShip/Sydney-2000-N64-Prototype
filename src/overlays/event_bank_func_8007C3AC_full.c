typedef unsigned char u8;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define F(o) (*(f32 *)(p + (o)))

typedef struct { f32 f; u8 pad[2]; u8 flags; u8 pad2[5]; } Ent;
typedef struct { s16 d; s16 pad; void (*fn)(); } VEnt;
typedef struct { s32 a; s32 b; s32 c; } Tmr;

extern s32 D_800F2780;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F1AE0[];
extern u8 D_800F4D00[];
extern u8 *D_800FC270;
extern u8 D_800F2AD8[];
extern volatile s32 D_800F2728;
extern s32 D_800F13F0;
extern Tmr D_800445F0;

void func_800AB2A4(void *, s32, s32, void *, s32, s32);
void func_8001D5D8(void *, s32, s32, s32, s32, s32);
s32 func_8001D4B8(void *, s32, s32, s32);
void func_8001D640(void *, s32, s32);
void func_8001D680(void *, s32);
void func_800A9BE8(void *, s32);
void func_800D29E0(void *);
void func_8007DAA4(s32, s32, f32, s32, s32, void *);
void func_8009B9EC(s32, s32);
void func_8007295C(u8 *);
void func_80077FC4(u8 *);
void func_80077EEC(u8 *, s32, s32, s32);
void func_8007755C(u8 *);
void func_80072C6C(u8 *);
void func_80072E50(u8 *);
void func_800D6EA0(void *);
void func_80078140(u8 *);
void func_8007819C(u8 *);
void func_800BBD78(void *, s32, s32, void *, s32);
void func_8009BD48(s32);
void func_8009BD50(s32);
void func_8009C0D8(s32, s32);
void func_800D3B70(void *, f32, f32, s32);
void func_8009B0E4(s32, s32, void *, s32, s32, s32, s32);
void func_80076B14(u8 *);
void func_80076E24(u8 *);
void func_80076964(u8 *);
void func_800D771C(void *);
void func_800ADC54(void *, s32);
void func_800ADC38(void *);
void func_800ADC1C(void *);
void func_80076F3C(u8 *);
void func_800A3394(void *, s32, s32, s32);
void func_800A31BC(void *);
void func_80008540(void *);
void func_80008534(void *);
void func_800EBE58(void *);
void func_800A62EC(void *);
void func_8007D93C(s32);
void func_800B3870(void *, s32, s32);

typedef struct { u8 pad[0xA14]; Ent e[1]; } Big;
#define ENT(q, i) (((Big *)(q))->e[i])

void func_8007C3AC(u8 *p, s32 a1)
{
    u32 st;
    u8 *q;
    u8 *o;
    s16 s1;
    u8 v;
    u32 sub;
    u32 i;
    u32 n;
    u8 *e;
    s32 k;
    Tmr *tm;

    if (a1 == 0) {
        return;
    }
    if (W(0x8CB0) != 0) {
        D_800F2780 -= 0x100;
        if (D_800F2780 <= 0) {
            W(0x8CA4) = 15;
            func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 9);
        }
    }
    st = W(0x8C94);
    switch (st) {
    case 0: goto c0;
    case 1: goto c1;
    case 2: goto c0;
    case 3: goto c3;
    case 4: goto c4;
    case 5: goto c5;
    case 6: goto c6;
    case 7: goto c0;
    case 8: goto c8;
    case 9: goto c9;
    case 10: goto c0;
    case 11: goto c11;
    case 12: goto c12;
    case 13: goto c13;
    case 14: goto c14;
    case 15: goto c15;
    case 16: goto c16;
    case 17: goto c17;
    case 18: goto c18;
    default: return;
    }

c1:
    e = p + 0x8000;
    *(s32 *)(e + 0xCA0) -= 0x100;
    if (*(s32 *)(e + 0xCA0) > 0) {
        goto c1_tail;
    }
    *(s32 *)(e + 0xC94) = 2;
    if (e[0xC9D] != 4) {
        s32 h;
        { s32 x = *(s32 *)(e + 0x4638); func_8001D5D8(D_800F1AE0, x, 0, 120, 1, 0); }
        h = func_8001D4B8(D_800F1AE0, 269, 0, -1);
        func_8001D640(D_800F1AE0, h, 0);
        func_8001D5D8(D_800F1AE0, h, (s32)(((long long)*(s32 *)(D_800F1AE0 + 0x68) * 8191)) >> 15, 195, 0, 0);
        *(s32 *)(e + 0x463C) = h;
    }
    func_800A9BE8(p + 0x86F8, 3);
    func_800D29E0(p + 11800);
    func_800D29E0(p + 14600);
    func_800D29E0(p + 16000);
    func_800D29E0(p + 17400);
    if (*(s32 *)(D_800FC270 + 0xA04) == 4) {
        u8 *g = D_800F4D00;
        func_8007DAA4(W(0x536C), 4, 7.65f, *(u8 *)(*(s32 *)(e + 0xCBC) + e[0xC98]),
                      *(s32 *)(e + 0xCB8) + e[0xC98] * 80, g + 220);
    } else {
        u8 *g = D_800F4D00;
        func_8007DAA4(W(0x536C), 5, 0.0f, *(u8 *)(*(s32 *)(e + 0xCBC) + e[0xC98]),
                      *(s32 *)(e + 0xCB8) + e[0xC98] * 80, g + 220);
    }
c1_tail:
    if (B(0x8C9D) != 4) {
        func_8009B9EC(19200, 24575);
    }
    goto done;

c3:
    func_8007295C(p);
    goto done;

c4:
    if (F(0x8844) < 344.053466796875f) {
        F(0x8844) = 360.4369812011719f;
    }
    goto done;

c5:
    if (F(0x8844) < 344.053466796875f) {
        F(0x8844) = 360.4369812011719f;
    }
c6:
    if (B(0x8C9F) != 0) {
        W(0x8CA0) -= 0x100;
        if (W(0x8CA0) < 0) {
            B(0x8C9F) = 0;
            func_800D29E0(p + 11800);
        }
    }
    goto done;

c8:
    switch (B(0x8C9D)) {
    case 0: case 1: case 2: case 3: case 4:
        {
            u8 *r = p + 0x87EC;
            r[185] = 0;
            r[184] = 1;
            r[186] = 1;
            r[187] = 0;
        }
    case 5:
        func_80077FC4(p);
        W(0x8C94) = 9;
        if (B(0x8C9D) == 5 && B(0x8CD8) == 0) {
            B(0x8CD8) = 1;
            func_80077EEC(p, W(0x8CD4), 15360, 0x16800);
            func_8007755C(p);
        }
        break;
    }
    goto done;

c9:
    func_80072C6C(p);
    goto done;

c11:
    func_80072E50(p);
    goto done;

c12:
    W(0x8CA0) -= 0x100;
    if (W(0x8CA0) > 0) {
        goto done;
    }
    func_800D6EA0(p + 11564);
    sub = B(0x8C9D);
    switch (sub) {
    case 0: case 1: goto i01;
    case 2: case 3: case 4: goto i234;
    case 5: goto i5;
    default: goto i_end;
    }
i01:
    func_800D29E0(p + 11800);
    func_80078140(p);
    if (B(0x8CB4) != 0) {
        W(0x8C94) = 13;
    } else {
        func_80077EEC(p, 291, 0, 0);
        W(0x8C94) = 16;
    }
    goto i_end;
i5:
    W(0x8C94) = 17;
    goto i_end;
i234:
    W(0x8C94) = 13;
    goto i_end;
i_end:
    D_800F2728 = 0;
    goto done;

c13:
    if (B(0x8C99) + 1 == B(0x8C9A)) {
        q = D_800FC270;
        if (*(s32 *)(q + 0xA00) == 5) {
            if (*(f32 *)(q + 0xDFC) < ENT(q, B(0x8C98)).f) {
                *(f32 *)(q + 0xDFC) = ENT(q, B(0x8C98)).f;
                ENT(q, B(0x8C98)).flags |= 2;
            }
        }
    }
    func_800D6EA0(p + 11564);
    v = B(0x8C9D);
    if (v >= 2 && v <= 4) {
        func_800BBD78(D_800F2AD8, 13, 0, p, 3);
        B(0x8C98) = 0;
        B(0x8C99) = 0;
        if (B(0x8C9D) == 2) {
            ENT(D_800FC270, B(0x8C98)).f = -1.0f;
            F(0x8CAC) = -1.0f;
            B(0xC69E) = 0;
            W(0x8C94) = 0;
            func_800AB2A4(D_800F26E0, D_800F2744, 24, p, 0, 0);
            B(0x8C9D) = 3;
            func_8009BD48(3);
        } else {
            if (B(0x8C9D) == 3) {
                func_800D3B70(p + 32292, ENT(D_800FC270, B(0x8C98)).f, F(0x8CAC), 0);
            } else {
                f32 f0 = ENT(D_800FC270, B(0x8C98)).f;
                f32 f2 = *(f32 *)(D_800FC270 + 0xD10);
                if (f2 <= f0) {
                    func_800D3B70(p + 32292, f0, f2, 2);
                } else {
                    func_800D3B70(p + 32292, f0, f2, 1);
                }
            }
            if (F(0x8CAC) < ENT(D_800FC270, B(0x8C98)).f) {
                F(0x8CAC) = ENT(D_800FC270, B(0x8C98)).f;
            }
            func_800A9BE8(p + 0x86F8, 10);
            func_80078140(p);
            W(0x8C94) = 0;
            *(s32 *)(*(u8 **)(p + 0x536C) + 0xAC) = 0;
            D_800F2728 = 0;
            goto done;
        }
        goto i_end;
    }
    if (B(0x8C98) + 1 < *(u8 *)(D_800FC270 + 0xA0C)) {
        if ((u8)v != 4) {
            func_8001D680(D_800F1AE0, W(0xC63C));
        }
        W(0x8C94) = 0;
        B(0x8C98)++;
        func_800AB2A4(D_800F26E0, D_800F2744, 24, p, 0, 0);
        goto done;
    }
    if (B(0x8C99) + 1 != B(0x8C9A)) {
        func_800D29E0(p + 11800);
        func_800D29E0(p + 14600);
        func_800D29E0(p + 16000);
        func_800D29E0(p + 17400);
        func_8009B0E4(233, B(0x8C99), p + 696, 2, 0, 0, 0);
        func_800A9BE8(p + 0x86F8, 10);
        W(0x8CA0) = 0x12C00;
        W(0x8C94) = 14;
        func_80077EEC(p, 292, 0, 0);
        goto done;
    }
    q = D_800FC270;
    s1 = 1;
    if (*(s32 *)(q + 0xA00) == 4) {
        s1 = (*(s32 *)(q + 0xA04) == 5) ? 1 : 0;
    }
    func_800D29E0(p + 11800);
    func_800D29E0(p + 14600);
    func_800D29E0(p + 16000);
    func_800D29E0(p + 17400);
    func_8009B0E4(233, B(0x8C99), p + 696, 2, s1, 0, 0);
    B(0x8C9D) = B(0x8C9E);
    func_800A9BE8(p + 0x86F8, 10);
    o = D_800FC270;
    W(0x8CA0) = 0x70800;
    W(0x8C94) = 15;
    switch (*(s32 *)(o + 0xA00)) {
    case 5:
        func_80076E24(p);
        break;
    case 0: case 1: case 2: case 3:
        func_80076964(p);
        break;
    case 4:
        func_80076B14(p);
        for (i = 0; (u8)i < *(u8 *)(D_800FC270 + 0xA0C); i++) {
        }
        break;
    }
    goto done;

c14:
    if (W(0x8CA0) > 0) {
        W(0x8CA0) -= 0x100;
        goto done;
    }
    func_800D771C(p + 696);
    func_8007819C(p);
    W(0x8C94) = 0;
    goto done;

c15:
    if (W(0x8CA0) > 0) {
        W(0x8CA0) -= 0x100;
        goto done;
    }
    q = D_800FC270;
    if (*(s32 *)(q + 0xA00) != 5 || (*(u8 *)(q + 0xD52) & 4)) {
        W(0x8C94) = 0;
        func_800D771C(p + 696);
        func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 9);
        W(0x8CA4) = 15;
    } else {
        W(0x8CA4) = 15;
        func_8009BD50(B(0x8C9D));
        func_8009C0D8(1, -1);
        W(0x8C94) = 0;
    }
    goto done;

c16:
    {
        u8 *g = D_800F4D00;
        u8 *o2;
        VEnt *t;
        s32 v2 = B(0x8C9D);
        B(0x8C9D) = 5;
        B(0x8C9E) = v2;
        o2 = p + 30728;
        t = *(VEnt **)(o2 + 180);
        t[2].fn(o2 + t[2].d, g);
        func_800ADC54(o2, 1 << *(s32 *)(g + 216));
        o2[176] = 1;
        func_800ADC38(o2);
    }
    B(0x8CD8) = 0;
    if (B(0x8C9D) != 2) {
        func_80076F3C(p);
    } else {
        B(0x8CD8) = 1;
    }
    if (B(0x8C9D) != 4) {
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
    }
    if (D_800445F0.c == 0) {
        D_800445F0.b = D_800445F0.a;
        func_80008540(&D_800445F0);
        D_800445F0.c = 1;
    }
c17:
    func_800EBE58(p + 0xC6A4);
    func_800A62EC(p + 18800);
    func_8007D93C(W(0x536C));
    func_800B3870(p + 0x8800, W(0x536C) + 20, 76);
    func_800A9BE8(p + 0x86F8, 11);
    {
        s32 t2 = W(0x8CA8);
        if (t2 == 0) {
            t2 = 1;
        }
        D_800F13F0 = t2;
    }
    W(0x8CA0) = 0;
    W(0x8C94) = 4;
    goto done;

c18:
    tm = &D_800445F0;
    if (tm->c == 1) {
        D_800445F0.a = tm->b;
        if (tm->b != 0) {
            func_80008534(tm);
            tm->c = 0;
        } else {
            func_80008540(tm);
            tm->c = 0;
        }
    }
    {
        u8 *e = p + 0x8000;
        u8 *o3;
        VEnt *t;
        *(s32 *)(e + 0xC94) = 13;
        o3 = p + 30728;
        t = *(VEnt **)(o3 + 180);
        t[3].fn(o3 + t[3].d);
        o3[176] = 0;
        func_800ADC1C(o3);
        func_800AB2A4(D_800F26E0, D_800F2744, 18, (void *)W(0x536C), 0, 0);
        if (e[0xC9B] == 0) {
            func_8009BD50(e[0xC9D]);
        }
    }
    goto done;
c0:
done:
    ;
}
