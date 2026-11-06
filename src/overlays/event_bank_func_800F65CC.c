typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern void func_800B8C70(u8 *obj, f32 v);

void func_800F65CC(u8 *obj, f32 lo, f32 hi)
{
    f32 x = *(f32 *)(obj + 768);
    f32 v = x * *(f32 *)(obj + 752);

    if (0.0f < v) {
        v *= hi - lo;
        v += lo;
    }
    *(f32 *)(obj + 632) = v;
    func_800B8C70(obj, v);
    if (*(f32 *)0x80078C18 < x) {
        x = *(f32 *)0x80078C18;
    } else if (x < *(f32 *)0x80078C1C) {
        x = *(f32 *)0x80078C1C;
    } else {
        x -= *(f32 *)0x80078C1C;
        goto scale;
    }
    x -= *(f32 *)0x80078C20;
scale:
    x *= *(f32 *)0x80078C24;
    *(s32 *)(obj + 240) = 0;
    *(f32 *)(obj + 236) = x;
}
