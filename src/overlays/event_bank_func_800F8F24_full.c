typedef struct Obj {
    char pad0[0x2DD];
    unsigned char range;
    char pad2DE[0x344 - 0x2DE];
    float val;
} Obj;

extern unsigned int D_800F13F0;
extern int D_80076F88;

static __inline__ unsigned int rnd(int n)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * n) >> 16;
}

void func_800F8F24(Obj *obj)
{
    unsigned char pick;
    int v;
    double d;
    float f;

    pick = rnd(10);
    v = rnd(obj->range);
    d = v;
    if (v < 0) {
        d += *(double *)0x80078A98;
    }
    f = (float)d / *(float *)0x80078AA0 * *(float *)0x80078AA4;
    if (pick < 5) {
        obj->val = (*(float *)0x80078AA8 - f) * *(float *)0x80078AB0;
    } else {
        obj->val = (f + *(float *)0x80078AAC) * *(float *)0x80078AB0;
    }
    if (D_80076F88 != 0) {
        obj->val = *(float *)0x80078AB4;
    }
}
