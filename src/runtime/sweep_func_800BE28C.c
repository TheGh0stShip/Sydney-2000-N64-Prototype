typedef struct { float x, y, z; } Vec;
typedef struct { char pad[12]; Vec n; char pad1[40 - 24]; float lim; } Plane;
typedef struct { Vec pos; char pad[36 - 12]; int time; } Hit;
extern int runtimePropertyClock;
extern int func_800BD884(Vec *, void *, Vec *);
static inline float dot(Vec *a, Vec *b) { return a->x * b->x + a->y * b->y + a->z * b->z; }
static inline void vscl(Vec *a, float k, Vec *r) { r->x = a->x * k; r->y = a->y * k; r->z = a->z * k; }
static inline void vadd(Vec *a, Vec *b, Vec *r) { r->x = a->x + b->x; r->y = a->y + b->y; r->z = a->z + b->z; }
int func_800BE28C(Plane *p, Vec *v, void *arg, Vec *dir, Hit *out)
{
    Vec t;
    float d = -dot(dir, v) + dot(dir, &p->n);
    if (p->lim <= d) return 0;
    vscl(dir, -d, &t);
    vadd(&p->n, &t, &t);
    if (func_800BD884(&t, arg, v) != -1) {
        out->time = runtimePropertyClock;
        out->pos = t;
        return 1;
    }
    return 0;
}
