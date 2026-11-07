typedef struct { float x, y, z; } Vec;
typedef struct { Vec p; char pad[40 - 12]; } Hit;
typedef struct { char pad[0x24]; Vec org; } Area;
typedef struct { char pad[8]; void *root; } Tree;
typedef struct { char pad[0xB8]; int nx; int nz; char padc0[0xF0 - 0xC0]; int flags; char padf4[0x100 - 0xF4]; short ix; short iz; } Map;
typedef struct {
    char pad0[0x54];
    Vec pos;
    char pad60[0xD0 - 0x60];
    Tree *tree;
    char padd4[0x3B4 - 0xD4];
    unsigned char on;
} Ent;
typedef struct {
    char pad0[0x1C8];
    float w;
    char pad1cc[0x1DC - 0x1CC];
    float h;
    char pad1e0[0x1E4 - 0x1E0];
    Vec home;
} Hud;

extern Area D_800F1AA4;
extern char D_800F1AD4[];
extern Vec D_80085124;
extern int func_800BE28C(void *root, Area *a, int n, char *tag, Hit *h);
extern void func_8009FD40(Map *m, int f);

static inline void vcopy(Vec *a, Vec *b) { a->x = b->x; a->y = b->y; a->z = b->z; }
static inline void vzero(Vec *a) { a->x = 0.0f; a->y = 0.0f; a->z = 0.0f; }
static inline void vsub(Vec *o, Vec *a, Vec *b) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }

void func_800A294C(Hud *hud, Ent *e)
{
    Hit hit;
    Vec d;
    Vec cp;
    Map *m;
    int ix;
    int iz;
    int nx;
    int nz;

    if (func_800BE28C(e->tree->root, &D_800F1AA4, 4, D_800F1AD4, &hit) == 0) {
        return;
    }
    if (e->on == 0) {
        return;
    }
    m = (Map *)((char *)hud + 0xF0);
    cp = D_80085124;
    nx = m->nx;
    nz = m->nz;
    vsub(&d, &e->pos, &D_800F1AA4.org);
    ix = d.x / hud->w * (float)(nx - 1);
    iz = d.z / hud->h * (float)(nz - 1);
    iz++;
    if (ix <= 0) ix = 1;
    if (ix > 14) ix = 14;
    if (iz <= 0) iz = 1;
    if (iz > 15) iz = 15;
    vcopy(&hud->home, &cp);
    m->flags |= 3;
    m->ix = ix;
    m->iz = iz - 1;
    func_8009FD40(m, 256);
    m->flags |= 2;
    vzero(&hud->home);
    m->iz = -1;
    m->ix = -1;
    cp.y = -(cp.y + cp.y);
    vcopy(&hud->home, &cp);
    m->flags |= 3;
    m->ix = ix;
    m->iz = iz;
}
