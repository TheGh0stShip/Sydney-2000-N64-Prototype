typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { s32 w[5]; } S20;
typedef void (*Fn)(void *, ...);

extern void func_800BC274(void *);
extern void func_800AA804(void *, void *, s32, void *);
extern void func_80017A90(s32);
extern void func_8001786C(s32);
extern s32 func_800DAC28(s32);
extern s32 func_800140A0(s32, s32, s32);
extern u8 *func_800AAA58(s32, u8 *);
extern void func_800BA1FC(u8 *);
extern void func_800AED80(u8 *);
extern void func_8009A828(u8 *, s32, s32);
extern void func_8007B17C(u8 *, s32);
extern void func_80081030(u8 *, s32);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800820DC(u8 *);
extern void func_800CD34C(u8 *, s32, f32);
extern void func_800B7130(u8 *, s32, s32, s32, s32);
extern void func_800BA068(u8 *, s32);
extern void func_80078EE8(u8 *, u8 *);
extern void func_800BBD78(void *, s32, s32, u8 *, s32);

extern u8 D_800F2AD8[];
extern u8 D_800F2758[];
extern u8 D_80071320[];
extern u8 D_80071438[];
extern u8 D_80078A70[];
extern u8 D_800F2A70[];
extern s32 D_80077A40[];
extern S20 D_80071328;

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define OBJ(g) (*(u8 **)((g) + 11704))
extern u8 *D_800FC270;
#define TBL D_800FC270

void func_800AC7B0(u8 *g, s32 flag)
{
    u8 *rec;
    u8 a, b;
    u8 *o;
    u8 *vt;
    u8 *hi;
    u8 *s3;
    s32 v;
    double d;
    f32 f, x, y;
    S20 tmp;
    s32 *tbl;
    s32 k;
    u8 vk;

    func_800BC274(D_800F2AD8);
    rec = TBL + (SB(g + 0x8000, 284) * 12 + 2576);
    a = rec[0];
    b = rec[1];
    if (OBJ(g) == 0) {
        func_800AA804(D_800F2758, g + 11704, 924, D_80071320);
        if (flag == 0) {
            func_80017A90(0x40000000);
            if (b != SB(g, 13780)) {
                if (SB(g, 13780) != -1 && W(g, 13776) != 0) {
                    func_8001786C(W(g, 13776));
                }
                tbl = D_80077A40;
                SB(g, 13780) = b;
                W(g, 13776) = func_800140A0(tbl[func_800DAC28(b)], b, 1);
            }
            func_80017A90(0x20000000);
        }
    } else {
        W(g, 13776) = W(OBJ(g), 728);
    }
    o = func_800AAA58(924, OBJ(g));
    func_800BA1FC(o);
    W(o, 180) = (s32)D_80071438;
    func_800AED80(o + 652);
    W(o, 180) = (s32)D_80078A70;
    B(o, 428) = 0;
    H(o, 638) = 0;
    B(o, 202) = 0;
    W(o, 644) = 0;
    W(o, 648) = 0;
    W(o, 728) = 0;
    W(o, 740) = 0;
    W(o, 744) = 0;
    W(o, 752) = 0;
    W(o, 916) = 0;
    W(o, 920) = 0;
    W(o, 0) = 100;
    W(OBJ(g), 728) = W(g, 13776);
    if (flag == 0) {
        u8 *q = OBJ(g);
        u8 *t = *(u8 **)(q + 180);
        ((Fn)W(t, 20))(q + H(t, 16), g);
    }
    W(OBJ(g), 644) = (s32)(g + 0x8124);
    W(OBJ(g), 648) = (s32)D_800F2A70;
    B(OBJ(g), 424) = a;
    B(OBJ(g), 425) = b;
    B(OBJ(g), 636) = b & 7;
    k = (s8)a;
    if (k != 8) {
        u8 *r = TBL + k * 60;
        u8 *q = OBJ(g);
        vk = *(volatile u8 *)(r + 32);
        W(r, 72) = (s32)q;
    } else {
        vk = 3;
    }
    B(OBJ(g), 426) = vk;
    B(OBJ(g), 427) = 0;
    if (B(g + 0x8000, 286) == 2) {
        u8 *q = OBJ(g);
        tmp = D_80071328;
        *(S20 *)(q + 404) = D_80071328;
    } else {
        func_8009A828(OBJ(g) + 404, b, (s8)a);
    }
    if (W(TBL, 2564) == 0) {
        W(OBJ(g), 416) = 0;
    }
    hi = g + 0x8000;
    func_8007B17C(OBJ(g), W(hi, 316) + SB(hi, 284) * 32);
    if (flag == 0) {
        s3 = g + 7244;
        func_80081030(s3, W(g, 13772));
        func_800AC37C(s3, g);
        func_800820DC(s3);
        v = W(g, 13772) - 150;
        d = v;
        if (v < 0) {
            d += *(double *)0x80071340;
        }
        f = d;
        f = f / *(f32 *)0x80071348;
        x = f * *(f32 *)0x8007134C + *(f32 *)0x80071354;
        y = f * *(f32 *)0x80071350 + *(f32 *)0x80071358;
        F(hi, 320) = x;
        F(hi, 324) = y;
        func_800CD34C(g + 15368, 0, F(hi, 320));
        func_800CD34C(g + 15368, 1, F(hi, 324));
        {
            s32 t2 = W(g, 32608);
            func_800B7130(OBJ(g), W(g, 13776), t2, 0, 1);
        }
        func_800BA068(OBJ(g), W(g, 32612));
        func_80078EE8(OBJ(g), s3);
        {
            u8 *q = OBJ(g);
            u8 *t = *(u8 **)(q + 180);
            ((Fn)W(t, 68))(q + H(t, 64));
        }
    }
    func_800BBD78(D_800F2AD8, 12, 1, g, 0);
}
