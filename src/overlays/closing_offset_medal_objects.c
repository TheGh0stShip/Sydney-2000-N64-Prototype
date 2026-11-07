typedef unsigned char u8;
typedef struct { float x, y, z; } Vec;
typedef struct { char pad[40]; short off; short pad2; void (*fn)(void *, int, void *); } VT;
typedef struct { char pad[180]; VT *vt; } Obj;
typedef struct { char pad[16]; Vec pos; } Xf;
typedef struct { char pad[84]; Vec vel; } Body;
typedef struct { char pad[1124]; Obj *a[10]; Body *b[10]; } Scene;
extern void func_800AC5CC(void *, void *, void *, int);
extern void func_800AD9E8(Body *);
static __inline__ void vscale(Vec *o, Xf *in, float k) { o->x = in->pos.x; o->y = in->pos.y; o->z = in->pos.z; o->x = o->x * k; o->y = o->y * k; o->z = o->z * k; }
static __inline__ void vadd(Vec *d, Vec *s) { d->x = s->x + d->x; d->y = s->y + d->y; d->z = s->z + d->z; }
void func_80071AB0(Scene *s) {
    int i;
    char buf[80];
    Vec v;
    float k = 45.873798f;
    i = 0;
    while (1) {
        u8 n = i;
        Obj *a;
        if (n >= 10) break;
        a = s->a[n];
        a->vt->fn((char *)a + a->vt->off, 17, buf);
        func_800AC5CC(buf, (char *)s->a[n] + 20, (char *)s->b[n] + 20, 1);
        vscale(&v, (Xf *)((char *)s->b[n] + 20), k);
        vadd(&s->b[n]->vel, &v);
        func_800AD9E8(s->b[n]);
        i++;
    }
}
