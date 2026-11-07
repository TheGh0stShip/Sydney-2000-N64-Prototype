typedef struct { short adj; short pad; void (*fn)(void *, void *); } VEnt;
typedef struct { char p[0x40]; float a, b, c; } Sub;
typedef struct { int a, b, c, d; } E16;
typedef struct { char p[0x50]; E16 e[1]; } Tab;
typedef struct { char p[8]; Tab *t; } Root;
typedef struct { char p[60]; } E60;
typedef struct { char p[20]; E60 e[1]; } G;
typedef struct { char p[0xD8]; int sh; } Cfg;
typedef struct {
    char p0[0x60];
    Sub s96;
    char p1[0xB0 - 0xAC];
    unsigned char b176;
    char p2[3];
    VEnt *vt;
    char p3[0x134 - 0xB8];
    Sub s308;
    char p4[0x1A8 - 0x180];
    char s424[0x2E4 - 0x1A8];
    Sub s740;
    char p5[0x348 - 0x330];
    int f840;
    char p6[0x3B8 - 0x34C];
    Sub s952;
    char p7[0xAD8 - 0x404];
    char s2776[1];
} Obj;
typedef struct { char p[0x1A8]; unsigned char b424, b425; } P;

extern Cfg D_800F4D00;
extern Root *D_800FCB44;
extern G *D_800FC270;
extern E60 *D_80102894;
extern char D_800F4B80[];
extern void func_800ADC54(void *, int);
extern void func_800CE6C4(void *, int);
extern void func_800B31EC(int);
extern void func_800B360C(void *, void *);
extern void func_800B2158(void *, int);

void func_800D1FFC(Obj *o, P *p)
{
    Cfg *c;

    {
        Sub *s = &o->s96;
        s->c = 0.0f;
        s->a = 376.0f;
        s->b = 200.0f;
    }
    c = &D_800F4D00;
    o->vt[2].fn((char *)o + o->vt[2].adj, c);
    func_800ADC54(o, 1 << c->sh);
    o->b176 = 1;
    o->f840 = (D_800FCB44->t->e + p->b424)->d;
    {
        Sub *s = &o->s740;
        s->a = 117.0f;
        s->b = 4.0f;
        s->c = 0.0f;
    }
    func_800CE6C4(o->s2776, p->b425);
    {
        Sub *s = &o->s308;
        s->c = 0.0f;
        s->a = 197.0f;
        s->b = 2.0f;
    }
    D_80102894 = &D_800FC270->e[p->b424];
    func_800B31EC(0);
    func_800B360C(o->s424, D_800F4B80);
    func_800B2158(o->s424, 0);
    {
        Sub *s = &o->s952;
        s->c = 0.0f;
        s->a = 64.0f;
        s->b = 3.0f;
    }
}
