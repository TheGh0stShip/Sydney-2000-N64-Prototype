typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { s32 w[5]; } Vec5;
typedef struct { s16 delta; s16 index; void (*fn)(); } VEntry;

typedef struct { u8 b0; u8 b1; u8 pad[2]; f32 f4; u8 pad2[4]; } SlotEntry;
typedef struct { u8 pad[0x20]; u8 b20; u8 pad2[0x3C - 0x21]; } KindEntry;

extern u8 *D_800FC270;
extern f32 D_800713EC;
extern f32 D_800713F0;
extern f32 D_800713F4;
extern char D_800713D0[];
extern Vec5 D_800713D8;
extern char D_800F2758[];
extern char D_800F2A70[];
extern s32 D_80077680[];
extern char D_800714B8[];
extern char D_80078AE8[];

extern void func_800AA804(void *, void *, s32, void *);
extern void func_80017A90(s32);
extern void func_8001786C(s32);
extern s32 func_800DAC28(s32);
extern s32 func_800140A0(s32, s32, s32);
extern void func_800BA0EC(void *);
extern void func_800ADB70(void *);
extern u8 *func_800AAA58(s32, void *);
extern void func_800BA1FC(void *);
extern void func_800AED80(void *);
extern void func_800B4418(void *);
extern void func_8009A828(void *, s32, s32);
extern void func_80078BC0(void *, s32, void *);
extern void func_80075928(void *);

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define SB(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define VT(p, o) ((VEntry *)(P(p, o)))

void func_800B4474(u8 *s, s32 arg1)
{
    SlotEntry *e;
    u8 kind;
    u8 id;
    u8 *p;
    u8 *obj;
    VEntry *vt;
    s32 i;
    s32 v;
    f32 dy;
    u8 *g;

    e = (SlotEntry *)(D_800FC270 + 0xA10) + B(s, 0x5B79);
    if (e->f4 == *(f32 *)0x800713EC) {
        e->f4 = 0.0f;
    }
    kind = e->b0;
    id = e->b1;
    if (P(s, 0x532C) == 0) {
        func_800AA804(D_800F2758, s + 0x532C, 1740, D_800713D0);
        if (arg1 == 0 && id != SB(s, 0x59C4)) {
            func_80017A90(0x40000000);
            if (SB(s, 0x59C4) != -1 && W(s, 0x59C0) != 0) {
                func_8001786C(W(s, 0x59C0));
            }
            SB(s, 0x59C4) = id;
            W(s, 0x59C0) = func_800140A0(D_80077680[func_800DAC28(id)], id, 1);
            func_80017A90(0x20000000);
        }
    } else {
        W(s, 0x59C0) = W(P(s, 0x532C), 0x2D8);
        func_800BA0EC(P(s, 0x532C) + 0x4E8);
        func_800ADB70(P(s, 0x532C) + 0x4E8);
        { u8 *q = P(s, 0x532C); VEntry *w;
        w = (VEntry *)P(q, 0x59C);
        q += 0x4E8;
        w[1].fn(q + w[1].delta, 2); }
        func_800BA0EC(P(s, 0x532C));
        func_800ADB70(P(s, 0x532C));
        p = P(s, 0x532C);
        vt = (VEntry *)P(p, 0xB4);
        vt[1].fn(p + vt[1].delta, 2);
    }
    obj = func_800AAA58(1740, P(s, 0x532C));
    func_800BA1FC(obj);
    W(obj, 0xB4) = (s32)D_800714B8;
    func_800AED80(obj + 0x28C);
    B(obj, 0x1AC) = 0;
    H(obj, 0x27E) = 0;
    B(obj, 0xCA) = 0;
    W(obj, 0x284) = 0;
    W(obj, 0x288) = 0;
    W(obj, 0x2D8) = 0;
    W(obj, 0xB4) = (s32)D_80078AE8;
    func_800B4418(obj + 0x334);
    func_800BA1FC(obj + 0x4E8);
    func_800AED80(obj + 0x680);
    W(obj, 0) = 0x61;
    W(P(s, 0x532C), 0x2D8) = W(s, 0x59C0);
    W(P(s, 0x532C), 0x67C) = W(s, 0x5598);
    if (arg1 == 0) {
        p = P(s, 0x532C);
        vt = (VEntry *)P(p, 0xB4);
        vt[2].fn(p + vt[2].delta, s);
        p = P(s, 0x532C);
        vt = (VEntry *)P(p, 0xB4);
        vt[8].fn(p + vt[8].delta);
    }
    W(P(s, 0x532C), 0x284) = (s32)(s + 0x5BA8);
    W(P(s, 0x532C), 0x288) = (s32)D_800F2A70;
    B(P(s, 0x532C), 0x1A8) = kind;
    B(P(s, 0x532C), 0x1A9) = id;
    B(P(s, 0x532C), 0x27C) = id & 7;
    if ((s8)kind != 8) {
        { KindEntry *ke = (KindEntry *)D_800FC270 + (s8)kind; v = ke->b20; }
    } else {
        v = 3;
    }
    if (B(s, 0x5B7F) == 2) {
        B(P(s, 0x532C), 0x1AA) = 3;
    } else {
        B(P(s, 0x532C), 0x1AA) = v;
    }
    B(P(s, 0x532C), 0x1AB) = 0;
    if (B(s, 0x5B7F) == 2) {
        Vec5 tmp;
        p = P(s, 0x532C);
        tmp = D_800713D8;
        *(Vec5 *)(p + 0x194) = D_800713D8;
    } else {
        func_8009A828(P(s, 0x532C) + 0x194, id, (s8)kind);
    }
    dy = F(P(s, 0x532C), 0x194) * *(f32 *)0x800713F0 * *(f32 *)0x800713F4;
    g = D_800FC270;
    F(P(P(s, 0x5400), 8), 0x28) = F(s, 0x5BB0) + dy;
    F(P(P(s, 0x5534), 8), 0x28) = F(s, 0x5BB0) + dy;
    if (W(g, 0xA04) == 0) {
        W(P(s, 0x532C), 0x1A0) = 0;
    }
    if (arg1 == 0) {
        func_80078BC0(P(s, 0x532C), B(s, 0x5B78), s + 0x2B8);
        { s32 t = B(s, 0x5B7F);
        if (t < 5) goto call;
        if (t == 5) goto skip;
    call:
        func_80075928(s);
    skip:; }
    }
    W(s, 0x5BBC) = W(s, 0x5BC0);
    for (i = 0; (u8)i < B(s, 0x5B79); i++) {
        W(s, 0x5BBC)++;
        if (W(s, 0x5BBC) >= 210) {
            W(s, 0x5BBC) = 205;
        }
    }
}
