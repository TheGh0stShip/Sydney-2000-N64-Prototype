typedef struct { float x, y, z; } Vec3;
typedef struct {
    short p0; short kind; Vec3 pos;
    char p1[36 - 16]; float sx; float sy; short h44; short h46; short h48; short p2;
    unsigned int c0; unsigned int c1;
} Spr;
typedef struct {
    char p0[192]; int b[4]; char p1[224 - 208]; int a[8];
    char p2[260 - 256]; int id; char p3[448 - 264]; char pool[4];
} Obj;
extern Spr *func_800EA308(void *, int, int);

void func_800EBC08(Obj *o, Vec3 *v)
{
    Spr *p;
    unsigned int i;
    int *q;

    p = func_800EA308(o->pool, 897, o->id);
    p->kind = 45;
    p->h46 = 6;
    p->h48 = 682;
    p->h44 = 0;
    { float x = v->x, y = v->y, z = v->z; p->pos.x = x; p->pos.y = y; p->pos.z = z; }
    p->c0 = 0xB2FFFFFF;
    p->c1 = 0x00FFFFFF;
    p->sy = 0.010922333f;
    p->sx = 1.0f;
    i = 0; q = o->a;
    while (1) {
        if (!(i < 8)) break;
        p = func_800EA308(o->pool, 898, *q);
        q++;
        p->kind = 45;
        p->h46 = 22;
        p->h48 = 186;
        p->h44 = 0;
        { float x = v->x, y = v->y, z = v->z; p->pos.x = x; p->pos.y = y; p->pos.z = z; }
        p->c0 = 0xB2FFFFFF;
        p->c1 = 0x00FFFFFF;
        p->sy = 0.030036418f;
        p->sx = 0.2f;
        i++;
    }
    i = 0;
    q = o->b;
    while (1) {
        if (!(i < 4)) break;
        p = func_800EA308(o->pool, 898, q[i]);
        p->kind = 135;
        p->h46 = 36;
        p->h48 = 113;
        p->h44 = 0;
        { float x = v->x, y = v->y, z = v->z; p->pos.x = x; p->pos.y = y; p->pos.z = z; }
        p->c0 = 0xB2FFFFFF;
        p->c1 = 0x00FFFFFF;
        p->sy = 0.008191750f;
        p->sx = 0.3f;
        i++;
    }
}
