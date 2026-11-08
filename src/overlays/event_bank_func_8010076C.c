typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern u32 D_800F2714;
extern void func_800770A4(s32 a);
extern void func_800B9FA4(u8 *o, s32 a, s32 b, f32 c, s32 d, s32 e);
extern void func_800B9E9C(u8 *o, s32 a, s32 b, f32 c, s32 d);
extern void func_800B9BD4(u8 *o, s32 a, f32 *b, s32 *c, f32 *d, s32 e);
extern void func_800B9964(u8 *o, f32 *a, s32 *b, f32 *c);
extern void func_8007B70C(u8 *o, f32 *a);
extern void func_800B9E74(u8 *o, s32 a);

typedef struct Obj {
    u8 pad[430];
    s16 anim[8];
} Obj;

static inline u32 rnd(u32 n)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * n) >> 16;
}

void func_8010076C(u8 *o, u8 a1, u8 a2, u8 a3, u8 a5)
{
    s16 *q;
    u8 *o2;
    u32 r;
    s32 last;
    s32 done;
    f32 b0[4];
    f32 b1[4];
    f32 b2[4];
    f32 b3[4];
    s32 c0;
    s32 c1;

    r = rnd(4);
    done = 0;
    last = 13;
    func_800770A4(W(o, 4));
    W(W(o, 816), 192) |= 4;
    F(o, 756) = F(o, 760) = F(o, 772) = F(o, 768) = F(o, 764) = F(o, 752) = F(o, 748) = 0.0f;
    o[745] = 0;
    o[744] = 0;
    o[743] = 0;
    o[742] = 0;
    o[741] = 0;
    W(o, 172) = 23;
    {
        u8 *p2 = o + 1256;
        W(p2, 192) &= ~4;
    }
    q = (s16 *)(o + 430);
    W(o, 192) &= ~4;
    if (a3 && !a5) {
        last = 14;
        H(o, 430) = 10;
        H(o, 432) = 11;
        H(o, 434) = last;
        q = (s16 *)(o + 436);
    } else {
        if (r != 0 || a5) {
            if ((a1 == 2 && a2) || a5) {
                *q++ = 10;
                *q++ = 15;
                last = 13;
                *q++ = last;
                done = 1;
            } else if (a1 == 0 || !a2) {
                *q++ = 16;
                last = 12;
                *q++ = last;
                done = 1;
            }
        }
        if (!done) {
            r = rnd(3);
            *q++ = 10;
            if (o[733] < 3 && r == 0) {
                r = 2;
            }
            if ((u32)(o[733] - 4) < 3 && r == 1) {
                r = 2;
            }
            switch ((u8)r) {
            case 0:
                *q++ = 18;
                last = 4;
                *q++ = last;
                break;
            case 1:
                *q++ = 19;
                last = 3;
                *q++ = last;
                break;
            case 2:
                *q++ = 17;
                last = 2;
                *q++ = last;
                break;
            }
        }
    }
    o2 = o + 1256;
    q[0] = last;
    q[1] = -1;
    o[429] = 0;
    func_800B9FA4(o2, H(o, 430), -1, F(o, 632), 0, 1);
    func_800B9FA4(o, ((Obj *)o)->anim[o[429]++], -1, F(o, 632), 0, 1);
    func_800B9E9C(o2, ((Obj *)o)->anim[o[429]], -1, F(o, 632), 0);
    func_800B9E9C(o, ((Obj *)o)->anim[o[429]++], -1, F(o, 632), 0);
    func_800B9BD4(o, 1, b0, &c0, b1, 0);
    func_800B9BD4(o2, 1, b2, &c1, b3, 0);
    func_800B9964(o, b0, &c0, b1);
    func_8007B70C(o, b2);
    func_800B9E74(o, 4);
    func_800B9E74(o2, 4);
}
