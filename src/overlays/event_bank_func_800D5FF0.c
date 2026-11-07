typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 pad[104]; s32 vol; } Snd;
extern Snd D_800F1AE0;
extern s32 func_8001D4B8(Snd *, s32, s32, s32);
extern void func_8001D640(Snd *, s32, s32);
extern void func_800AAC84(u8 *, u8 *, u8 *, s32);
extern void func_800BBB94(s32);
extern void func_8007439C(u8 *, u8, f32);
static inline s32 scl(s32 v, s32 m)
{
    return (v * m) >> 15;
}
void func_80071480(u8 *o, u8 *msg)
{
    u8 *p;
    u8 n;
    s32 v;
    p = *(u8 **)(msg + 12);
    n = p[733];
    o[1552] |= 1 << n;
    if (p[426] == 4) return;
    v = *(s32 *)(msg + 16);
    if (p[426] == 1) *(s32 *)(o + 24940) = v;
    if (o[1557] == 3) {
        s32 a = *(s32 *)(o + 24940);
        s32 b = *(s32 *)(o + 24944);
        if (a < b || b == -7680) {
            *(s32 *)(o + 24944) = a;
            func_800AAC84(p, o + (o[1553] * 8 + 1564), o + (o[1553] * 8 + 1572), 4800);
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 213, 0, 1), scl(D_800F1AE0.vol, 32767));
        } else {
            func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 131, 0, 1), scl(D_800F1AE0.vol, 32767));
        }
    } else {
        if (o[1557] == 2) func_800BBB94(*(s32 *)(p + 644));
        func_8007439C(o, n - o[1553], (f32)v / 30.0f * 0.00390625f);
    }
    if (o[1551] == 17) {
        *(s32 *)(o + 24932) = 3840;
        o[1551] = 25;
    }
}
