typedef struct { short offset; short pad; void (*fn)(void *, ...); } VEntry;
typedef struct { char pad0[8]; VEntry release; VEntry pad1; VEntry reset; } VTable;
typedef struct { char pad0[180]; VTable *vt; } Unit;
typedef struct { void *heap; void *a; void *b; Unit **cur; unsigned short cap; unsigned short n; } Pool;

typedef struct {
    char pad0[192];
    Pool pool;
    Pool pool2;
    Unit *units[24];
    Unit *units2[24];
    int w424;
    void *buf;
    char o432;
} Obj;

extern char D_800F26E0[];
extern char D_800F2758[];
extern char D_800FFD30[];
extern void *D_801000B4;
extern void *D_801000BC;
extern void func_800AC308(Obj *o);
extern void func_800EA4B0(Obj *o);
extern void func_800EA5FC(void *p);
extern void func_80006A18(void *p);
extern void func_800AA658(void *heap, void **slot);
extern void func_800EF964(Unit *u);
extern void func_800EF95C(Unit *u);
extern void func_800EF8AC(Unit *u);
extern void func_800EF8A4(Unit *u);
extern void func_800AACB0(void *list, Unit *u, int flag);

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

void func_800F01A8(Obj *o)
{
    unsigned int i;
    Unit *u;
    Pool *p;

    func_800AC308(o);
    func_800EA4B0(o);
    func_800EA5FC(D_800FFD30);
    func_80006A18(&o->o432);
    func_800AA658(D_800F2758, &D_801000B4);
    func_800AA658(D_800F2758, &D_801000BC);
    i = 0;
    while (1) {
        if (i >= 24) break;
        func_800EF964(o->units[i]);
        p = &o->pool;
        func_800EF95C(o->units[i]);
        u = o->units[i];
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        func_800AACB0(D_800F26E0, u, 0);
        pool_push(p, u);
        i++;
    }
    i = 0;
    while (1) {
        if (i >= 24) break;
        func_800EF8AC(o->units2[i]);
        p = &o->pool2;
        func_800EF8A4(o->units2[i]);
        u = o->units2[i];
        u->vt->reset.fn((char *)u + u->vt->reset.offset);
        func_800AACB0(D_800F26E0, u, 0);
        pool_push(p, u);
        i++;
    }
    pool_free(&o->pool);
    pool_free(&o->pool2);
    func_800AA658(D_800F2758, &o->buf);
    o->buf = 0;
    o->w424 = 0;
}
