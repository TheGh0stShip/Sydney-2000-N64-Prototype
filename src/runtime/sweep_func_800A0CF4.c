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
    char padd4[0x1AA - 0xD4];
    unsigned char state;
    char pad1ab[0x2DC - 0x1AB];
    unsigned char snd;
    char pad2dd[0x113C - 0x2DD];
    int ready;
    int fresh;
} Ent;
typedef struct {
    char pad0[0xEC];
    int fec;
    char padf0[0x1CC - 0xF0];
    float w;
    char pad1d0[0x1E0 - 0x1D0];
    float h;
    char pad1e4[0x1E8 - 0x1E4];
    Vec home;
} Hud;

extern Area D_800F1A00;
extern char D_800F1A30[];
extern float D_800F19D8;
extern char D_800445F0[];
extern int func_800BE28C(void *root, Area *a, int n, char *tag, Hit *h);
extern void func_80037F30(void *p, int v, int n);
extern void func_800084C0(char *bank, int id, float vol);

static inline void vcopy(Vec *a, Vec *b) { a->x = b->x; a->y = b->y; a->z = b->z; }
static inline void vsub(Vec *o, Vec *a, Vec *b) { o->x = a->x - b->x; o->y = a->y - b->y; o->z = a->z - b->z; }

void func_800A0CF4(Hud *hud, Ent *e)
{
    Hit hit;
    Vec d;
    Vec cp;
    Vec tmp;
    Map *m;
    int ix;
    int iz;
    int nx;
    int nz;

    if (func_800BE28C(e->tree->root, &D_800F1A00, 4, D_800F1A30, &hit) == 0) {
        return;
    }
    if (e->ready == 0) {
        return;
    }
    func_80037F30(&tmp, 0, 12);
    tmp.y = D_800F19D8;
    cp = tmp;
    m = (Map *)((char *)hud + 0xF4);
    nx = m->nx;
    nz = m->nz;
    vcopy(&e->pos, &hit.p);
    vsub(&d, &e->pos, &D_800F1A00.org);
    ix = d.x / hud->w * (float)(nx - 1);
    iz = d.z / hud->h * (float)(nz - 1);
    if (ix <= 0) ix = 1;
    if (ix > 16) ix = 16;
    if (iz <= 0) iz = 1;
    if (iz > 7) iz = 7;
    hud->fec = 0;
    vcopy(&hud->home, &cp);
    m->flags |= 3;
    m->ix = ix;
    m->iz = iz;
    if (e->fresh != 0) {
        if (e->state == 1) {
            func_800084C0(D_800445F0, e->snd, 0.7f);
        }
        e->fresh = 0;
    }
}
