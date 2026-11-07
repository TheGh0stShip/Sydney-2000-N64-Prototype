typedef unsigned char u8;
typedef struct { float x, y, z; } Vector3;
typedef struct { float values[16]; Vector3 position; } MotionTransform;
typedef struct { u8 head[20]; MotionTransform transform; u8 pad[368 - 96]; Vector3 v368; u8 pad2[12]; Vector3 v392; } Medal;
typedef struct { u8 pad[1124]; Medal *a[10]; } Scene;
extern Vector3 *runtimeMotionUpVector;
extern void func_800AC9B8(Vector3 *, MotionTransform *, Vector3 *);
extern void func_800AD9E8(Medal *);
extern void func_800B9FA4(Medal *, int, int, float, int, int);
extern void func_800B9E9C(Medal *, int, int, float, int);
extern void func_800AD434(MotionTransform *, float, int);
extern void func_800AD2A8(MotionTransform *, Vector3 *, Vector3 *, int);
static __inline__ void setpos(MotionTransform *t, Vector3 *v) { t->position.x = v->x; t->position.y = v->y; t->position.z = v->z; }
static __inline__ void mident(MotionTransform *m, float one) {
    m->values[9] = 0.0f; m->values[8] = 0.0f; m->values[6] = 0.0f; m->values[4] = 0.0f; m->values[2] = 0.0f; m->values[1] = 0.0f;
    m->position.z = 0.0f; m->position.y = 0.0f; m->position.x = 0.0f;
    m->values[10] = one; m->values[5] = one; m->values[0] = one;
}
static __inline__ void vcopy(Vector3 *d, Vector3 *s) { d->x = s->x; d->y = s->y; d->z = s->z; }
void func_8007217C(Scene *s) {
    MotionTransform m;
    Vector3 b;
    Vector3 a;
    int i;
    float step = 18.0f;
    float one = 1.0f;
    b.x = 262.135986328125f; b.y = 0.0f; b.z = 0.0f;
    a.x = 262.135986328125f; a.y = 0.0f; a.z = 0.0f;
    i = 0;
    while (1) {
        u8 n = i;
        if (n >= 10) break;
        vcopy(&s->a[n]->v368, &a);
        vcopy(&s->a[n]->v392, &s->a[n]->v368);
        func_800AC9B8(&a, &s->a[n]->transform, runtimeMotionUpVector);
        setpos(&s->a[n]->transform, &s->a[n]->v368);
        func_800AD9E8(s->a[n]);
        i++;
        func_800B9FA4(s->a[n], 10, -1, one, 0, 1);
        func_800B9E9C(s->a[n], 10, -1, one, 0);
        mident(&m, one);
        func_800AD434(&m, step * (float)(n + 1) * 0.01745329052209854f, 3);
        func_800AD2A8(&m, &b, &a, 0);
    }
}
