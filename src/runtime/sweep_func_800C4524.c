typedef struct { short adj; short pad; void (*fn)(void *, ...); } VEnt;
typedef struct { float m[19]; } Mtx;
typedef struct {
    char p0[0x60];
    Mtx mtx;
    char p0b[0xB0 - 0x60 - sizeof(Mtx)];
    unsigned char b176;
    char p1[3];
    VEnt *vt;
    char p2[0xC0 - 0xB8];
    int flags;
    int h196;
    char p3;
    unsigned char b201;
    char p4[212 - 0xCA];
} Ent;
typedef struct {
    char p0[0x104];
    Ent sub;
    char p2[0x318 - 0x104 - sizeof(Ent)];
    Ent *extra;
} Obj;
typedef struct { char p0[0xD8]; int sh; } Cfg;

extern int D_800F40F8;
extern Cfg *D_800F63F0;
extern char D_800F2758[];
extern void func_80019680(int *, const char *);
extern void func_800191E0(int *, int);
extern void func_8001A1D8(int *, float, float, float, float);
extern void func_8001A210(int *, float, float, float, float, int);
extern void func_800ADC54(void *, int);
extern void func_800AA804(void *, Ent **, int, const char *);
extern void *func_800AAA58(int, void *);
extern void func_800CE3A8(void *);
extern void func_800CE468(Ent *, int, int, int, int, int);

static const char D_psu_flag[] = "Player Setup Flag";
static const char D_psu_back[] = "PSU_BACK";

void func_800C4524(Obj *o)
{
    Ent *s;
    Mtx *p;

    if (D_800F40F8 == 0) {
        int h;
        h = 0;
        func_80019680(&h, D_psu_back);
        func_800191E0(&h, 0xC8FFFFFF);
        func_8001A1D8(&h, -14.0f, -2.0f, 103.0f, 57.0f);
        func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        D_800F40F8 = h;
    }
    s = &o->sub;
    s->h196 = D_800F40F8;
    p = &o->sub.mtx;
    p->m[9] = 0.0f;
    p->m[8] = 0.0f;
    p->m[6] = 0.0f;
    p->m[4] = 0.0f;
    p->m[2] = 0.0f;
    p->m[1] = 0.0f;
    p->m[18] = 0.0f;
    p->m[17] = 0.0f;
    p->m[16] = 0.0f;
    p->m[10] = 1.0f;
    p->m[5] = 1.0f;
    o->sub.mtx.m[0] = 1.0f;
    func_800ADC54(s, 1 << D_800F63F0->sh);
    s->b201 = 1;
    s->flags |= 0x20000;
    s->vt[8].fn((char *)s + s->vt[8].adj);
    s->vt[2].fn((char *)s + s->vt[2].adj, o);
    s->b176 = 1;
    if (o->extra == 0) {
        func_800AA804(D_800F2758, &o->extra, 212, D_psu_flag);
        func_800CE3A8(func_800AAA58(212, o->extra));
        func_800CE468(o->extra, 7, 0, 51, 14, 2);
        {
            Ent *q = o->extra;
            q->b201 = 3;
            q->flags |= 0x20000;
        }
        o->extra->b176 = 1;
        o->extra->vt[2].fn((char *)o->extra + o->extra->vt[2].adj, o);
        o->extra->vt[8].fn((char *)o->extra + o->extra->vt[8].adj);
    }
}
