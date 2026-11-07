typedef unsigned char u8;
typedef int s32;
typedef float f32;
extern u8 *D_800F1A44;
extern const f32 D_8007DC94;

void func_800A14C0(u8 *p)
{
    if (p[256] >= 2) {
        f32 *s = (f32 *)(D_800F1A44 + 1168);
        f32 *d = (f32 *)(p + 232);
        f32 *q;
        f32 *o;
        f32 r;
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        q = (f32 *)(p + 20);
        *(f32 *)(p + 220) = q[16];
        o = (f32 *)(p + 220);
        o[1] = q[17];
        o[2] = q[18];
        *(f32 *)(p + 244) = D_8007DC94;
        *(s32 *)(p + 252) = 1;
        *(s32 *)(p + 248) = 0;
    }
}
