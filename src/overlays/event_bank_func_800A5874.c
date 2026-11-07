typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0x10];
    s16 off10;
    char pad12[2];
    void (*fn14)(void *, void *);
    char pad18[0x40 - 0x18];
    s16 off40;
    char pad42[2];
    void (*fn44)(void *);
} VT;

typedef struct {
    f32 c[4];
    s32 z;
} Col;

typedef struct Ent {
    s32 f0;
    char pad4[0xB4 - 0x4];
    VT *vt;
    char padB8[0xCA - 0xB8];
    u8 bCA;
    char padCB[0x194 - 0xCB];
    Col col;
    u8 b1A8;
    u8 b1A9;
    u8 b1AA;
    u8 b1AB;
    u8 b1AC;
    char pad1AD[0x27C - 0x1AD];
    u8 b27C;
    char pad27D;
    s16 h27E;
    char pad280[4];
    void *f284;
    void *f288;
    char pad28C[0x2D8 - 0x28C];
    s32 f2D8;
    char pad2DC[0x320 - 0x2DC];
    s32 f320;
    s32 f324;
    char pad328[0x3A8 - 0x328];
    f32 f3A8;
} Ent;

typedef struct {
    char pad0[0xD8];
    u8 fD8[0x2FB4 - 0xD8];
    Ent *ent;
    char pad2FB8[0x7AE8 - 0x2FB8];
    s32 f7AE8;
    char pad7AEC[0x7CA0 - 0x7AEC];
    s32 snd;
    s8 sndId;
    char pad7CA5[0x7CAD - 0x7CA5];
    s8 slot;
    char pad7CAE;
    u8 mode;
    char pad7CB0[0x7CB8 - 0x7CB0];
    u8 f7CB8[0x7CF8 - 0x7CB8];
    s32 f7CF8;
} Obj;

typedef struct {
    char pad0[0x20];
    u8 b20;
    char pad21[0x48 - 0x21];
    Ent *ent;
    char pad4C[0x3C - 0x4C + 0x10];
} Lane;

extern u8 *D_800FC270;
extern u8 D_800F2758[];
extern u8 D_800F2A70[];
extern s32 D_80077290[];
extern u8 D_800716A8[];
extern u8 D_80078B38[];
extern void func_800AA804(void *, void *, s32, char *);
extern void func_80017A90(s32);
extern void func_8001786C(s32);
extern s32 func_800DAC28(s32);
extern s32 func_800140A0(s32, s32, s32);
extern void func_800BA0EC(void *);
extern void func_800ADB70(Ent *);
extern Ent *func_800AAA58(s32, Ent *);
extern void func_800BA1FC(Ent *);
extern void func_800AED80(void *);
extern void func_8009A828(void *, s32, s32);
extern void func_800B7130(Ent *, s32, s32, s32, s32);
extern void func_80078DE4(Ent *);
extern void func_80074D64(Obj *);
extern void func_800BB368(void *, Ent *, s32, s32);

static inline u8 lit(u8 b)
{
    switch (b) {
    case 0:
    case 6:
    case 10:
    case 15:
    case 17:
    case 28:
    case 31:
        return 0;
    }
    return 1;
}

static inline void play(Obj *o, s32 x)
{
    func_800B7130(o->ent, o->snd, x, 0, 1);
}

static inline void post(Obj *o, s32 m)
{
    if (m < 5) {
        if (m >= 2) {
            func_80074D64(o);
        } else if (m == 0) {
            func_80074D64(o);
        }
    }
}

void func_80074874(Obj *o, s32 flag)
{
    u8 *t;
    s8 a;
    u8 b;
    u8 c;
    Ent *e;

    t = D_800FC270 + (o->slot * 12 + 0xA10);
    a = t[0];
    b = t[1];
    if (o->ent == 0) {
        func_800AA804(D_800F2758, &o->ent, 952, "TpjAth");
        if (flag == 0) {
            func_80017A90(0x40000000);
            if (b != o->sndId) {
                if (o->sndId != -1 && o->snd != 0) {
                    func_8001786C(o->snd);
                }
                o->sndId = b;
                o->snd = func_800140A0(D_80077290[func_800DAC28(b)], b, 1);
            }
            func_80017A90(0x20000000);
        }
    } else {
        func_800BA0EC(o->ent);
        func_800ADB70(o->ent);
        o->snd = o->ent->f2D8;
    }
    e = func_800AAA58(952, o->ent);
    func_800BA1FC(e);
    e->vt = (VT *)D_800716A8;
    func_800AED80((u8 *)e + 652);
    e->vt = (VT *)D_80078B38;
    e->b1AC = 0;
    e->h27E = 0;
    e->bCA = 0;
    e->f284 = 0;
    e->f288 = 0;
    e->f2D8 = 0;
    e->f320 = 0;
    e->f324 = 0;
    e->f0 = 95;
    o->ent->f2D8 = o->snd;
    if (flag == 0) {
        o->ent->vt->fn14((u8 *)o->ent + o->ent->vt->off10, o);
    }
    o->ent->f284 = o->f7CB8;
    o->ent->f288 = D_800F2A70;
    o->ent->b1A8 = a;
    o->ent->b1A9 = b;
    o->ent->b27C = b & 7;
    if (a != 8) {
        u8 *l = D_800FC270 + a * 60;
        *(Ent **)(l + 0x48) = o->ent;
        c = l[0x20];
    } else {
        c = 3;
    }
    if (o->mode == 2) {
        c = 3;
    }
    o->ent->b1AA = c;
    o->ent->b1AB = 0;
    if (lit(b)) {
        o->ent->f3A8 = -1.96602011f;
    } else {
        o->ent->f3A8 = 0.0f;
    }
    if (o->mode == 2) {
        Ent *p = o->ent;
        Col k = { { 1.0f, 1.0f, 1.0f, 1.0f }, 0 };

        p->col = k;
    } else {
        func_8009A828(&o->ent->col, b, a);
    }
    if (*(s32 *)(D_800FC270 + 0xA04) == 0) {
        o->ent->col.c[3] = 0.0f;
    }
    if (flag == 0) {
        play(o, o->f7AE8);
        func_80078DE4(o->ent);
        o->ent->vt->fn44((u8 *)o->ent + o->ent->vt->off40);
        post(o, o->mode);
    }
    func_800BB368(o->fD8, o->ent, 1, 2);
    o->f7CF8 = -1;
}
