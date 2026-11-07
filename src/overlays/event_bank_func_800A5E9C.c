typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Ent { u8 pad[4]; f32 v; u8 pad2[4]; } Ent;
typedef struct Tm { u8 pad[40]; s32 x; u8 pad2[16]; } Tm;
typedef struct H2 { u8 pad[32]; Tm tm[8]; } H2;
typedef struct G {
    u8 pad[1284];
    f32 h0;
    u8 pad1[1328 - 1288];
    f32 h1;
    u8 pad2[2560 - 1332];
    s32 mode;
    u8 pad3[2576 - 2564];
    Ent ents[1];
} G;
extern G *D_800FC270;

typedef struct VE { s16 off; s16 pad; void (*fn)(); } VE;
typedef struct VT { u8 pad[8]; VE b; u8 pad2[8]; VE a; } VT;

extern u8 D_800F2AD8[];
extern u8 D_800F26E0[];
extern u8 D_800F2758[];

extern void func_800CEE04(u8 *p);
extern void func_80097504(u8 *p);
extern void func_800AC334(u8 *p);
extern void func_800ADC1C(u8 *p);
extern void func_800BBD78(u8 *a, s32 b, s32 c, s32 d, s32 e);
extern void func_800AACB0(u8 *a, u8 *b, s32 c);
extern void func_800AA658(u8 *a, u8 *b);

#define W(o) (*(s32 *)(p + (o)))

void func_800A5E9C(u8 *p, u8 flag)
{
    u8 *q;
    f32 f;
    s32 m;

    W(31948) = 1;
    func_800CEE04(p + 29936);
    func_80097504(p + 13804);
    func_800AC334(p + 31248);
    func_800ADC1C(p + 31248);
    q = (u8 *)W(12212);
    if (W(31912) == 0) {
        f = D_800FC270->ents[(s8)p[31917]].v;
        m = D_800FC270->mode;
        if (m == 4 || m == 0 || m == 1 || m == 2) {
            if (p[31919] != 4 && D_800FC270->h0 < f) {
                D_800FC270->h0 = f;
            }
        }
        if (D_800FC270->mode == 4) {
            if (D_800FC270->h1 < f) {
                D_800FC270->h1 = f;
            }
        } else if (D_800FC270->mode == 5) {
            if (*(f32 *)((u8 *)D_800FC270 + 3564) < f) {
                *(f32 *)((u8 *)D_800FC270 + 3564) = f;
            }
        }
    }
    if (q != 0) {
        u8 k = ((u8 *)W(12212))[424];
        VT *vt;
        if (k != 8) {
            ((H2 *)D_800FC270)->tm[k].x = 0;
        }
        func_800BBD78(D_800F2AD8, (s8)q[427], 0, 0, 5);
        func_800BBD78(D_800F2AD8, (s8)q[427], 1, 0, 2);
        func_800AACB0(D_800F26E0, q, 0);
        vt = *(VT **)(q + 180);
        vt->a.fn(q + vt->a.off);
        vt = *(VT **)(q + 180);
        vt->b.fn(q + vt->b.off, 2);
        if (flag == 0) {
            func_800AA658(D_800F2758, p + 12212);
        }
    }
}
