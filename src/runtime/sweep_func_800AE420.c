typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec pos; } Xf;
typedef struct { int flags; Vec v; char pad[92 - 16]; float f92; } Src;
typedef struct {
    char pad0[20]; Xf xf;
    char pad1[160 - 96]; Vec v160;
    char pad2[200 - 172]; int v200;
    char pad3[244 - 204]; float f244;
} Obj;
extern void func_800AD58C(Xf *, float, float, float);
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
void func_800AE420(Obj *o, Src *s)
{
    Xf *x = &o->xf;
    o->v160.x = o->v160.y = o->v160.z = 0.0f;
    func_800AD58C(x, o->v160.x, o->v160.y, o->v160.z);
    if (s == 0) {
        x->pos.x = 0.0f;
        x->pos.y = 0.0f;
        x->pos.z = -98.30099487f;
    } else {
        Vec *v = &s->v;
        x->pos.x = v->x;
        x->pos.y = v->y;
        x->pos.z = v->z;
        if (s->flags & 0x200) o->f244 = s->f92;
    }
    o->v200 = 0;
}
