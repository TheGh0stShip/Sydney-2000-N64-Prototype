typedef struct { float x, y, z; } Vec;
typedef struct { char pad[64]; Vec pos; } Sub;
typedef struct { char pad[20]; Sub sub; } Obj;
typedef struct {
    int state; int frozen; int v8; int v12; Vec cur;
    char pad0[60 - 28]; int idx; int v64; void *anim; int flip;
} Trk;
extern int func_800AF2D4(void *, float, Vec *, int *, int *);
extern void func_800AE8C0(Trk *, Obj *);
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
static inline void topos(Vec *a, Sub *s) { s->pos.x = a->x; s->pos.y = a->y; s->pos.z = a->z; }
int func_800AE9DC(Trk *t, float dt, Obj *o)
{
    Vec p;
    int r;
    if (t->frozen) dt = 0.0f;
    if (t->state != 4) return 0;
    r = func_800AF2D4(t->anim, dt, &p, &t->idx, &t->v64);
    topos(&p, &o->sub);
    if (t->v12) {
        if (0.0f <= dt) {
            func_800AE8C0(t, o);
        } else {
            t->flip = !t->flip;
            func_800AE8C0(t, o);
            t->flip = !t->flip;
        }
    }
    vcpy(&p, &t->cur);
    return r;
}
