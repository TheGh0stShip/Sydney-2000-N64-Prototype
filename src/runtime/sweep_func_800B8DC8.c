typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec pos; } Xf;
typedef struct {
    char pad0[20]; Xf xf;
    char pad1[368 - 96]; Vec v368; Vec v380; Vec v392;
} Obj;
extern int func_800AE9DC(void *, float, Obj *);
extern void func_800AD2A8(Xf *, Vec *, Vec *, int);
extern void func_800B9480(Obj *);
static inline void vacc(Vec *a, Vec *r) { r->x += a->x; r->y += a->y; r->z += a->z; }
static inline void vadd(Vec *a, Vec *b, Vec *r) { r->x = a->x + b->x; r->y = a->y + b->y; r->z = a->z + b->z; }
static inline void vsub(Vec *a, Vec *b, Vec *r) { r->x = a->x - b->x; r->y = a->y - b->y; r->z = a->z - b->z; }
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
int func_800B8DC8(Obj *o, void *ctx, Vec *pos, int *flag, Vec *d)
{
    Vec t;
    Vec c;
    Vec a;
    int r;
    if (*flag) {
        vacc(d, &o->v368);
        vacc(d, &o->v380);
    }
    vadd(pos, &o->v368, &a);
    vsub(&a, &o->v392, &t);
    vcpy(&a, &o->v392);
    r = func_800AE9DC(ctx, t.z, o);
    a.x = pos->x + o->v380.x;
    a.y = pos->y + o->v380.y;
    a.z = 0.0f;
    func_800AD2A8(&o->xf, &a, &c, 0);
    vadd(&c, &o->xf.pos, &o->xf.pos);
    func_800B9480(o);
    return r;
}
