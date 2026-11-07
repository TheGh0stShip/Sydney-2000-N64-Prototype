typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec p; } Mtx;
extern void func_800AD58C(Mtx *, float, float, float);
extern void func_800AD2A8(Mtx *, Vec *, Vec *, int);
static inline void vadd(Vec *d, Vec *a, Vec *b)
{
    d->x = a->x + b->x;
    d->y = a->y + b->y;
    d->z = a->z + b->z;
}
void func_80080E20(u8 *o, float y)
{
    Mtx *m = (Mtx *)(o + 20);
    Vec *p;
    Vec t;
    func_800AD58C(m, 0.0f, y, 0.0f);
    p = (Vec *)(o + 84);
    p->x = 0.0f;
    p->y = 0.0f;
    p->z = 0.0f;
    if (0.0f <= y) {
        func_800AD2A8(m, (Vec *)(o + 212), &t, 0);
        vadd(p, &t, (Vec *)(o + 224));
    } else {
        func_800AD2A8(m, (Vec *)(o + 236), &t, 0);
        vadd(p, &t, (Vec *)(o + 248));
    }
}
