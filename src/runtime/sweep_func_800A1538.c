typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { float x, y, z; } Vec;
typedef struct { char pad[64]; Vec pos; } Sub;
typedef struct { short d; short pad; void (*f)(); } VEnt;
typedef struct { char pad[64]; VEnt e; } VTab;
typedef struct {
    char pad0[20]; Sub sub;
    char pad1[180 - 96]; VTab *vt;
    char pad2[212 - 184]; void *a; void *b;
    char pad3[252 - 220]; int v252; u8 kind; char pad4[264 - 257]; Vec *src; char pad5[272 - 268]; char ctl[484 - 272];
    u16 t[6];
} Obj;
extern void func_80017CF4(void *, int, int);
extern void func_800AD9E8(Obj *);
extern void func_800ADC5C(void *);
extern void func_800ADC38(void *);
static inline void topos(Vec *a, Sub *s) { s->pos.x = a->x; s->pos.y = a->y; s->pos.z = a->z; }
void func_800A1538(Obj *o, u8 kind, Vec *p, u8 flag)
{
    o->kind = kind;
    o->src = p;
    switch (o->kind) {
    case 6:
    case 7:
    case 8:
        func_80017CF4(o->b, 0, o->t[0]);
        func_80017CF4(o->a, 0, o->t[1]);
        break;
    case 3:
        func_80017CF4(o->b, 0, o->t[2]);
        func_80017CF4(o->a, 0, o->t[3]);
        break;
    case 4:
    case 5:
        func_80017CF4(o->b, 0, o->t[4]);
        func_80017CF4(o->a, 0, o->t[5]);
        break;
    }
    topos(p, &o->sub);
    func_800AD9E8(o);
    func_800ADC5C(o->ctl);
    o->v252 = 0;
    if (flag) {
        o->vt->e.f((char *)o + o->vt->e.d);
        func_800ADC38(o->ctl);
    }
}
