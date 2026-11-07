typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct VT { s16 off; s16 pad; void (*fn)(); } VT;
typedef struct Pool { u8 pad[12]; u8 **wp; u16 max; u16 cnt; } Pool;
typedef struct Gx { u8 pad[72]; struct { s32 x; u8 r[56]; } pl[8]; } Gx;
typedef struct Obj {
    u8 pad[20168];
    Pool a;
    Pool b;
    u8 *tbl[8];
    u8 *grid[8][10];
} Obj;

extern u8 D_800F26E0[];
extern u8 *D_800FC270;

extern void func_800AACB0(u8 *a, u8 *o, s32 b);
extern void func_800172CC(s32 a, s32 b);

#define VTB(o) (*(VT **)((o) + 180))
#define CALL(o, k) VTB(o)[k].fn((o) + VTB(o)[k].off)
#define CALLA(o, k, a) VTB(o)[k].fn((o) + VTB(o)[k].off, a)
#define OB ((Obj *)p)

static inline void rel(Pool *pl, u8 *o)
{
    CALL(o, 3);
    func_800AACB0(D_800F26E0, o, 0);
    if (pl->cnt < pl->max) {
        CALLA(o, 1, 2);
        *pl->wp = o;
        pl->wp++;
        pl->cnt++;
    }
}

void func_800E084C(u8 *p, u8 idx)
{
    u8 *o;
    u8 *c;
    u8 k;
    u8 i;
    Pool *pl;

    o = OB->tbl[idx];
    if (o == 0) {
        return;
    }
    func_800AACB0(D_800F26E0, o, 0);
    c = o + 1004;
    if (c != 0) {
        CALL(c, 3);
        CALL(c, 9);
        if (*(s32 *)(c + 196) != 0) {
            func_800172CC(*(s32 *)(c + 196), 1);
        }
    }
    c = o + 792;
    if (c != 0) {
        CALL(c, 3);
        CALL(c, 9);
    }
    k = o[424];
    if (k != 8) {
        ((Gx *)D_800FC270)->pl[k].x = 0;
    }
    rel(&OB->a, OB->tbl[idx]);
    OB->tbl[idx] = 0;
    i = 0;
    while (1) {
        if (!(i < 10)) break;
        rel(&OB->b, OB->grid[idx][i]);
        OB->grid[idx][i] = 0;
        i++;
    }
}
