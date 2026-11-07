typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;
extern f32 D_80077BD8;
extern void *func_800AEF6C(void *, s32);
extern void func_800AF088(void *, f32 *);
void func_80076D40(u8 *o)
{
    f32 p[4];
    f32 v;
    f32 z;
    f32 s;
    s8 i;
    func_800AF088(func_800AEF6C(o + 25424, 8), p);
    i = 10;
    z = p[2];
    s = 299.4903869628906f;
    v = z;
    *(f32 *)(o + 25260) = v;
    v -= 459.3933410644531f;
    D_80077BD8 = z;
    do {
        i--;
        *(f32 *)((i << 2) + o + 25220) = v;
        v -= s;
    } while (i > 0);
}
