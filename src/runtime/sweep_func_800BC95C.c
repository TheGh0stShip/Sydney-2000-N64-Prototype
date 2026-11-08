typedef struct { float x, y, z; } Vec;
typedef struct {
    char pad0[0xC];
    Vec c;
    char pad18[0x28 - 0x18];
    Vec dir;
    char pad34[0x40 - 0x34];
    float len;
} Seg;

int func_800BC95C(int unused, Seg *s, Vec *a, Vec *b)
{
    Vec p1;
    Vec p2;
    Vec d;
    Vec n;
    Vec sc;
    float d1;
    float d2;
    float ta;
    float tb;
    Vec *v;
    float l;

    l = s->len;
    v = &s->dir;
    d.x = v->x; d.y = v->y; d.z = v->z;
    sc.x = d.x * l; sc.y = d.y * l; sc.z = d.z * l;
    v = &s->c;
    p1.x = v->x + sc.x; p1.y = v->y + sc.y; p1.z = v->z + sc.z;
    d1 = d.x * p1.x + d.y * p1.y + d.z * p1.z;
    ta = a->x * d.x + a->y * d.y + a->z * d.z;
    n.x = -d.x; n.y = -d.y; n.z = -d.z;
    p2.x = v->x - sc.x; p2.y = v->y - sc.y; p2.z = v->z - sc.z;
    d2 = n.x * p2.x + n.y * p2.y + n.z * p2.z;
    tb = b->x * n.x + b->y * n.y + b->z * n.z;
    if (ta <= d1) {
        if (ta >= -d2) return 1;
        if (tb > d2) return 0;
    }
    if (tb <= d2) {
        if (tb >= -d1) return 1;
        if (ta > d1) return 0;
    }
    return 1;
}
