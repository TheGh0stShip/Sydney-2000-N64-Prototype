typedef unsigned char u8;
typedef int s32;

typedef struct D1AE0 { u8 pad[104]; s32 vol; } D1AE0;
typedef struct G { u8 pad[2560]; s32 mode; } G;
extern D1AE0 D_800F1AE0;
extern G *D_800FC270;
extern u8 D_8007750C[];
extern s32 D_8007735C;
extern u8 D_800F26E0[];
extern s32 D_800F2744;

extern s32 func_8001D4B8(D1AE0 *d, s32 a, s32 b, s32 c);
extern void func_8001D640(D1AE0 *d, s32 a, s32 b);
extern void func_80075348(u8 *p);
extern void func_800D33A0(u8 *p, u8 *d, s32 a, s32 b);
extern void func_800A9BE8(u8 *p, s32 a);
extern void func_800CC418(u8 *p);
extern void func_80076204(u8 *p);
extern s32 func_80017D54(void);
extern void func_800AB2A4(u8 *a, s32 b, s32 c, s32 d, s32 e, s32 f);

#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

static inline s32 scale(s32 v, s32 k)
{
    return (v * k) >> 15;
}

void func_800D6E1C(u8 *p)
{
    u8 c;

    W(24932) -= 256;
    if (W(24932) > 0) {
        return;
    }
    func_8001D640(&D_800F1AE0, func_8001D4B8(&D_800F1AE0, 143, 0, 1),
                  scale(D_800F1AE0.vol, 32767));
    B(25011) = 1;
    if (D_800FC270->mode != 6 && B(1557) != 4) {
        func_80075348(p);
    }
    if (B(1557) != 5) {
        func_800D33A0(p + 12884, D_8007750C, 0, -1);
    }
    c = B(1557);
    if (c == 2) {
        u8 *q;
        func_800A9BE8(p + 1116, 17);
        q = p + 1360;
        q[185] = 1;
        q[184] = 1;
        q[186] = 0;
        q[187] = 0;
        W(24932) = 27648;
        B(1551) = 36;
    } else if (c == 5 || c == 1) {
        func_800A9BE8(p + 1116, 14);
        W(24932) = 3840;
        B(1551) = 15;
    } else {
        W(24932) = 16896;
        B(1551) = 34;
        func_800CC418(p + 22784);
    }
    func_80076204(p);
    if (func_80017D54()) {
        func_800AB2A4(D_800F26E0, D_800F2744, 12, D_8007735C, 0, 0);
    }
}
