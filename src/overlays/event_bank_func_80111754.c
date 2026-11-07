typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { float m[16]; Vec p; } Mtx;
extern void func_800AD434(Mtx *, float, int);
extern void func_800AD4E0(Mtx *, float, int);
static inline void getpos(Mtx *m, Vec *v)
{
    v->x = m->p.x;
    v->y = m->p.y;
    v->z = m->p.z;
}
static inline void setpos(Mtx *m, Vec *v)
{
    m->p.x = v->x;
    m->p.y = v->y;
    m->p.z = v->z;
}
static inline void rot(Mtx *m, float a, Vec *t)
{
    getpos(m, t);
    m->p.x = m->p.y = m->p.z = m->m[1] = m->m[2] = m->m[4] = m->m[6] = m->m[8] = m->m[9] = 0.0f;
    m->m[0] = m->m[5] = m->m[10] = 1.0f;
    func_800AD434(m, a, 3);
    setpos(m, t);
}
void func_8007CA64(u8 *o, u8 b)
{
    Mtx *m = (Mtx *)(o + 1296);
    Vec t;
    if (!b) {
        rot(m, 1.5707961f, &t);
    } else {
        rot(m, 4.7123885f, &t);
    }
    if (o[1489]) {
        func_800AD4E0((Mtx *)(o + 1296), 3.1415923f, 3);
    }
}
