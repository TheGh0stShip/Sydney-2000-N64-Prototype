typedef struct { int type; int time; } Msg;
typedef struct {
    char pad0[16]; int time;
    char pad1[196 - 20]; unsigned short flags;
    char pad2[200 - 198]; int v200;
    char pad3[268 - 204]; int v268;
    char pad4[292 - 272]; char sub292[4]; int v296;
    char pad5[376 - 300]; char sub376[452 - 376]; int v452;
} Obj;
extern void func_800AE1EC(Obj *, int);
extern int func_800AE9DC(void *, int, Obj *);
extern void func_800AE17C(Obj *);
extern void func_800B4B40(Obj *, void *, int);
extern void func_800ADFAC(Obj *);
extern void func_800AE304(Obj *);
void func_800B5264(Obj *o, Msg *m)
{
    int d = (m->time - o->time) >> 8;
    switch (m->type) {
    case 3:
        break;
    case 5:
        if (d == 0) return;
        func_800AE1EC(o, m->time);
        if (func_800AE9DC(o->sub292, o->v200, o)) func_800AE17C(o);
        func_800B4B40(o, o->sub376, o->v452);
        break;
    }
    o->time = m->time;
    if (o->v296 == 0) {
        if (o->v268) func_800ADFAC(o);
        if (o->flags & 1) func_800AE304(o);
    }
}
