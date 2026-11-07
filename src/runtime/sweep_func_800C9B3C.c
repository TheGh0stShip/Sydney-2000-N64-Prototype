typedef struct { short offset; short pad; void (*fn)(void *, ...); } VEntry;
typedef struct { char pad0[8]; VEntry release; VEntry pad1; VEntry reset; char pad2[40]; VEntry stop; } VTable;
typedef struct { char pad0[180]; VTable *vt; } Unit;
typedef struct { void *heap; void *a; void *b; Unit **cur; unsigned short cap; unsigned short n; } Pool;
typedef struct { char pad0[180]; VTable *vt; Pool pool; Unit *units[93]; int x576; int x580; char pad9; unsigned char count; unsigned char keep; } Obj;
extern char D_800F26E0[];
extern void func_800AACB0(void *, Unit *, int);
extern void func_800AA658(void *, void **);
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
void func_800C9B3C(Obj *o)
{
    unsigned char i;
    i = 0;
    while (1) {
        Unit *u;
        Pool *p;
        if (i >= o->count) break;
        {
            Unit *t = o->units[i];
            t->vt->stop.fn((char *)t + t->vt->stop.offset);
        }
        u = o->units[i];
        p = &o->pool;
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        func_800AACB0(D_800F26E0, u, 0);
        pool_push(p, u);
        i++;
    }
    pool_free(&o->pool);
    o->x576 = 0;
    o->x580 = 0;
    if (!o->keep) o->vt->reset.fn((char *)o + o->vt->reset.offset);
}
