typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern u32 D_800F2C14;
extern void func_8007B834(u8 *);
extern void func_80075FC8(s32);
extern s32 func_8007BBE4(u8 *);
extern void func_800B9E9C(u8 *, s32, s32, f32, s32);
extern void func_800B9E74(u8 *, s32);
extern void func_800794B0(u8 *, s32);
void func_80078C60(u8 *o, s32 *m)
{
    s32 d = (m[1] - *(s32 *)(o + 16)) >> 8;
    s32 p = *(s32 *)(*(u8 **)(o + 4) + 4);
    switch (m[0]) {
    case 3:
        break;
    case 12:
        *(s32 *)(o + 172) = 5;
        func_800794B0(o, d);
        break;
    case 15:
        *(s32 *)(o + 172) = 7;
        func_800794B0(o, d);
        break;
    case 17:
        func_8007B834(o);
        func_80075FC8(p);
        *(s32 *)(o + 172) = 8;
        D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
        *(f32 *)(o + 608) = (f32)(D_800F2C14 >> 19) * (1.0f / 4096.0f) * 0.2f + 0.8f;
        func_800B9E9C(o, func_8007BBE4(o), -1, *(f32 *)(o + 608), 0);
        func_800B9E74(o, 4);
        func_800794B0(o, d);
        break;
    case 5:
        func_800794B0(o, d);
        break;
    case 26:
        func_800794B0(o, d);
        break;
    case 13:
        *(s32 *)(o + 172) = 9;
        break;
    }
    *(s32 *)(o + 16) = m[1];
}
