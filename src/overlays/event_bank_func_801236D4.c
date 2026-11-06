typedef struct { float x, y, z; } Vec3;
typedef struct { float m[4][4]; Vec3 pos; } Xform;
typedef struct {
    char pad[0x1368];
    char unk1368[0x1384 - 0x1368];
    char unk1384[0x34D4 - 0x1384];
    int flags;
} Actor;

extern void func_800CA160(void *a, Xform *x, float f, void *b);
extern void func_800AC37C(void *a, void *b);

static __inline__ Xform *xform_identity(Xform *x, float one)
{
    x->pos.x = x->pos.y = x->pos.z = x->m[0][1] = x->m[0][2] = x->m[1][0] =
        x->m[1][2] = x->m[2][0] = x->m[2][1] = 0.0f;
    x->m[0][0] = x->m[1][1] = x->m[2][2] = one;
    return x;
}

static __inline__ void vec3_copy(Vec3 *d, Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static __inline__ void vec3_set(Vec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_801236D4(Actor *a, Xform *x, float f)
{
    Xform local;

    if (x == 0) {
        x = xform_identity(&local, *(float *)0x80081BC0);
        vec3_set(&x->pos, *(float *)0x80081BC4, *(float *)0x80081BC8, *(float *)0x80081BCC);
    }
    func_800CA160(a->unk1384, x, f, a->unk1368);
    func_800AC37C(a->unk1384, a);
    a->flags |= 2;
}
