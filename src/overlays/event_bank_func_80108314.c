typedef int s32;
typedef unsigned char u8;
typedef float f32;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern void func_800AB2A4(void *, s32, s32, s32, s32, s32);
void func_8007BD64(u8 *o, f32 a, f32 b)
{
    f32 t = *(f32 *)(o + 820) * *(f32 *)(o + 836);
    if (t > 0.0f) {
        t *= b - a; t += a;
    }
    *(f32 *)(o + 756) = t;
    if (t > 1.1f) {
        s32 h = *(s32 *)(o + 4);
        func_800AB2A4(D_800F26E0, D_800F2744, 15, h, 0, 0);
    }
}
