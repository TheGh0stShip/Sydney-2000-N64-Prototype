typedef struct { float x, y, z; } Vec;
typedef struct { short d; short pad; void (*f)(); } VEnt;
typedef struct { char pad[16]; VEnt a; VEnt b; } VTab;
typedef struct {
    char pad0[84]; Vec v84;
    char pad1[180 - 96]; VTab *vt;
    char pad2[784 - 184]; Vec v784;
    char pad3[924 - 796]; Vec v924;
    char pad4[1160 - 936]; int v1160;
    char pad5[2624 - 1164]; Vec v2624;
} Obj;
static inline void vcpy(Vec *a, Vec *r) { r->x = a->x; r->y = a->y; r->z = a->z; }
static inline void vzero(Vec *r) { r->x = 0.0f; r->y = 0.0f; r->z = 0.0f; }
static inline void vscl(Vec *a, float k, Vec *r) { r->x = a->x * k; r->y = a->y * k; r->z = a->z * k; }
static inline void vadd(Vec *a, Vec *b, Vec *r) { r->x = a->x + b->x; r->y = a->y + b->y; r->z = a->z + b->z; }
void func_8009F660(Obj *o, int arg, Vec *p, Vec *v)
{
    Vec t;
    vcpy(p, &o->v784);
    vzero(&o->v924);
    vscl(v, 31.620155f, &t);
    vadd(p, &t, &o->v84);
    vzero(&o->v2624);
    o->vt->b.f((char *)o + o->vt->b.d);
    o->vt->a.f((char *)o + o->vt->a.d, arg);
    o->v1160 = 0;
}
