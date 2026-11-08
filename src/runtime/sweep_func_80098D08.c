typedef struct { void *heap; void *a; void *b; void **cur; unsigned short cap; unsigned short n; } Pool;
typedef struct { char b[212]; } Blk212;

typedef struct {
    Pool p0;
    Pool p20;
    Pool p40;
    Pool p60;
    Pool p80;
    Pool p100;
    Pool p120;
    Blk212 u140;
    Blk212 u352;
    Blk212 u564;
    Blk212 u776;
    Blk212 u988;
    Blk212 u1200;
    Blk212 u1412;
    int h1624[8];
    int h1656;
    int h1660;
    int h1664;
    int h1668;
    int h1672;
    int h1676;
    char pad1680[2564 - 1680];
    char u2564;
} Obj;

extern void func_80099FE4(Obj *o);
extern void func_80099728(Obj *o);
extern void func_800AC334(void *p);
extern void func_800CC47C(void *p);
extern void func_8001A248(int *p);
extern void func_800CE594(void);
extern void func_800AA658(void *heap, void **slot);

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

void func_80098D08(Obj *o)
{
    unsigned char i;

    func_80099FE4(o);
    func_80099728(o);
    func_800AC334(&o->u2564);
    func_800CC47C(&o->u2564);
    func_800AC334(&o->u564);
    func_800AC334(&o->u352);
    func_800AC334(&o->u140);
    func_800AC334(&o->u1412);
    func_800AC334(&o->u1200);
    func_800AC334(&o->u988);
    func_800AC334(&o->u776);
    if (o->h1668) {
        func_8001A248(&o->h1668);
        o->h1668 = 0;
    }
    if (o->h1672) {
        func_8001A248(&o->h1672);
        o->h1672 = 0;
    }
    if (o->h1676) {
        func_8001A248(&o->h1676);
        o->h1676 = 0;
    }
    if (o->h1660) {
        func_8001A248(&o->h1660);
        o->h1660 = 0;
    }
    if (o->h1664) {
        func_8001A248(&o->h1664);
        o->h1664 = 0;
    }
    if (o->h1656) {
        func_8001A248(&o->h1656);
        o->h1656 = 0;
    }
    for (i = 0; i < 8; i++) {
        if (o->h1624[i]) {
            func_8001A248(&o->h1624[i]);
            o->h1624[i] = 0;
        }
    }
    func_800CE594();
    pool_free(&o->p120);
    pool_free(&o->p100);
    pool_free(&o->p80);
    pool_free(&o->p60);
    pool_free(&o->p40);
    pool_free(&o->p20);
    pool_free(&o->p0);
}
