typedef struct { float x, y, z; } Vec;
typedef struct { Vec p; Vec dir; } Ear;
typedef struct { char pad[116]; Ear ear[1]; } Obj;
extern char D_800F1AE0[];
extern float func_800AD6D0(Vec *, Vec *);
extern double func_80038550(double);
extern int func_8001D4B8(void *, int, int, int);
extern void func_8001D640(void *, int, int);
static inline void vsub(Vec *a, Vec *b, Vec *r) { r->x = a->x - b->x; r->y = a->y - b->y; r->z = a->z - b->z; }
static inline float vdot(Vec *a, Vec *b) { return a->x * b->x + a->y * b->y + a->z * b->z; }
int func_800A2D00(Obj *o, int snd, Vec *pos, float range, int n, int idx)
{
    Ear *e;
    Vec t;
    float dist;
    float dot;
    float l, r;
    int h;
    if (range == 0.0f) return -1;
    e = &o->ear[idx];
    vsub(pos, &e->p, &t);
    dist = func_800AD6D0(&t, &t);
    if (range != 1.0f) dist /= range;
    if (500.0f < dist) {
        l = r = 0.0f;
    } else {
        dot = vdot(&t, &e->dir);
        l = (0.8f - dot) * (float)(n * 4);
        r = (dot + 0.8f) * (float)(n * 4);
        l = func_80038550(l);
        r = func_80038550(r);
        if (dist < 10.0f) dist = 10.0f;
        if (l <= 0.0f) l = 0.0f;
        else l = l / (dist * 0.5f);
        if (r <= 0.0f) r = 0.0f;
        else r = r / (dist * 0.5f);
        if (32767.0f < l) l = 32767.0f;
        if (32767.0f < r) r = 32767.0f;
    }
    h = func_8001D4B8(D_800F1AE0, snd, 0, 1);
    func_8001D640(D_800F1AE0, h, (l + r) * 0.5f);
    return h;
}
