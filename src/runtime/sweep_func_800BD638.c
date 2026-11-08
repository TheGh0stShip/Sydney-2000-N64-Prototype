typedef struct {
    float x, y, z;
} Vec;

typedef struct {
    Vec dir;
    Vec org;
} Ray;

typedef struct {
    Vec pos;
    char pad[36 - 12];
    int dist;
} Hit;

extern int D_800F2744;

float func_800AD6D0(Vec *src, Vec *dst);
int func_800BD884(Vec *pt, void *poly, Vec *a, Vec *n);

int func_800BD638(Ray *r, Vec *dir, Vec *p, void *poly, Vec *n, Hit *out)
{
    Vec h;
    Vec dd;
    Vec v;
    float d, len, dn, t;
    Vec *o;
    Vec *hp;

    d = -(n->x * p->x + n->y * p->y + n->z * p->z);
    v.x = dir->x;
    v.y = dir->y;
    v.z = dir->z;
    len = func_800AD6D0(dir, &v);
    if (len == 0.0f) return 0;
    dn = n->x * v.x + n->y * v.y + n->z * v.z;
    if (0.0f <= dn) return 0;
    o = &r->org;
    t = -((d + (n->x * o->x + n->y * o->y + n->z * o->z)) / dn);
    if (t <= 0.0f) return 0;
    hp = &h;
    hp->x = v.x * t;
    hp->y = v.y * t;
    hp->z = v.z * t;
    hp->x += o->x;
    hp->y += o->y;
    hp->z += o->z;
    if (func_800BD884(hp, poly, p, n) != -1) {
        dd.x = hp->x - o->x;
        dd.y = hp->y - o->y;
        dd.z = hp->z - o->z;
        out->dist = D_800F2744 + (int)(func_800AD6D0(&dd, &dd) / len * 256.0f);
        out->pos = h;
        return 1;
    }
    return 0;
}
