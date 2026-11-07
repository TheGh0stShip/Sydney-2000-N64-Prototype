typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct VE { s16 off; s16 pad; void (*fn)(); } VE;
typedef struct VT { u8 pad[24]; VE a; } VT;
typedef struct Obj { u8 pad[176]; u8 flag; u8 pad2[3]; VT *vt; } Obj;
typedef struct Pool { u8 *owner; s32 a; s32 b; s32 c; s16 d; s16 e; } Pool;

extern u8 D_800F2AD8[];
extern u8 D_800F26E0[];
extern u8 D_800F2758[];
extern u8 D_80077C80[];
extern u8 D_800F7270[];
extern u8 D_80077A30[];
extern u8 D_800F4D00[];
extern Pool D_800F26B0;

extern void func_8009BDC4(void);
extern void func_800BC274(u8 *a);
extern void func_800AACB0(u8 *a, s32 b, s32 c);
extern void func_800759C8(u8 *p);
extern void func_800AC25C(u8 *p, s32 a, s32 b, s32 c);
extern void func_800AA658(u8 *a, void *b);
extern void func_8008204C(u8 *a);
extern void func_800AC334(u8 *a);
extern void func_80082044(u8 *a);
extern void func_800D29E0(u8 *a);
extern void func_800ADC1C(u8 *a);
extern void func_800B35F0(u8 *a);
extern void func_800A8850(u8 *a);
extern void func_800AEFA0(u8 *a);
extern void func_8001A248(u8 *a);
extern void func_800D771C(u8 *a);
extern void func_80097A30(u8 *a);
extern void func_800CCE4C(u8 *a);
extern void func_80017B24(s32 a);
extern void func_800D7F5C(u8 *a);
extern void func_800BAC24(void);
extern void func_8007E394(u8 *a);
extern void func_800D52A8(u8 *a);
extern void func_8009C100(void);

#define W(o) (*(s32 *)(p + (o)))

static inline void reset(Obj *o)
{
    o->vt->a.fn((u8 *)o + o->vt->a.off);
    o->flag = 0;
}

void func_800AC4A0(u8 *p)
{
    u8 *q;
    u32 i;
    Obj *o0;
    Obj *o1;
    Obj *o2;
    Obj *o3;
    Pool *pl;
    u8 *own;

    func_8009BDC4();
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_800759C8(p);
    func_800AC25C(p, 107, 7, 0);
    if (W(0x8000 + 288) != 0) {
        func_800AA658(D_800F2758, p + 0x8120);
    }
    if (W(0x8000 + 316) != 0) {
        func_800AA658(D_800F2758, p + 0x813C);
    }
    q = p + 7244;
    func_8008204C(q);
    func_800AC334(q);
    func_80082044(q);
    q = p + 11928;
    func_800AC334(q);
    func_800D29E0(q);
    func_800ADC1C(q);
    q = p + 13328;
    func_800AC334(q);
    func_800B35F0(q);
    func_800ADC1C(q);
    q = p + 13548;
    func_800AC334(q);
    func_800B35F0(q);
    func_800ADC1C(q);
    q = p + 30776;
    func_800AC334(q);
    func_800ADC1C(q);
    q = p + 32620;
    func_800AC334(q);
    func_800A8850(q);
    func_800AEFA0(D_80077C80);
    func_8001A248(p + 29916);
    func_8001A248(p + 29920);
    func_8001A248(p + 29924);
    q = p + 696;
    func_800D29E0(q);
    func_800AC334(q);
    o0 = (Obj *)(p + 19048);
    func_800D771C((u8 *)o0);
    reset(o0);
    o1 = (Obj *)(p + 2096);
    reset(o1);
    o2 = (Obj *)(p + 3496);
    reset(o2);
    o3 = (Obj *)(p + 4896);
    reset(o3);
    func_800D29E0((u8 *)o1);
    func_800D29E0((u8 *)o2);
    func_800D29E0((u8 *)o3);
    func_80097A30(p + 13784);
    func_800CCE4C(p + 32392);
    func_800AC334(p + 216);
    func_80017B24(W(184));
    q = p + 6836;
    func_800AEFA0(D_800F7270);
    func_800D7F5C(q);
    for (i = 0; i < 8; i++) {
        *(s32 *)(q + 184) = 0;
        q += 4;
    }
    func_800AC334(p + 6836);
    func_800BAC24();
    q = p + 6296;
    func_800AEFA0(D_80077A30);
    func_8007E394(q);
    func_800AC334(q);
    func_800D52A8(D_800F4D00);
    pl = &D_800F26B0;
    own = pl->owner;
    if (own != 0) {
        pl->owner = 0;
        if (pl->a != 0) {
            func_800AA658(own, &pl->a);
        }
        if (pl->b != 0) {
            func_800AA658(own, &pl->b);
        }
        pl->d = 0;
        pl->e = 0;
        pl->c = 0;
        pl->owner = 0;
    }
    func_8009C100();
    W(172) = 1;
}
