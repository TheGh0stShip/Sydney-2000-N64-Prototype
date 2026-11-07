typedef struct { short adj; short pad; void (*fn)(void *, void *); } VEnt;
typedef struct { float x, y, z; } Vec;
typedef struct {
    char p0[0x54];
    Vec pos;
    char p1[0xB4 - 0x60];
    VEnt *vt;
    char p2[0x170 - 0xB8];
    Vec pos2;
    char p3[0x1E8 - 0x17C];
    int j;
    char p4[0x204 - 0x1EC];
    unsigned char c;
} Ent;
typedef struct { char p0[8]; Ent **base; Ent **top; char p1[2]; unsigned short n; } Pool;
typedef struct {
    char p0[0xB8];
    int a184[8];
    int a216[4];
    Ent *list[30];
    Pool pool;
    char p1[0x176 - 0x174];
    unsigned short cnt;
} Obj;

extern int D_800F7250[];
extern int D_800F7240[];
extern void *func_800AAA58(int, void *);
extern void func_800D9360(void *);
extern int func_800BA2D0(int);
extern int func_800140A0(int, int, int);
extern void func_800D9358(Ent *, int);

static inline void vcopy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

Ent *func_800D7BF4(Obj *o, Vec *pos, unsigned char c, unsigned char k, int j)
{
    Ent *e;
    Pool *p;

    e = 0;
    p = &o->pool;
    if (p->top > p->base) {
        p->n--;
        p->top--;
        e = *p->top;
        *p->top = 0;
        func_800D9360(func_800AAA58(528, e));
    }
    if (e != 0) {
        e->vt[2].fn((char *)e + e->vt[2].adj, o);
    }
    o->list[o->cnt++] = e;
    if (o->a184[j] == 0) {
        o->a184[j] = func_800BA2D0(D_800F7250[j]);
    }
    vcopy(&e->pos, pos);
    vcopy(&e->pos2, pos);
    if (o->a216[k] == 0) {
        o->a216[k] = func_800140A0(D_800F7240[k], -1, 1);
    }
    func_800D9358(e, o->a216[k]);
    e->c = c;
    e->j = j;
    return e;
}
