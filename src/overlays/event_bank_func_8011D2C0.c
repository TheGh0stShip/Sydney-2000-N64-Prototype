typedef int s32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
#define F32(x) (*(f32 *)(o + (x)))
#define S32(x) (*(s32 *)(o + (x)))
#define PTR(x) (*(u8 **)(o + (x)))
extern u8 D_80080A20[];
extern s32 func_800140A0(void *, s32, s32);
extern void func_800B7130(u8 *, s32, s32, s32, s32);
extern void func_800ADC54(u8 *, s32);
extern void func_800AD890(u8 *, s32);
extern void func_800B9FA4(u8 *, s32, s32, f32, s32, s32);
extern s32 func_800B9BD4(u8 *p, s32 a, f32 *b, void *c, f32 *d, s32 e);
extern void func_800B8C70(u8 *obj, f32 v);
static inline void vset(f32 *v, f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}
void func_80081C40(u8 *o)
{
    f32 a[4];
    f32 c[4];
    struct { s32 x; unsigned short y; } b;
    s32 v;
    s32 h;
    f32 *q;
    u8 *p;
    F32(428) = 0.0f;
    if (S32(196) == 0) {
        v = func_800140A0(D_80080A20, -1, 1);
        S32(408) = *(s32 *)(PTR(4) + 29672);
        S32(404) = v;
        func_800B7130(o, v, S32(408), 0, 0);
        func_800ADC54(o, 1);
        func_800AD890(o, 1);
        o[202] = 7;
        *(u32 *)(o + 192) |= 0x2000;
        *(f32 *)(*(u8 **)(PTR(208) + 8) + 40) = 0.00471238885f;
        *(f32 *)(*(u8 **)(PTR(208) + 8)) = 0.00471238885f;
    }
    func_800B9FA4(o, 0, -1, 0.4f, 0, 1);
    func_800B9BD4(o, 1, a, &b, c, 0);
    vset((f32 *)(o + 84), 0.01f, F32(428), 0.00471238885f);
    p = o + 20;
    F32(368) = *(f32 *)(p + 64);
    q = (f32 *)(o + 368);
    q[1] = *(f32 *)(p + 68);
    q[2] = *(f32 *)(p + 72);
    func_800B8C70(o, 0.4f);
    S32(432) = 0;
    S32(436) = 0;
    S32(440) = 0;
    S32(444) = 0;
    S32(172) = 0;
    F32(424) = 0.25f;
}
