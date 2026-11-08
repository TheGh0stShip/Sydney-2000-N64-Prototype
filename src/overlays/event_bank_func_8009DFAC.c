typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern u8 *D_800FC270;

extern void func_80074D54(u8 *);
extern void func_8007D298(void *);
extern void func_800A9AE4(void *, void *);
extern void func_800A9BE8(void *, s32);
extern void func_800CC294(void *, s32, s32, s32);
extern void func_800D2164(void *, f32);
extern void func_800D26AC(void *);
extern void func_800E805C(void *, void *);

#define B(o) (p[o])
#define W(o) (*(s32 *)(p + (o)))
#define P(o) (*(u8 **)(p + (o)))

void func_800721EC(u8 *p)
{
    f32 f;
    u8 *q;

    W(0x5E08) -= 256;
    if (W(0x5E08) > 0) {
        return;
    }
    func_80074D54(p);
    W(0x4690) = 3;
    B(0x5DE7) = 5;
    W(0x5E08) = 0;
    B(0x6DC) = 0;
    W(0x5E20) = 0;
    W(0x5E40) = -7680;
    W(0x5E44) = -7680;
    if (P(0x5CA0) != 0) {
        func_8007D298(P(0x5CA0));
    }
    if (P(0x5CA4) != 0) {
        func_8007D298(P(0x5CA4));
    }
    switch (B(0x5DE9)) {
    case 0:
    case 3:
    case 4:
        if (P(0x5CA0)[0x1AA] == 1) {
            q = p + 0x4694;
            func_800CC294(p + 0x5414, 0, 0x753000, 2);
            if (B(0x5DE9) == 4) {
                f = (f32)*(s32 *)(D_800FC270 + 0xD10) / 30.0f * 0.00390625f;
                func_800D2164(q, f);
            } else {
                f = (f32)W(0x5E0C) / 30.0f * 0.00390625f;
                func_800D2164(q, f);
            }
            func_800D26AC(p + 0x4694);
            func_800E805C(p + 0x30C, P(0x5CA0));
            func_800A9AE4(p + 0x5CB0, p + 0x30C);
            break;
        }
    case 1:
    case 2:
    case 5:
        func_800A9BE8(p + 0x5CB0, 6);
        break;
    }
}
