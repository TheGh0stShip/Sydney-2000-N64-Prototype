typedef struct { int type; int time; } Msg;
typedef struct {
    char pad0[16]; int time;
    char pad1[196 - 20]; unsigned short flags;
    char pad2[200 - 198]; float f200;
    char pad3[268 - 204]; int v268;
    char pad4[292 - 272]; char sub292[4]; int v296;
    char pad5[376 - 300]; char sub376[12]; char sub388[12]; float f400;
} Obj;
extern void func_800AE1EC(Obj *, int);
extern void func_800AEAE8(void *, Obj *);
extern float func_800B47B0(Obj *, void *);
extern void func_800ADFAC(Obj *);
extern void func_800AE304(Obj *);
extern void func_800B4C2C(Obj *, void *);
void func_800B68C0(Obj *o, Msg *m)
{
    int d = (m->time - o->time) >> 8;
    switch (m->type) {
    case 3:
        break;
    case 5:
        if (d == 0) return;
        func_800AE1EC(o, m->time);
        if (o->f200 < o->f400) func_800AEAE8(o->sub292, o);
        o->f400 = func_800B47B0(o, o->sub388);
        func_800B4C2C(o, o->sub376);
        break;
    }
    o->time = m->time;
    if (o->v296 == 0) {
        if (o->v268) func_800ADFAC(o);
        if (o->flags & 1) func_800AE304(o);
    }
}
