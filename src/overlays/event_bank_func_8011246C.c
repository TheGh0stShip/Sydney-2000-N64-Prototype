typedef unsigned char u8;
typedef unsigned int u32;
extern u32 D_800F13F0;
extern void func_800B9E9C(u8 *, short, int, float, int);
static inline u32 rnd(u32 n)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * n) >> 16;
}
void func_8007D77C(u8 *o)
{
    u32 r = rnd(10);
    short *p;
    if (r >= 7) {
        p = (short *)(o + 432);
        *(short *)(o + 430) = 61;
        p[0] = 62;
        o[743] = 1;
    } else if (r >= 4) {
        p = (short *)(o + 432);
        *(short *)(o + 430) = 59;
        o[743] = 0;
        p[0] = 63;
    } else {
        p = (short *)(o + 432);
        *(short *)(o + 430) = 59;
        o[743] = 0;
        p[0] = 64;
    }
    p[1] = -1;
    o[429] = 0;
    func_800B9E9C(o, *(short *)(o + 430), -1, *(float *)(o + 632), 0);
    *(float *)(o + 632) = *(float *)(o + 804);
}
