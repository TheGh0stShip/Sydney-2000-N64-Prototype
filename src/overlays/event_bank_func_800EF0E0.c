typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern u8 *D_800FC270;
extern u32 D_800F13F0;
extern s32 func_8007B800(u8 *o, f32 x);
extern s8 func_8009B670(u8 *o);
extern void func_800B9FA4(u8 *o, s32 a, s32 b, f32 c, s32 d, s32 e);

static inline u32 rnd(u32 n)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * n) >> 16;
}

void func_800EF0E0(u8 *o, f32 x)
{
    s32 hit;
    s32 a;
    s32 flag;
    s32 one;
    f32 f;
    u8 *g = D_800FC270;
    s32 t;

    W(o, 768) = 0;
    W(o, 772) = 0;
    t = W(g, 2560);
    switch (t) {
    case 5:
        f = F(g, 3560);
        break;
    case 4:
        if (F(g, 1324) < x) {
            W(o, 772) = 1;
            hit = 1;
            goto done;
        }
    default:
        f = F(D_800FC270, 1280);
        break;
    }
    if (f < x) {
        W(o, 768) = 1;
        hit = 1;
    } else {
        hit = 0;
    }
done:
    W(o, 776) = 0;
    flag = 0;
    if (W(W(o, 784), 1168) == 0 || W(o, 744) == 0) {
        flag = 1;
    }
    if (flag) {
        W(o, 748) = 0;
        switch (rnd(4)) {
        case 0:
            a = 31;
            break;
        case 1:
            a = 30;
            break;
        case 2:
            a = 32;
            break;
        default:
            a = 33;
            break;
        }
    } else {
        one = 1;
        W(o, 748) = one;
        if (hit) {
            switch (rnd(3)) {
            case 0:
                a = 28;
                break;
            case 1:
                a = 26;
                break;
            default:
                a = 29;
                break;
            }
            W(o, 748) = 2;
        } else if (*(s8 *)(W(o, 4) + 0x8000 + 1044) > 0) {
            hit = func_8007B800(o, x);
            if (hit != 0) {
                switch (func_8009B670(o)) {
                case 0:
                    a = 28;
                    W(o, 776) = one;
                    W(o, 748) = 2;
                    break;
                case 1:
                case 2:
                    a = 26;
                    W(o, 776) = one;
                    W(o, 748) = 2;
                    break;
                default:
                    a = 27;
                    break;
                }
            } else {
                a = 32;
            }
        } else {
            switch (func_8009B670(o)) {
            case 0:
                a = 28;
                W(o, 748) = 2;
                break;
            case 1:
            case 2:
                a = 26;
                W(o, 748) = 2;
                break;
            default:
                a = 27;
                break;
            }
        }
    }
    func_800B9FA4(o, a, -1, 1.0f, 0, 1);
}
