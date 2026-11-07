typedef struct { short offset; short pad; void (*fn)(void *, ...); } VEntry;
typedef struct { char pad0[8]; VEntry release; VEntry pad1; VEntry reset; char pad2[40]; VEntry stop; } VTable;
typedef struct { char pad0[180]; VTable *vt; char pad1[12]; int handle; } Unit;
typedef struct { void *heap; void *a; void *b; Unit **cur; unsigned short cap; unsigned short n; } Pool;
typedef struct { char pad0[692]; Pool pool; Unit *units[4]; char pad1[124]; int flags; } Obj;
extern char D_800F26E0[];
extern void func_800AACB0(void *, Unit *, int);
extern void func_800AA658(void *, void **);
extern void func_8001A248(int *);
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
void func_800C1C0C(Obj *o)
{
    unsigned char i;
    i = 0;
    while (1) {
        Unit *u;
        Pool *p;
        if (i >= 2) break;
        u = o->units[i];
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        func_8001A248(&o->units[i]->handle);
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        u->vt->stop.fn((char *)u + u->vt->stop.offset);
        p = &o->pool;
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        func_800AACB0(D_800F26E0, u, 0);
        pool_push(p, u);
        o->units[i] = 0;
        i++;
    }
    pool_free(&o->pool);
    o->flags &= ~2;
}
