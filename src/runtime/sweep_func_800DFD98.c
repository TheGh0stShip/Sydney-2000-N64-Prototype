typedef struct {
    unsigned short a;
    unsigned short b;
} Pair;

typedef struct {
    char p0[0x38];
    float f38;
    char p1[0x208 - 0x3C];
    unsigned char b208;
    char p2[0x20C - 0x209];
    Pair pair[12];
    char p3[0x4B8 - 0x23C];
    float spd[12];
    char p4[0x4F2 - 0x4E8];
    unsigned char b4F2;
    char p5[0x9DC - 0x4F3];
    unsigned short sel;
    char p6[0x9E0 - 0x9DE];
    unsigned short v9E0;
    unsigned short v9E2;
    char p7[0x9E8 - 0x9E4];
    unsigned char b9E8;
    char p8[0xD48 - 0x9E9];
    int wD48;
    char p9[0xD50 - 0xD4C];
    unsigned short flags;
} Glob;

typedef struct {
    char p0[0xBC];
    char *snd;
    char p1[0x4A9E - 0xC0];
    unsigned char done;
    char p2[0x4AA0 - 0x4A9F];
    int state;
} Obj;

typedef struct {
    short *p;
    int v;
} Slot;

extern Glob *D_800FC270;
extern int D_800F2620;
extern char D_800F26E0[];
extern int D_800F2744;
extern char D_800F11A0[];
extern short D_800FEEB6;
extern char D_800F5900[];
extern Slot D_800FCD8C[];
extern short *D_800FF484;

void func_800DF828(Obj *p, int k);
void func_800AB2A4(char *, int, int, void *, void *, int);
void func_800E8EB4(char *s);
void func_800E2788(Obj *p);
void func_800E11E4(Obj *p, int n);
void func_800E9A2C(char *s, int f, int n);
void func_800D53A0(char *s, int n);
void func_80008570(int a, int b, int c, int d);
void func_800E287C(Obj *p, int n);
void func_800DFFF4(Obj *p, int n);

void func_800DFD98(Obj *p, int k)
{
    Glob *g;
    unsigned short f;
    unsigned short v;
    unsigned char i;

    func_800DF828(p, k);
    switch (k) {
    case 43:
        D_800FC270->b208 = 1;
        if (D_800F2620) {
            func_800AB2A4(D_800F26E0, D_800F2744, 7, p, 0, 15);
            return;
        }
        func_800E8EB4(p->snd);
        func_800AB2A4(D_800F26E0, D_800F2744, 3, D_800F11A0, p, 0x10012);
        return;
    case 15:
        func_800E2788(p);
        return;
    case 17: case 18: case 19: case 20: case 21: case 22:
    case 23: case 24: case 25: case 26: case 27: case 28:
        g = D_800FC270;
        g->sel = k - 17;
        v = g->pair[g->sel].b;
        g->v9E0 = v;
        g->v9E2 = v;
        f = g->flags;
        g->f38 = g->spd[g->sel];
        if (f & 0x80) {
            g->b9E8 = 1;
            g->flags = f & 0xFF7F;
            D_800FC270->wD48 = D_800FC270->sel;
            func_800E8EB4(p->snd);
            func_800AB2A4(D_800F26E0, D_800F2744, 3, D_800F11A0, p, 0x10014);
        } else {
            func_800E11E4(p, 1);
        }
        return;
    case 10:
        func_800E9A2C(p->snd, 1024, 1);
        p->state = 17;
        D_800FEEB6 = 2;
        func_800D53A0(D_800F5900, 21);
        p->done = 1;
        return;
    case 39:
        for (i = 0; i < 1; i++) {
            D_800FCD8C[i].p = &D_800FF484[i];
            D_800FCD8C[i].v = i + 29;
        }
        func_80008570(0, 0, 0, 0);
        if (D_800FC270->b4F2) func_800E287C(p, 0);
        else func_800DFFF4(p, 1);
        p->done = 1;
        return;
    case 9:
        func_800DFFF4(p, 0);
        p->done = 1;
        return;
    }
}
