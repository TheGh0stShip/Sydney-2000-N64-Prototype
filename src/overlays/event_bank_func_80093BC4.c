typedef signed char s8;
typedef struct P { char pad[0x2FC]; int i2FC; char pad300[0x318 - 0x300]; int i318; } P;
typedef struct Ent { char pad[0x10]; int i10; char pad14[0x1C - 0x14]; } Ent;
typedef struct Obj {
    char pad[0x59CC];
    P *p59CC;
    char pad59D0[0x73F4 - 0x59D0];
    int i73F4;
    char pad73F8[0x75A8 - 0x73F8];
    s8 cur;
    char pad75A9[0x75FC - 0x75A9];
    Ent *ents;
} Obj;
typedef unsigned int u32;
extern u32 D_800F2C14;
extern void func_80074C84(Obj *, int);
extern void func_8007620C(Obj *);
static inline u32 rnd(u32 *p, u32 n)
{
    *p = (*p * 16807) & 0x7FFFFFFF;
    return ((*p >> 15) * n) >> 16;
}
void func_80093BC4(Obj *o, int force)
{
    int v = 0;
    P *p;
    int q;
    if (force != 0) {
        p = o->p59CC;
        if (p != 0 && p->i318 != 0) {
            if (p->i2FC == 0) {
                v = o->i73F4;
            }
        } else {
            force = 0;
        }
    }
    if (force == 0) {
        int t;
        t = o->ents[o->cur].i10;
        if (t >= o->i73F4) {
            q = (t - o->i73F4) / 3;
            if (q == 0) {
                if (rnd(&D_800F2C14, 100) < 25) v = o->i73F4;
            } else if (q == 1) {
                if (rnd(&D_800F2C14, 100) < 50) v = o->i73F4;
            } else if (q == 2) {
                if (rnd(&D_800F2C14, 100) < 60) v = o->i73F4;
            } else {
                if (rnd(&D_800F2C14, 100) < 80) v = o->i73F4;
            }
        }
    }
    func_80074C84(o, v);
    func_8007620C(o);
}
