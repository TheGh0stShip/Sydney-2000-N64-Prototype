typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern u32 D_800F13F0[];
extern u16 D_8007C378[];
extern void func_800B9E9C(u8 *o, s32 a, s32 b, s32 c, s32 d);

static inline u32 rnd(u32 n)
{
    D_800F13F0[0] = (D_800F13F0[0] * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0[0] >> 15) * n) >> 16;
}

void func_800F5B68(u8 *o)
{
    s16 *p = (s16 *)(o + 430);
    u32 r = rnd(35);
    s32 n;

    if (r >= 20) {
        if (r + o[1229] >= 24) {
            *p++ = 37;
            for (n = rnd(10); n > 0; n--) {
                *p++ = 38;
            }
            *p++ = 39;
        } else {
            *p++ = 43;
            for (n = rnd(20); n > 0; n--) {
                *p++ = 44;
            }
            *p++ = 45;
            o[1229]++;
        }
    }
    n = r >> 2;
    do {
        D_800F13F0[0] = (D_800F13F0[0] * 16807) & 0x7FFFFFFF;
        n--;
        *p++ = D_8007C378[D_800F13F0[0] >> 29];
    } while (n > 0);
    *p = -1;
    o[429] = 0;
    func_800B9E9C(o, *(s16 *)(o + 430), -1, *(s32 *)(o + 632), 0);
    *(f32 *)(o + 632) = *(f32 *)(o + 788);
}
