typedef unsigned char u8;
typedef float f32;

typedef struct {
    char pad0[0x40];
    short off;
    char pad42[2];
    void (*fn)(void *);
} VT;

typedef struct {
    char pad0[0x54];
    int w54;
    f32 f58;
    char pad5C[0xB4 - 0x5C];
    VT *vt;
    char padB8[0xC0 - 0xB8];
    int flags;
    int wC4;
    char padC8[0xD4 - 0xC8];
} Ent;

typedef struct {
    f32 m[3][4];
    char pad30[0x10];
    f32 t[3];
} Mtx;

typedef struct {
    int w0;
    f32 f4;
    int w8;
} Snd;

typedef struct {
    char pad0[0x42F0];
    int w42F0;
    char pad42F4[0x433C - 0x42F4];
    int w433C;
    Ent *e4340;
    int w4344;
    Ent *e4348;
    int w434C;
    Ent *e4350;
    char p4354[0x4368 - 0x4354];
    Mtx mtx;
    char pad43B4[0x4418 - 0x43B4];
    int w4418;
} S;

extern char D_800F2758[];
extern void func_800AA804(void *, void *, int, char *);
extern int func_80013E7C(char *, void *, int);
extern void *func_800AAA58(int, void *);
extern void func_800ADED4(void *);
extern void func_800ADC54(void *, int);
extern void func_800ADC38(void *);

typedef struct { f32 x, y, z; } Vec;

static inline void mtx_ident(Mtx *m)
{
    m->m[0][1] = m->m[0][2] = m->m[1][0] = m->m[1][2] = m->m[2][0] = m->m[2][1] = 0.0f;
    m->t[0] = m->t[1] = m->t[2] = 0.0f;
    m->m[0][0] = m->m[1][1] = m->m[2][2] = 1.0f;
}

static inline void vec_set(Vec *v, f32 x, f32 y, f32 z)
{
    v->x = x; v->y = y; v->z = z;
}

void func_80071948(S *s)
{
    u8 i;
    Ent *e;

    s->w42F0 = 0;
    s->e4340 = 0;
    s->e4348 = 0;
    s->e4350 = 0;
    func_800AA804(D_800F2758, &s->e4350, 2968, "HURDH");
    func_800AA804(D_800F2758, &s->e4348, 2968, "HURDM");
    func_800AA804(D_800F2758, &s->e4340, 2968, "HURDL");
    if ((s->w434C = func_80013E7C("GRAPHICS__VIRTUALGYM__HEIGHTDEPTHJUMP__LASERHIGH_OBB", &s->w42F0, 0)) == 0) {
        return;
    }
    i = 0;
    while (1) {
        if (i >= 14) break;
        func_800ADED4(func_800AAA58(212, &s->e4350[i]));
        s->e4350[i].wC4 = s->w434C;
        func_800ADC54(&s->e4350[i], 1);
        s->e4350[i].flags |= 2;
        s->e4350[i].vt->fn((char *)&s->e4350[i] + s->e4350[i].vt->off);
        s->e4350[i].w54 = 0;
        s->e4350[i].f58 = 14.7451506f;
        e = s->e4350;
        e += i;
        e->flags |= 4;
        i++;
    }
    if ((s->w4344 = func_80013E7C("GRAPHICS__VIRTUALGYM__HEIGHTDEPTHJUMP__LASERMED_OBB", &s->w42F0, 0)) == 0) {
        return;
    }
    i = 0;
    while (1) {
        if (i >= 14) break;
        func_800ADED4(func_800AAA58(212, &s->e4348[i]));
        s->e4348[i].wC4 = s->w4344;
        func_800ADC54(&s->e4348[i], 1);
        s->e4348[i].flags |= 2;
        s->e4348[i].vt->fn((char *)&s->e4348[i] + s->e4348[i].vt->off);
        s->e4348[i].w54 = 0;
        s->e4348[i].f58 = 12.4514599f;
        e = s->e4348;
        e += i;
        e->flags |= 4;
        i++;
    }
    if ((s->w433C = func_80013E7C("GRAPHICS__VIRTUALGYM__HEIGHTDEPTHJUMP__LASERLOW_OBB", &s->w42F0, 0)) == 0) {
        return;
    }
    i = 0;
    while (1) {
        if (i >= 14) break;
        func_800ADED4(func_800AAA58(212, &s->e4340[i]));
        s->e4340[i].wC4 = s->w433C;
        func_800ADC54(&s->e4340[i], 1);
        s->e4340[i].flags |= 2;
        s->e4340[i].vt->fn((char *)&s->e4340[i] + s->e4340[i].vt->off);
        s->e4340[i].w54 = 0;
        s->e4340[i].f58 = 9.17475986f;
        e = s->e4340;
        e += i;
        e->flags |= 4;
        i++;
    }
    if ((s->w4418 = func_80013E7C("GRAPHICS__VIRTUALGYM__HEIGHTDEPTHJUMP__STANDBOX_OBB", &s->w42F0, 0)) == 0) {
        return;
    }
    mtx_ident(&s->mtx);
    vec_set((Vec *)s->mtx.t, 0.0f, 10.4854393f, 0.0f);
    func_800ADC54(s->p4354, 1);
    func_800ADC38(s->p4354);
}
