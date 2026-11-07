typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec pos; } Xf;
typedef struct { char pad[20]; Xf xf; } Obj;
typedef struct { char pad[16]; int v16; } Anim;
typedef struct {
    int state; int frozen; int v8; int v12; Vec cur;
    char pad0[56 - 28]; int keepy; int idx; int v64; Anim *anim; int flip;
} Trk;
extern Vec *runtimeMotionUpVector;
extern void func_800AF0E4(Anim *, int, int, Vec *);
extern float func_800AD6D0(Vec *, Vec *);
extern void func_800AC9B8(Vec *, Xf *, Vec *);
static inline void getpos(Xf *s, Vec *r) { r->x = s->pos.x; r->y = s->pos.y; r->z = s->pos.z; }
static inline void vsub(Vec *a, Vec *b, Vec *r) { r->x = a->x - b->x; r->y = a->y - b->y; r->z = a->z - b->z; }
void func_800AE8C0(Trk *t, Obj *o)
{
    Vec v;
    Vec c;
    if (t->state == 4) {
        func_800AF0E4(t->anim, t->anim->v16, t->idx, &v);
        if (t->keepy == 0) v.y = 0.0f;
    } else {
        getpos(&o->xf, &c);
        if (t->flip) vsub(&t->cur, &c, &v);
        else vsub(&c, &t->cur, &v);
        if (t->keepy == 0) v.y = 0.0f;
        if (!(0.1f < func_800AD6D0(&v, &v))) return;
    }
    func_800AC9B8(&v, &o->xf, runtimeMotionUpVector);
}
