typedef struct { float x, y, z; } Vec;
typedef struct { short y; short pad; } YE;
typedef struct { short x; short z; } XZ;
typedef struct { char pad[84]; YE y[81]; XZ xz[81]; } Tile;
typedef struct { int pad; Tile *tiles[1]; } Land;
typedef struct { float x; float pad4; float z; char padc[0x18 - 0xC]; unsigned short tile; char pad1a[0x20 - 0x1A]; unsigned int cell; float y; } Probe;

extern void func_800AD820(Vec *a, Vec *b, Vec *out);
extern void func_800AD6D0(Vec *a, Vec *b);

static inline void vset3(Vec *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
static inline float dot(Vec *a, Vec *b) { return a->x * b->x + a->y * b->y + a->z * b->z; }
static inline void vsub(Vec *o, Vec *a, Vec *b) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }

void func_800E6D4C(Land *l, Probe *q)
{
    Tile *t;
    unsigned int c;
    int n;
    unsigned int row;
    unsigned int col;
    XZ *pa, *pb, *pc;
    YE *ya, *yb, *yc;
    Vec p0;
    Vec p1;
    Vec p2;
    Vec e1;
    Vec e2;
    Vec nrm;
    float d;

    t = l->tiles[q->tile];
    c = q->cell;
    row = c / 16;
    col = (c - row * 16) / 2;
    n = row * 9 + col;
    if (c & 1) {
        pa = &t->xz[n + 1];
        pb = pa + 9;
        pc = pa + 8;
        ya = &t->y[n + 1];
        yb = ya + 9;
        yc = ya + 8;
    } else {
        pa = &t->xz[n];
        pb = pa + 1;
        pc = pa + 9;
        ya = &t->y[n];
        yb = ya + 1;
        yc = ya + 9;
    }
    vset3(&p0, pa->x, ya->y, pa->z);
    vset3(&p1, pb->x, yb->y, pb->z);
    vset3(&p2, pc->x, yc->y, pc->z);
    vsub(&e1, &p0, &p2);
    vsub(&e2, &p1, &p2);
    func_800AD820(&e1, &e2, &nrm);
    func_800AD6D0(&nrm, &nrm);
    d = dot(&nrm, &p0);
    q->y = (0.0f - nrm.x * q->x - nrm.z * q->z + d) / nrm.y;
}
