typedef unsigned char u8;
typedef int s32;
typedef float f32;

#define S32(o) (*(s32 *)(obj + (o)))

typedef struct {
    char pad0[0xC0];
    s32 flags;
    char padC4[0xD4 - 0xC4];
} Rec;

extern u8 D_800F1AE0[];
extern void func_800B9E9C(u8 *p, s32 a, s32 b, f32 c, s32 d);
extern s32 func_800B9BD4(u8 *p, s32 a, f32 *b, f32 *c, f32 *d, s32 e);
extern void func_800B9964(u8 *p, f32 *b, f32 *c, f32 *d);
extern s32 func_8001D4B8(u8 *p, s32 a, s32 b, s32 c);
extern void func_8001D640(u8 *p, s32 a, s32 b);

static inline s32 scale15(s32 x, s32 k)
{
    return (x * k) >> 15;
}

void func_8007117C(u8 *obj, s32 arg)
{
    f32 a[4];
    f32 b[4];
    f32 c[2];

    S32(3852) -= 256;
    if (S32(3852) <= 0) {
        S32(17132) = 2;
    }
    if (obj[19374] == obj[19373]) {
        switch (obj[19373]) {
        case 0:
            if (S32(19404) == 1) {
                S32(19392) = 0;
            } else {
                S32(19392) = 1;
            }
            break;
        case 1:
            if (S32(19404) == 1 && S32(19412) == 1) {
                S32(19392) = 0;
            } else {
                S32(19392) = 1;
            }
            break;
        case 2:
            if (S32(19408) == 1 && S32(19412) == 1) {
                S32(19392) = 0;
            } else {
                S32(19392) = 1;
            }
            break;
        case 3:
            if (S32(19408) == 1) {
                S32(19392) = 0;
            } else {
                S32(19392) = 1;
            }
            break;
        }
        S32(19392) = 0;
        if (func_800B9BD4(obj + 4552, arg, a, c, b, 0) != 0) {
            S32(17132) = 8;
            S32(19400) = 1;
            obj[19375] = 0;
            ((Rec *)(obj + 17156))[obj[19373]].flags |= 4;
            ((Rec *)(obj + 18020))[obj[19373]].flags &= ~4;
        }
        func_800B9964(obj + 4552, a, c, b);
        return;
    }
    if (func_800B9BD4(obj + 4552, arg, a, c, b, 0) != 0) {
        if (obj[19375] == 0) {
            s32 h = func_8001D4B8(D_800F1AE0, 193, 0, 1);
            func_8001D640(D_800F1AE0, h, scale15(*(s32 *)(D_800F1AE0 + 104), 32767));
        }
        if (++obj[19375] == 2) {
            obj[19375] = 0;
            S32(17132) = 5;
            func_800B9E9C(obj + 4552, 0, -1, 2.0f, 0);
        }
    }
    func_800B9964(obj + 4552, a, c, b);
    S32(19408) = 0;
    S32(19404) = 0;
}
