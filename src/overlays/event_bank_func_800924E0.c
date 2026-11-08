typedef unsigned char u8;
typedef signed char s8;
typedef struct VT { short d; short pad; void (*fn)(); } VT;
typedef struct VTab { char pad[16]; VT ini; char pad2[64-24]; VT go; } VTab;
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
typedef struct G { char pad0[16]; Ent ent[42]; char pad[2564-16-42*60]; int wA04; char p[2576-2568]; u8 tab[1][12]; } G;
typedef struct S {
    char pad[22988];
    Obj *obj;
    char p1[23444 - 22992];
    int w5B94;
    char p2[23680 - 23448];
    int w5C80;
    char w5C84[29680 - 23684];
    void *p73F0;
    char p3[30120 - 29684];
    s8 c75A8;
    char p4;
    s8 c75AA;
    u8 b75AB;
    char p5[30132 - 30124];
    char x75B4[4];
} S;
extern G *D_800FC270;
extern char D_800F2758[];
extern char D_80071298[];
extern void *D_80076960[];
extern VTab D_80071458, D_80078B18;
extern char D_80086598[];
extern char D_800F2A70[];
extern V5 D_800712A0;
extern void func_800AA804(void *, void *, int, void *);
extern void func_80017A90(int);
extern void func_8001786C(void *);
extern int func_800DAC28(int);
extern void *func_800140A0(void *, int, int);
extern Obj *func_800AAA58(int, void *);
extern void func_800BA1FC(Obj *);
extern void func_800AED80(void *);
extern void func_800D28B0(void *);
extern void func_800ADE10(void *);
extern void func_800ADED4(void *);
extern void func_8009A828(void *, int, int);
extern void func_8007B258(Obj *, void *, int, int);

void func_800924E0(S *s, int a1)
{
    u8 *e;
    u8 b47, b55;
    Obj *o;
    Sub *q, *r;
    u8 x;
    Ent *en;

    e = D_800FC270->tab[s->c75A8];
    b47 = e[0];
    b55 = e[1];
    if (s->obj == 0) {
        func_800AA804(D_800F2758, &s->obj, 4420, D_80071298);
        if (a1 == 0) {
            func_80017A90(0x40000000);
            if (s->c75AA != b55) {
                if (s->c75AA != -1) func_8001786C(s->p73F0);
                s->c75AA = b55;
                s->p73F0 = func_800140A0(D_80076960[func_800DAC28(b55)], b55, 1);
            }
            func_80017A90(0x20000000);
        }
    } else {
        s->p73F0 = s->obj->w2D8;
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
    s->obj->w2D8 = s->p73F0;
    s->obj->vt->ini.fn((char *)s->obj + s->obj->vt->ini.d, s);
    s->obj->w284 = s->x75B4;
    s->obj->w288 = D_800F2A70;
    s->obj->b1A8 = b47;
    s->obj->b1A9 = b55;
    s->obj->b27C = b55 & 7;
    if ((s8)b47 != 8) {
        D_800FC270->ent[(s8)b47].o = s->obj;
        x = D_800FC270->ent[(s8)b47].b20;
    } else {
        x = 3;
    }
    s->obj->b1AA = x;
    s->obj->b1AB = 0;
    if (s->b75AB == 2) {
        V5 t;
        Obj *p = s->obj;
        t = D_800712A0;
        p->v = D_800712A0;
    } else {
        func_8009A828(&s->obj->v, b55, (s8)b47);
    }
    if (D_800FC270->wA04 == 0) s->obj->v.d = 0;
    if (a1 == 0) {
        func_8007B258(s->obj, s->w5C84, s->w5B94, s->w5C80);
        s->obj->vt->go.fn((char *)s->obj + s->obj->vt->go.d);
    } else {
        s->obj->w2FC = 0;
    }
}
