typedef unsigned short u16;
typedef struct { int a, b, c, d; } B16;
typedef struct { int a, b; } B8;
typedef struct { int v0; u16 v4; char rest[84 - 6]; } Rec;
typedef struct {
    char pad0[212]; unsigned int n; Rec *recs;
    char pad1[224 - 220]; int v224; int v228;
    char pad2[244 - 232]; char self[356 - 244]; int v356;
} Obj;
extern int func_800B794C(Obj *, int, void *, void *, void *, int);
extern void func_800B7FE0(Obj *, int, int);
unsigned int func_800B9BD4(Obj *o, int a, int b, void *c, void *d, int e)
{
    B16 x;
    B8 y;
    unsigned int i;
    unsigned int mask;
    o->v356 = 0;
    mask = func_800B794C(o, a, o->self, c, d, e) != 0;
    for (i = 0; i < o->n; i++) {
        if (o->recs[i].v4 != 0xffff) {
            if (func_800B794C(o, a, &o->recs[i], &y, &x, e)) mask |= 1 << (i + 1);
        }
    }
    o->v228 = 0;
    func_800B7FE0(o, b, o->v224);
    return mask;
}
