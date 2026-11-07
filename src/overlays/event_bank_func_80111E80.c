typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
extern void func_8008D8E8(u8 *, f32 *, u16, s32, f32);
void func_8007D190(u8 *o)
{
    f32 v[3];
    u8 *p = o + 20;
    f32 *q;
    u8 *h;
    u16 t;
    v[0] = *(f32 *)(p + 64);
    q = v;
    q[1] = *(f32 *)(p + 68);
    q[2] = *(f32 *)(p + 72);
    h = *(u8 **)(o + 4);
    t = *(u16 *)(o + 746) + *(s8 *)(o + 745);
    *(u16 *)(o + 746) = t;
    if (t > 20) {
        *(s8 *)(o + 745) = -2;
    } else if (t < 3) {
        *(s8 *)(o + 745) = 2;
    }
    if (o[735]) {
        v[0] += 49.1504974f;
    } else {
        v[0] -= 16.3834991f;
    }
    if (o[735]) {
        func_8008D8E8(h + 15956, v, *(u16 *)(o + 746), 1, *(f32 *)(o + 1496));
    } else {
        func_8008D8E8(h + 15956, v, *(u16 *)(o + 746), 0, *(f32 *)(o + 1496));
    }
}
