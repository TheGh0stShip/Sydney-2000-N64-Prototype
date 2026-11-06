typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct VEntry { s16 pad0[8]; s16 off; s16 pad12; void (*fn)(void *, void *); } VEntry;
typedef struct VTab { s16 pad0[8]; s16 off0; s16 p0; void (*fn0)(void *, void *);
    s16 pad1[20]; s16 off1; s16 p1; void (*fn1)(void *); } VTab;

extern u8 *D_800FC270;
extern char D_80071308[];
extern u8 D_800F2758[];
extern u8 D_800F2A70[];
extern void *D_800F1A44;
extern s32 D_800785A0[];
extern u8 D_80071518[];
extern u8 D_80078C40[];
extern void func_800AA804(void *, void *, s32, void *);
extern void func_80017A90(s32);
extern void func_8001786C(s32);
extern s32 func_800DAC28(s32);
extern s32 func_800140A0(s32, s32, s32);
extern void func_800BA0EC(void);
extern void func_800ADB70(void *);
extern u8 *func_800AAA58(s32, void *);
extern void func_800BA1FC(void *);
extern void func_800AED80(void *);
extern void func_800AC37C(void *, void *);
extern void func_80075100(s32);
extern void func_8009A828(void *, s32, s32);
extern void func_80078D20(void *, void *, void *, void *);
extern void func_80075374(void *);

#define PL (*(u8 **)(ctx + 0x536C))

void func_8007ACE0(u8 *ctx, s32 arg1)
{
    u8 *hi = ctx + 0x8000;
    u8 *e;
    u8 a, b;
    u8 *o; u8 *o2;
    u8 *h2;
    u8 *v; u8 *w;
    s8 sa;
    s32 c;
    VTab *vt;
    short bb;
    u8 *q; u8 *p0;
    s32 m;
    u8 *h1;
    f32 f0, f2, f4, f6;

    e = (hi[0xC98] * 12 + 0xA10) + D_800FC270;
    if (*(f32 *)(e + 4) == *(f32 *)0x80071310) {
        *(s32 *)(e + 4) = 0;
    }
    a = e[0];
    b = e[1];
    if ((p0 = PL) == 0) {
        func_800AA804(D_800F2758, ctx + 0x536C, 1216, D_80071308);
        if (arg1 != 0) goto L1;
        func_80017A90(0x40000000);
        if (b != (s8)hi[0x6F4]) {
            bb = b;
        if ((s8)hi[0x6F4] != -1 && *(s32 *)(hi + 0x6F0) != 0) {
                func_8001786C(*(s32 *)(hi + 0x6F0));
            }
            h1 = ctx + 0x8000;
            h1[0x6F4] = b;
            *(s32 *)(h1 + 0x6F0) = func_800140A0(D_800785A0[func_800DAC28(bb)], bb, 1);
        }
        func_80017A90(0x20000000);
        goto L1;
    }
    func_800BA0EC();
    func_800ADB70(p0 = PL);
    *(s32 *)(hi + 0x6F0) = *(s32 *)(PL + 728);
L1:
    o = func_800AAA58(1216, PL);
    func_800BA1FC(o);
    *(void **)(o + 180) = D_80071518;
    func_800AED80(o + 652);
    *(void **)(o + 180) = D_80078C40;
    *(s32 *)o = 99;
    o[428] = 0;
    *(s16 *)(o + 638) = 0;
    o[202] = 0;
    *(s32 *)(o + 644) = 0;
    *(s32 *)(o + 648) = 0;
    *(s32 *)(o + 728) = 0;
    o2 = ctx + 0x87EC;
    *(s32 *)(PL + 728) = *(s32 *)(ctx + 0x8000 + 0x6F0);
    func_800AC37C(o2, PL);
    o2[186] = 1;
    v = ctx + 0x88BC;
    f0 = *(f32 *)0x80071314; f2 = *(f32 *)0x80071318; f4 = *(f32 *)0x8007131C; f6 = *(f32 *)0x80071320;
    o2[185] = 0;
    o2[184] = 0;
    o2[187] = 0;
    *(s32 *)(v + 36) = 0; *(s32 *)(v + 32) = 0; *(s32 *)(v + 24) = 0;
    *(s32 *)(v + 16) = 0; *(s32 *)(v + 8) = 0; *(s32 *)(v + 4) = 0;
    *(s32 *)(v + 72) = 0; *(s32 *)(v + 68) = 0; *(s32 *)(v + 64) = 0;
    *(f32 *)(v + 40) = f0; *(f32 *)(v + 20) = f0; *(f32 *)(v + 0) = f0;
    w = ctx + 0x8978;
    *(s32 *)(w + 36) = 0; *(s32 *)(w + 32) = 0; *(s32 *)(w + 24) = 0;
    *(s32 *)(w + 16) = 0; *(s32 *)(w + 8) = 0; *(s32 *)(w + 4) = 0;
    *(s32 *)(w + 72) = 0; *(s32 *)(w + 68) = 0; *(s32 *)(w + 64) = 0;
    *(f32 *)(w + 40) = f0; *(f32 *)(w + 20) = f0; *(f32 *)(w + 0) = f0;
    *(f32 *)(w + 64) = f2; *(f32 *)(w + 68) = f4; *(f32 *)(w + 72) = f6;
    q = PL;
    D_800F1A44 = q;
    if (arg1 == 0) {
        vt = *(VTab **)(q + 180);
        vt->fn0(q + vt->off0, ctx);
        *(s32 *)(PL + 192) = (*(s32 *)(PL + 192) | 0x600) & ~1;
        *(s32 *)(PL + 192) |= 1;
        vt = *(VTab **)(PL + 180);
        vt->fn1(PL + vt->off1);
    }
    *(void **)(PL + 644) = ctx + 0x8CC4;
    *(void **)(PL + 648) = D_800F2A70;
    PL[424] = a;
    PL[425] = b;
    PL[636] = b & 7;
    sa = a;
    if (sa != 8) {
        u8 *bp = D_800FC270 + sa * 60;
        c = bp[32];
    } else {
        c = 3;
    }
    h2 = ctx + 0x8000;
    if (h2[0xC9D] == 2) c = 3;
    PL[426] = c;
    PL[427] = 0;
    func_8009A828(PL + 404, b, (s8)a);
    if (*(s32 *)(D_800FC270 + 2564) == 0) {
        *(s32 *)(PL + 416) = 0;
    }
    if (arg1 == 0) {
        func_80078D20(PL, ctx + 0xA22C, ctx + 0x8BC0, ctx + 0xA3B8);
        m = h2[0xC9D];
        if (m < 5 && (m >= 2 || m == 0)) {
            func_80075374(ctx);
        }
    }
}
