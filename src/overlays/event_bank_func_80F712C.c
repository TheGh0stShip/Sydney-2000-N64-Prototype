typedef int s32;
typedef unsigned char u8;
typedef float f32;
#define F32(o) (*(f32 *)(a + (o)))
extern u8 D_80076D40[];
extern void *func_800AEF6C(void *, s32);
extern void func_800AF0BC(void *, f32 *);
extern void func_800AF088(void *, void *);
extern void func_800AD6D0(f32 *, f32 *);
extern void func_800AE72C(char *, char *, void *);
static inline void snap(char *a)
{
    char *p = a + 0x14;
    char *q;

    F32(0x170) = *(f32 *)(p + 0x40);
    q = a + 0x170;
    *(f32 *)(q + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(q + 8) = *(f32 *)(p + 0x48);
    F32(0x188) = *(f32 *)(p + 0x40);
    a += 0x188;
    *(f32 *)(a + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(a + 8) = *(f32 *)(p + 0x48);
}
void func_8007903C(char *a)
{
    f32 v1[4];
    f32 v2[4];
    void *h;
    f32 *p;
    f32 *q;
    f32 k;
    h = func_800AEF6C(D_80076D40, 0);
    func_800AF0BC(h, v1);
    func_800AF088(h, v2);
    func_800AF088(h, a + 844);
    p = v1;
    v2[0] -= v1[0];
    v2[1] -= p[1];
    v2[2] -= p[2];
    func_800AD6D0(v2, v2);
    func_800AE72C(a + 652, a, func_800AEF6C(D_80076D40, 0));
    k = -32.767f;
    v2[0] *= k;
    v2[1] *= k;
    v2[2] *= k;
    F32(84) -= v2[0];
    q = (f32 *)(a + 84);
    q[1] -= v2[1];
    q[2] -= v2[2];
    snap(a);
}
