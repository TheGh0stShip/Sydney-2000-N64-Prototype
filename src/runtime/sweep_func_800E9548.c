typedef struct { char pad[192]; int flags; char pad2[36]; } Rec;
typedef struct {
    char pad[24632];
    Rec recs[14];
    char pad2[216];
    char a[220];
    char b[220];
    int idx;
} Obj;
extern void func_800B2158(void *, int);
static inline void off(Rec *r, void *a)
{
    r->flags &= ~4;
    func_800B2158(a, 1);
}
void func_800E9548(Obj *o, int flags)
{
    if (o->idx != -1) {
        if (flags & 1) {
            off(o->recs + o->idx, o->a);
        }
        if (flags & 2) {
            off(o->recs + o->idx + 1, o->b);
        }
    }
}
