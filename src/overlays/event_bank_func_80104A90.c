typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern void func_800B8C70(u8 *obj, f32 v);

void func_80104A90(u8 *obj, f32 lo, f32 hi)
{
    f32 x = *(f32 *)(obj + 768);
    f32 v = x * *(f32 *)(obj + 752);

    if (0.0f < v) {
        v *= hi - lo;
        v += lo;
    }
    *(f32 *)(obj + 632) = v;
    func_800B8C70(obj, v);
    if (*(f32 *)0x80078B90 < x) {
        x = *(f32 *)0x80078B90;
    } else if (x < *(f32 *)0x80078B94) {
        x = *(f32 *)0x80078B94;
    } else {
        x -= *(f32 *)0x80078B94;
        goto scale;
    }
    x -= *(f32 *)0x80078B98;
scale:
    x *= *(f32 *)0x80078B9C;
    *(s32 *)(obj + 240) = 0;
    *(f32 *)(obj + 236) = x;
}
