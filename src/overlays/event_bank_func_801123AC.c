typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;
extern unsigned int D_800F13F0;
extern void func_800B9E9C(u8 *obj, s32 a, s32 b, s32 c, s32 d);
static __inline__ unsigned int rand_n(unsigned int n)
{
    unsigned int seed = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    D_800F13F0 = seed;
    return ((seed >> 15) * n) >> 16;
}
void func_801123AC(u8 *obj){
    s16 *q;
    *(s16 *)(obj + 430) = 59;
    q = (s16 *)(obj + 432);
    if (rand_n(10) >= 6) q[0] = 63; else q[0] = 64;
    q++;
    *q = -1;
    obj[429] = 0;
    func_800B9E9C(obj, *(s16 *)(obj + 430), -1, *(s32 *)(obj + 632), 0);
    obj[743] = 0;
    *(f32 *)(obj + 632) = *(f32 *)(obj + 804);
}
