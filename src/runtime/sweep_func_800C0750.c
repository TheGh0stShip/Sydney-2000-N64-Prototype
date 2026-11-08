typedef struct {
    short off;
    short pad;
    void (*fn)();
} VEnt;

typedef struct {
    char p0[16];
    VEnt setup;
} VTbl;

typedef struct {
    char p0[20];
    float m[19];
    char p1[180 - 96];
    VTbl *vt;
    char p2[192 - 184];
    int flags;
    int res;
    char p3[201 - 200];
    unsigned char mode;
    char p4[212 - 202];
    int arg;
} Sprite;

typedef struct {
    char p0[216];
    int slot;
} Ctx;

extern Ctx *D_800F63F0;

void func_8001A330(int *res, int v);
void func_80019680(int *res, char *name);
void func_800ADC10(Sprite *s);
void func_800191E0(int *res, int a);
void func_8001A1D8(int *res, float x0, float y0, float x1, float y1);
void func_8001A210(int *res, float a, float b, float c, float d, int e);
void func_800ADC54(Sprite *s, int mask);
void func_8001457C(Sprite *s);

static inline void ident(float *m)
{
    m[9] = 0;
    m[8] = 0;
    m[6] = 0;
    m[4] = 0;
    m[2] = 0;
    m[1] = 0;
    m[18] = 0;
    m[17] = 0;
    m[16] = 0;
    m[10] = 1.0f;
    m[5] = 1.0f;
    m[0] = 1.0f;
}

void func_800C0750(Sprite *s, float x, float y, float w, float h, unsigned char kind, int arg)
{
    float *m;

    s->res = 0;
    m = s->m;
    ident(m);
    m[16] = x;
    m[17] = y;
    m[18] = 0;
    s->mode = 0;
    s->flags |= 0x20000;
    switch (kind) {
    case 0:
        func_8001A330(&s->res, 0xFFFF);
        break;
    case 1:
        func_80019680(&s->res, "TITLE_FLUID");
        break;
    case 2:
        func_80019680(&s->res, "TITLE_FADE");
        break;
    case 3:
        func_800ADC10(s);
        func_80019680(&s->res, "TITLE_CURVE");
        break;
    case 4:
        func_80019680(&s->res, "TITLE_TRIM");
        break;
    case 5:
        func_80019680(&s->res, "OLY_LOGO");
        break;
    case 8:
        s->mode = 1;
        s->flags |= 0x20000;
        func_80019680(&s->res, "BAR_FLAG");
        break;
    case 6:
        s->mode = 1;
        s->flags |= 0x20000;
        func_80019680(&s->res, "FIRE_PROC");
        break;
    case 7:
        s->mode = 2;
        s->flags |= 0x20000;
        func_80019680(&s->res, "FLAME_BOT");
        break;
    case 28:
        s->mode = 1;
        s->flags |= 0x20000;
        func_80019680(&s->res, "ICON_ACCEPT");
        break;
    case 29:
        s->mode = 1;
        s->flags |= 0x20000;
        func_80019680(&s->res, "ICON_BACK");
        break;
    }
    if (s->res != 0) {
        func_800191E0(&s->res, arg);
        func_8001A1D8(&s->res, 0.0f, 0.0f, w, h);
        func_8001A210(&s->res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        func_800ADC54(s, 1 << D_800F63F0->slot);
        func_8001457C(s);
        s->flags |= 2;
        s->vt->setup.fn((char *)s + s->vt->setup.off, s->arg);
    }
}
