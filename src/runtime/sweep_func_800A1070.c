typedef struct { float x, y, z; } Vec;
typedef struct { float r[3][4]; char pad[16]; Vec t; } Xf;
typedef struct { char pad[0x40]; Vec pos; } Body;
typedef struct {
    char pad0[0x14];
    Xf xf;
    char pad60[0xC0 - 0x60];
    int flags;
    int img;
    char padc8[0xD4 - 0xC8];
    int icon;
    int bar;
    char paddc[0xFC - 0xDC];
    int fc;
    unsigned char b100;
    char pad101[0x1E4 - 0x101];
    short ids[6];
} Gauge;

extern unsigned short func_8000EB20(char *s);
extern void func_80013208(int *out, float w, float h, int id, int n);
extern void func_800AD890(void *o, int n);
extern void func_800ADC54(void *o, int n);
extern void func_800AC37C(void *o, void *p);

static inline void ident(Xf *x)
{
    x->r[2][1] = 0.0f;
    x->r[2][0] = 0.0f;
    x->r[1][2] = 0.0f;
    x->r[1][0] = 0.0f;
    x->r[0][2] = 0.0f;
    x->r[0][1] = 0.0f;
    x->t.z = 0.0f;
    x->t.y = 0.0f;
    x->t.x = 0.0f;
    x->r[2][2] = 1.0f;
    x->r[1][1] = 1.0f;
    x->r[0][0] = 1.0f;
}

void func_800A1070(Gauge *g)
{
    Gauge *s;
    Body *b;

    g->icon = 0;
    g->bar = 0;
    func_80013208(&g->icon, 16.3835f, 16.3835f, func_8000EB20("POSICON"), 2);
    func_80013208(&g->bar, 49.150497f, 3.2766998f, func_8000EB20("POSBAR"), 2);
    ident(&g->xf);
    g->img = g->bar;
    g->fc = 0;
    g->b100 = 0;
    func_800AD890(g, 1);
    func_800ADC54(g, 1);
    g->flags |= 2;
    ((Gauge *)((char *)g + 0x110))->img = g->icon;
    s = (Gauge *)((char *)g + 0x110);
    func_800AD890(s, 1);
    func_800ADC54(s, 1);
    s->flags |= 0x400002;
    *((unsigned char *)g + 0x1C0) = 1;
    b = (Body *)((char *)g + 0x170);
    b->pos.x = -32.767f;
    b->pos.y = 0.0f;
    b->pos.z = 0.0f;
    func_800AC37C(s, g);
    g->ids[0] = func_8000EB20("POSBAR");
    g->ids[1] = func_8000EB20("POSICON");
    g->ids[2] = func_8000EB20("ROLLBAR");
    g->ids[3] = func_8000EB20("ROLLICON");
    g->ids[4] = func_8000EB20("TWISTBAR");
    g->ids[5] = func_8000EB20("TWIST2ICON");
}
