typedef struct { short adj; short pad; void (*fn)(void *, void *); } VEnt;
typedef struct {
    char p0[0xB0];
    unsigned char b176;
    char p1[0xB4 - 0xB1];
    VEnt *vt;
} Ent;
typedef struct {
    char p0[0x688];
    char a1672[0x74C - 0x688];
    char a1868[0xB80 - 0x74C];
    Ent e;
    char p1[0xC5E - 0xB80 - sizeof(Ent)];
    short h3166;
} Obj;
typedef struct { char p0[0xD8]; int sh; } Cfg;

extern char D_80089620[];
extern Cfg D_800F4D00;
extern char D_800F4860[];
extern void func_800CB204(Obj *, void *, float, float, float, float, char *, int, int);
extern short func_8000EB20(char *);
extern void func_8001A3B8(void *, int, int, float);
extern void func_800ADC54(void *, int);
extern void func_800B360C(void *, void *);

void func_800CB5D8(Obj *o)
{
    Ent *e;
    Cfg *c;

    func_800CB204(o, o->a1672, 479.0f, 14.0f, 120.0f, 16.0f, D_80089620, 3, 1);
    o->h3166 = func_8000EB20(D_80089620);
    func_8001A3B8(o->a1868, 14, 4, 0.05f);
    c = &D_800F4D00;
    e = &o->e;
    e->vt[2].fn((char *)e + e->vt[2].adj, c);
    func_800ADC54(e, 1 << c->sh);
    e->b176 = 1;
    func_800B360C(e, D_800F4860);
}
