typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec p; } Mtx;
extern void func_800B3870(Mtx *, u8 *, int);
extern void func_800AD2A8(Mtx *, Vec *, Vec *, int);
static inline void vcpy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
void func_80081E34(u8 *o)
{
    Mtx *m = (Mtx *)(o + 20);
    Vec a = { 21.462385f, 0.0f, 0.0f };
    Vec b;
    *(int *)(o + 4296) = 0;
    func_800B3870(m, o + 4380, 76);
    *(float *)(o + 4264) = *(float *)(o + 4268) = *(float *)(o + 4272) = *(float *)(o + 4276) = *(float *)(o + 4280) = *(float *)(o + 4288) = 0.0f;
    func_800AD2A8(m, &a, &b, 1);
    vcpy((Vec *)(o + 4332), &b);
    a.x = -a.x;
    func_800AD2A8(m, &a, &b, 1);
    vcpy((Vec *)(o + 4344), &b);
}
