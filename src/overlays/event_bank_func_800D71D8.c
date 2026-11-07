typedef unsigned char u8;
typedef int s32;

typedef struct G { u8 pad[3344]; s32 lim; } G;
extern G *D_800FC270;
extern s32 D_800F13F0;
extern u8 D_80077610;

extern void func_800D29E0(u8 *p);
extern void func_80075F84(u8 *p);
extern void func_8009AC98(s32 a, s32 b, u8 *c, s32 d);
extern void func_800A9BE8(u8 *p, s32 a);
extern void func_80073CF0(u8 *p);
extern void func_8009BD48(s32 a);
extern void func_80074E18(u8 *p);
extern void func_800AC25C(u8 *p, s32 a, s32 b, s32 c);

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

void func_800D71D8(u8 *p)
{
    s32 v;

    W(24932) -= 256;
    if (W(24932) > 0) {
        return;
    }
    if (B(1557) == 0) {
        func_800D29E0(p + 12884);
        func_80075F84(p);
        func_8009AC98(225, B(1550), p + 2016, 2);
        func_800A9BE8(p + 1116, 12);
        W(24932) = 0x1C200;
        B(1551) = 30;
        return;
    }
    if (B(1557) == 5 || B(1557) == 1) {
        B(1551) = 31;
        return;
    }
    if (B(1557) == 4 && D_800FC270->lim >= W(24940)) {
        func_80073CF0(p);
        return;
    }
    if (B(1557) == 2) {
        func_800D29E0(p + 12884);
        W(24944) = -7680;
        B(1557) = 3;
        func_8009BD48(3);
    } else {
        v = W(1628);
        if (v == 0) {
            v = 1;
        }
        D_800F13F0 = v;
        if (B(1557) == 3) {
            func_80074E18(p);
        }
    }
    func_800AC25C(p, 91, 17, 0);
    func_800A9BE8(p + 1116, 5);
    B(1552) = D_80077610;
    B(1551) = 8;
}
