typedef unsigned char u8;
typedef float f32;

typedef struct { u8 pad0[4]; f32 v; u8 pad8[28]; } Ent36;

extern void func_800A13A0(u8 *p, f32 v);

void func_800EBC74(u8 *obj)
{
    f32 d = *(f32 *)(obj + 1084);
    f32 z = 0.0f;
    f32 r = *(f32 *)0x80078CA8;
    f32 t;

    if (d != z) {
        t = *(f32 *)(obj + 88) - (*(Ent36 **)(obj + 1080))[obj[1044]].v;
        t /= d;
        if (*(f32 *)0x80078CAC < t)
            t = *(f32 *)0x80078CAC;
        if (t < z)
            t = z;
        r -= t * *(f32 *)0x80078CB0;
    }
    func_800A13A0((obj[1044] * 496 + 0x8CDC) + *(u8 **)(obj + 4), r);
}
