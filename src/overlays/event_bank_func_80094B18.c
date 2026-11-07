typedef unsigned char u8;
typedef signed char s8;
typedef struct VT { short d; short pad; void (*fn)(); } VT;
typedef struct VTab { char pad[8]; VT m8; VT ini; char pad2[64-24]; VT go; } VTab;
typedef struct V5 { int a, b, c, d, e; } V5;
typedef struct Sub { int w0; char pad[176-4]; u8 b176; char pa[3]; void *vt; char p1[212-184]; short h212; short h214; short h216; char p2[220-218]; } Sub;
typedef struct Obj {
    int w0;
    char p0[180 - 4];
    VTab *vt;
    char p1[202 - 184];
    u8 bCA;
    char p2[404 - 203];
    V5 v;
    u8 b1A8, b1A9, b1AA, b1AB, b1AC;
    char p3[636 - 429];
    u8 b27C;
    char p4[638 - 637];
    short h27E;
    char p5[644 - 640];
    void *w284;
    void *w288;
    char p6[728 - 652];
    void *w2D8;
    char p7[764 - 732];
    int w2FC;
    char p8[776 - 768];
    int w308;
    char p9[800 - 780];
    int w320;
    int w324;
    char p10[3612-808];
    Sub s1;
    Sub s2;
    char p11[4264-4052];
    int w10A8;
} Obj;
typedef struct Ent { char pad[16]; u8 b20; char p[56-17]; Obj *o; } Ent;
typedef struct G { char pad0[16]; Ent ent[42]; char pad[2560-16-42*60]; int wA00; int wA04; char p[2572-2568]; u8 nA0C; char pA0D[3]; u8 tab[64][12];
 char pE[3344-2576-64*12]; float fD10; char pD14[3411-3348]; u8 bD53; } G;
typedef struct R28 { char pad[16]; int w16; char p[28-20]; } R28;
typedef struct S {
    char pad[22988];
    Obj *obj;
    char p1[23444 - 22992];
    int w5B94;
    char p2[23680 - 23448];
    int w5C80;
    char w5C84[29680 - 23684];
    void *p73F0;
    int w73F4;
    char p3[30120 - 29688];
    s8 c75A8;
    char p4;
    s8 c75AA;
    u8 b75AB;
    char p5[30132 - 30124];
    char x75B4[30204-30132];
    R28 *p75FC;
} S;
extern G *D_800FC270;
extern char D_800F2758[];
extern char D_800713DC[];
extern VTab D_80071458, D_80078B18;
extern char D_80086598[];
extern void func_800AA804(void *, void *, int, void *);
extern void func_800AA658(void *, void *);
extern Obj *func_800AAA58(int, void *);
extern void func_800BA1FC(Obj *);
extern void func_800AED80(void *);
extern void func_800D28B0(void *);
extern void func_800ADE10(void *);
extern void func_800ADED4(void *);
extern void func_8009A828(void *, int, int);
extern int func_8007BC90(Obj *);

void func_80094B18(S *s)
{
    int max;
    int min;
    u8 i;
    int made;
    Obj *o;
    Sub *q, *r;
    u8 *e;
    int v;
    int x;
    G *g;

    max = 148;
    min = 300;
    made = 0;
    if (s->obj == 0) {
        func_800AA804(D_800F2758, &s->obj, 4420, D_800713DC);
        made = 1;
    }
    o = func_800AAA58(4420, s->obj);
    func_800BA1FC(o);
    o->vt = &D_80071458;
    func_800AED80((char *)o + 652);
    o->b1AC = 0;
    o->h27E = 0;
    o->bCA = 0;
    o->w284 = 0;
    o->w288 = 0;
    o->w2D8 = 0;
    o->vt = &D_80078B18;
    o->w308 = 0;
    o->w320 = 0;
    o->w324 = 0;
    func_800D28B0((char *)o + 812);
    func_800D28B0((char *)o + 2212);
    q = &o->s1;
    func_800ADE10(q);
    r = &o->s2;
    q->vt = D_80086598;
    q->w0 = 62;
    q->b176 = 1;
    q->h214 = -1;
    q->h216 = -1;
    q->h212 = 4;
    func_800ADE10(r);
    r->vt = D_80086598;
    r->w0 = 62;
    r->b176 = 1;
    r->h214 = -1;
    r->h216 = -1;
    r->h212 = 4;
    func_800ADED4((char *)o + 4052);
    o->w10A8 = 0;
    o->w0 = 96;
    i = 0;
    while (1) {
        u8 c0, c1;
        if (i >= D_800FC270->nA0C) break;
        e = D_800FC270->tab[i];
        c0 = e[0];
        c1 = e[1];
        s->obj->b1A8 = c0;
        s->obj->b1A9 = c1;
        func_8009A828(&s->obj->v, c1, (s8)c0);
        v = func_8007BC90(s->obj);
        s->p75FC[i].w16 = v;
        if (max < v) max = v;
        if (v < min) min = v;
        i++;
    }
    s->obj->vt->m8.fn((char *)s->obj + s->obj->vt->m8.d, 2);
    if (made) func_800AA658(D_800F2758, &s->obj);
    g = D_800FC270;
    if (g->wA04 == 0 || (g->wA00 == 4 && g->wA04 == 1)) {
        min = (unsigned int)(g->fD10 * 100.0f + 0.5f);
        x = min - 6;
    } else {
        x = min - 12;
        switch (D_800FC270->bD53) {
        case 0: if (x > 180) x = 180; break;
        case 1: if (x > 200) x = 200; break;
        case 2: if (x > 215) x = 215; break;
        case 3: if (x > 220) x = 220; break;
        }
    }
    if (x < 148) x = 148;
    else if (x > 300) x = 300;
    s->w73F4 = x;
    if (s->b75AB == 2) s->w73F4 = 185;
}
