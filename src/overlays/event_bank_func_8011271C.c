typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec p; } Mtx;
typedef struct { float a; int b; int c; } Trip;
extern void func_8007C914(u8 *, int);
extern void func_8007CA64(u8 *, u8);
static inline void getpos(Mtx *m, Vec *v)
{
    v->x = m->p.x;
    v->y = m->p.y;
    v->z = m->p.z;
}
void func_8007DA2C(u8 *o, float y)
{
    float v;
    Trip *q;
    Mtx *m;
    func_8007C914(o, 0);
    func_8007CA64(o, 0);
    v = (8.74f - o[733] * 2.49f) * 32.767f;
    *(int *)(o + 1492) = 0;
    o[1488] = 1;
    q = (Trip *)(o + 1260);
    *(float *)(o + 1496) = 255.0f;
    *(float *)(o + 84) = -1769.418f;
    *(float *)(o + 88) = y;
    q->a = 0.1441748f;
    *(float *)(o + 92) = v;
    *(float *)(o + 812) = v;
    q->b = 0;
    q->c = 0;
    m = (Mtx *)(o + 20);
    getpos(m, (Vec *)(o + 368));
    getpos(m, (Vec *)(o + 392));
}
