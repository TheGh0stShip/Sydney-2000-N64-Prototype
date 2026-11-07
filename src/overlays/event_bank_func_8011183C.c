typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;
extern u8 D_8007DEAC[];
extern u8 D_8007DEA0[];
extern s32 func_800125DC(s32, u16 *, u8 *, s32);
extern s32 func_80017C4C(s32, s32, u8 **);
extern s32 func_80017C3C(s32);
extern s32 func_80017C20(s32, s32, s32, u8 *);
extern u16 func_8000EB20(char *);
extern void func_80017CF4(s32, s32, u16);
extern void func_800B3870(u8 *, u8 *, s32);
extern void func_800ADC54(u8 *, s32);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800ADC38(u8 *);
extern void func_8007CA64(u8 *, s32);
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
    *(f32 *)(q + 40) = 1.0f;
    *(f32 *)(q + 20) = 1.0f;
    *(f32 *)(q + 0) = 1.0f;
}
static inline void zt(u8 *q)
{
    *(s32 *)(q + 64) = 0;
    *(s32 *)(q + 68) = 0;
    *(s32 *)(q + 72) = 0;
}
void func_8007CB4C(u8 *o)
{
    u16 n;
    u8 *p;
    u8 *q;
    n = 4;
    p = 0;
    if (func_800125DC(1, &n, o + 1272, -1) < 0) return;
    if (func_80017C4C(*(s32 *)(o + 1272), 0, &p) < 0) return;
    func_800B3870(p, D_8007DEAC, n * 36);
    if (func_80017C3C(*(s32 *)(o + 1272)) < 0) return;
    if (func_80017C20(*(s32 *)(o + 1272), 0, 2, D_8007DEA0) < 0) return;
    func_80017CF4(*(s32 *)(o + 1272), 0, func_8000EB20("SWIM_WAKE"));
    q = o + 1276;
    *(s32 *)(o + 1472) = *(s32 *)(o + 1272);
    *(f32 *)(o + 1496) = 255.0f;
    ident(o + 1296);
    zt(o + 1296);
    func_800ADC54(q, 1);
    *(s32 *)(q + 192) |= 0x14;
    *(s32 *)(o + 1276) = 87;
    *(s32 *)(q + 192) |= 2;
    func_800AC37C(q, o);
    func_800ADC38(q);
    o[1488] = 1;
    o[1489] = 0;
    func_8007CA64(o, 0);
}
