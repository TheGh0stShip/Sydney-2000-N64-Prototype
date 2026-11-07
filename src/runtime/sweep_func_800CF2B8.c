typedef struct VT { int p0; int p1; short off; short p2; void (*dtor)(char *, int); } VT;
typedef struct { char p0[180]; VT *vt; char p1[212 - 184]; } A;
typedef struct { char p0[180]; VT *vt; char p1[220 - 184]; } B;
typedef struct {
    char p0[180]; VT *vt; char p1[212 - 184];
    A a6[8]; char q0[1924 - 1908];
    B b4[4];
    B b5[7];
    B b4x[5]; char q2[5464 - 5444];
    A a3[5]; A a2[5]; A a1[5];
    A s2; A s1; A s0;
} Obj;

extern VT D_80089C80;
extern VT D_80086598;
extern void func_800ADDA4(void *, int);

void func_800CF2B8(Obj *o, int f)
{
    A *p;
    B *pb;
    o->vt = &D_80089C80;
    func_800ADDA4(&o->s0, 2);
    func_800ADDA4(&o->s1, 2);
    func_800ADDA4(&o->s2, 2);
    if (o->a1 != 0) {
        p = o->a1 + 5;
        while (o->a1 != p) {
            p--;
            p->vt->dtor((char *)p + p->vt->off, 2);
        }
    }
    if (o->a2 != 0) {
        p = o->a2 + 5;
        while (o->a2 != p) {
            p--;
            p->vt->dtor((char *)p + p->vt->off, 2);
        }
    }
    if (o->a3 != 0) {
        p = o->a3 + 5;
        while (o->a3 != p) {
            p--;
            p->vt->dtor((char *)p + p->vt->off, 2);
        }
    }
    if (o->b4x != 0) {
        pb = o->b4x + 5;
        while (o->b4x != pb) {
            pb--;
            pb->vt->dtor((char *)pb + pb->vt->off, 2);
        }
    }
    if (o->b5 != 0) {
        pb = o->b5 + 7;
        while (o->b5 != pb) {
            pb--;
            pb->vt->dtor((char *)pb + pb->vt->off, 2);
        }
    }
    { B *q = &o->b4[3]; q->vt = &D_80086598; func_800ADDA4(q, 2); }
    { B *q = &o->b4[2]; q->vt = &D_80086598; func_800ADDA4(q, 2); }
    { B *q = &o->b4[1]; q->vt = &D_80086598; func_800ADDA4(q, 2); }
    { B *q = &o->b4[0]; q->vt = &D_80086598; func_800ADDA4(q, 2); }
    if (o->a6 != 0) {
        p = o->a6 + 8;
        while (o->a6 != p) {
            p--;
            p->vt->dtor((char *)p + p->vt->off, 2);
        }
    }
    func_800ADDA4(o, f);
}
