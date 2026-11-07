typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern u32 D_800F13F0;
extern void func_800B9E9C(void *, s32, s32, s32, s32);

static inline u32 rnd(u32 n)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * n) >> 16;
}

void func_8007D050(u8 *o, s32 kind)
{
    s16 *p;
    u32 thr;

    thr = 0;
    *(s16 *)(o + 430) = 59;
    p = (s16 *)(o + 432);
    switch (kind) {
    case 0:
        break;
    case 1:
        thr = 30;
        break;
    case 2:
        thr = 90;
        break;
    }
    if (rnd(100) < thr) {
        *p++ = 67;
    } else if (rnd(50) < thr) {
        *p++ = 66;
    } else {
        *p++ = 65;
    }
    *p = -1;
    o[429] = 0;
    func_800B9E9C(o, *(s16 *)(o + 430), -1, *(s32 *)(o + 632), 0);
    o[743] = 0;
    *(f32 *)(o + 632) = *(f32 *)(o + 804);
}
