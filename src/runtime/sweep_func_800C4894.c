typedef struct { short offset; short pad; void (*fn)(void *, ...); } VEntry;
typedef struct { char pad0[8]; VEntry release; VEntry pad1; VEntry reset; char pad2[40]; VEntry stop; } VTable;
typedef struct { char pad0[180]; VTable *vt; char pad1[12]; int handle; } Unit;
typedef struct { void *heap; void *a; void *b; Unit **cur; unsigned short cap; unsigned short n; } Pool;
typedef struct { char pad0[4]; int mode; } Cfg;
typedef struct {
    char pad0[220];
    Cfg *cfg;
    Pool pool;
    Unit *units[4];
    Unit sub;
    char pad1[792 - 260 - sizeof(Unit)];
    Unit *extra;
} Obj;
extern char D_800F26E0[];
extern char D_800F2758[];
extern int D_800F40F8;
extern void func_800B35F0(Unit *);
extern void func_800AACB0(void *, Unit *, int);
extern void func_800AA658(void *, void *);
extern void func_8001A248(int *);
extern void func_800C2160(Obj *);
extern void func_800C3764(Obj *);
static inline void pool_push(Pool *p, Unit *u)
{
    if (p->n < p->cap) {
        u->vt->release.fn((char *)u + u->vt->release.offset, 2);
        *p->cur = u;
        p->cur++;
        p->n++;
    }
}
static inline void pool_free(Pool *p)
{
    void *heap = p->heap;
    if (heap) {
        p->heap = 0;
        if (p->a) func_800AA658(heap, &p->a);
        if (p->b) func_800AA658(heap, &p->b);
        p->cap = 0;
        p->n = 0;
        p->cur = 0;
        p->heap = 0;
    }
}
void func_800C4894(Obj *o)
{
    unsigned char i;
    unsigned int n;
    Unit *u;
    Unit *v;
    Unit *s;

    n = 2;
    if (o->cfg->mode == 4) {
        n = 4;
    }
    i = 0;
    while (1) {
        Pool *p;
        if (i >= n) break;
        u = o->units[i];
        func_800B35F0(u);
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        v = o->units[i];
        p = &o->pool;
        v->vt->reset.fn((char *)v + v->vt->reset.offset);
        func_800AACB0(D_800F26E0, v, 0);
        pool_push(p, v);
        i++;
    }
    pool_free(&o->pool);
    func_800C2160(o);
    if (D_800F40F8 != 0) {
        func_8001A248(&D_800F40F8);
        D_800F40F8 = 0;
    }
    s = &o->sub;
    o->sub.vt->stop.fn((char *)s + o->sub.vt->stop.offset);
    o->sub.vt->reset.fn((char *)s + o->sub.vt->reset.offset);
    if (o->extra != 0) {
        o->extra->vt->reset.fn((char *)o->extra + o->extra->vt->reset.offset);
        o->extra->vt->stop.fn((char *)o->extra + o->extra->vt->stop.offset);
        func_800AA658(D_800F2758, &o->extra);
        o->extra = 0;
    }
    func_800C3764(o);
}
