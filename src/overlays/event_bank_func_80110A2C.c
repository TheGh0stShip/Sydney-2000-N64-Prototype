typedef int s32;
typedef unsigned char u8;
typedef float f32;
#define U8(o) (*(u8 *)(a + (o)))
#define S32(o) (*(s32 *)(a + (o)))
#define F32(o) (*(f32 *)(a + (o)))
#define PTR(o) (*(char **)(a + (o)))
extern void func_8007C914(char *, s32);
extern void func_8007CA64(char *, s32);
extern void func_800B9E74(char *, s32);
extern void func_800B9FA4(char *, s32, s32, f32, s32, s32);
static inline void snap(char *a)
{
    char *p = a + 0x14;
    char *q;

    F32(0x170) = *(f32 *)(p + 0x40);
    q = a + 0x170;
    *(f32 *)(q + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(q + 8) = *(f32 *)(p + 0x48);
    F32(0x188) = *(f32 *)(p + 0x40);
    q = a + 0x188;
    *(f32 *)(q + 4) = *(f32 *)(p + 0x44);
    *(f32 *)(q + 8) = *(f32 *)(p + 0x48);
}
void func_8007BD3C(char *a)
{
    f32 t;
    char *q;
    char *b;
    func_8007C914(a, 0);
    func_8007CA64(a, 0);
    F32(0x5D8) = 255.0f;
    F32(0x54) = -1769.41797f;
    F32(0x4EC) = 0.144174799f;
    t = (8.74f - U8(0x2DD) * 2.49f) * 32.767f;
    S32(0x5D4) = 0;
    S32(0x58) = 0;
    U8(0x5D0) = 1;
    F32(0x5C) = t;
    F32(0x32C) = t;
    q = a + 0x4EC;
    *(f32 *)(q + 4) = 0.0f;
    *(f32 *)(q + 8) = 0.0f;
    snap(a);
    b = PTR(0x288);
    b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0;
    F32(0x278) = F32(0x324);
    func_800B9FA4(a, 37, -1, F32(0x278), 0, 1);
    func_800B9E74(a, 2);
    U8(0x2E8) = 1;
    S32(0xAC) = 7;
    S32(0x4E8) = S32(0x31C);
}
