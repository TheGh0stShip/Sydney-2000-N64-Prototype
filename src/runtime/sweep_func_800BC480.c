typedef struct { float x, y, z; } Vec;
typedef struct { Vec a; Vec n; Vec c; int i; } Ray;
typedef struct { char pad[0x18]; int step; } Clock;

extern char D_800F26E0[];
extern Clock D_800F272C;
extern Ray *func_800BE55C(void);
extern void func_800AB2A4(char *q, int step, int kind, int a, int b, Ray *r);

static inline void vcopy(Vec *d, Vec *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void rcopy(Ray *d, Ray *s)
{
    vcopy(&d->n, &s->n);
    d->a.x = s->a.x;
    d->a.y = s->a.y;
    d->a.z = s->a.z;
    vcopy(&d->c, &s->c);
    d->i = s->i;
}

void func_800BC480(int a, int b, Ray *r)
{
    Ray *t;

    t = func_800BE55C();
    rcopy(t, r);
    func_800AB2A4(D_800F26E0, D_800F272C.step, 26, a, b, t);
    if (b) {
        t = func_800BE55C();
        r->n.x = -r->n.x;
        r->n.y = -r->n.y;
        r->n.z = -r->n.z;
        rcopy(t, r);
        func_800AB2A4(D_800F26E0, D_800F272C.step, 26, b, a, t);
    }
}
