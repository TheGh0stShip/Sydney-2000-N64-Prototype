typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct VEnt {
    s16 off;
    s16 pad;
    void (*fn)();
} VEnt;

typedef struct Obj {
    u8 pad[180];
    VEnt *vt;
} Obj;

typedef struct List {
    Obj *head;
    s32 a;
    s32 b;
    Obj **wp;
    u16 cap;
    u16 cnt;
} List;

typedef struct Mgr {
    u8 pad[216];
    List list;
    Obj *objs[32];
} Mgr;

extern char D_800F26E0[];
extern void func_800AACB0(char *a, Obj *o, s32 z);
extern void func_800AA658(Obj *o, void *p);

#define VCALL(o, n) ((o)->vt[n].fn((u8 *)(o) + (o)->vt[n].off))

void func_800C68C8(Mgr *m)
{
    u8 i;
    Obj *o;
    List *l;

    i = 0;
    while (1) {
        if (!(i < 32)) {
            break;
        }
        VCALL(m->objs[i], 9);
        o = m->objs[i];
        l = &m->list;
        o->vt[3].fn((u8 *)o + o->vt[3].off);
        func_800AACB0(D_800F26E0, o, 0);
        if (l->cnt < l->cap) {
            o->vt[1].fn((u8 *)o + o->vt[1].off, 2);
            *l->wp = o;
            l->wp++;
            l->cnt++;
        }
        i++;
    }
    {
    Obj *h = m->list.head;
    List *k = &m->list;
    if (h != 0) {
        m->list.head = 0;
        if (k->a != 0) {
            func_800AA658(h, &m->list.a);
        }
        if (k->b != 0) {
            func_800AA658(h, &m->list.b);
        }
        k->cap = 0;
        k->cnt = 0;
        k->wp = 0;
        m->list.head = 0;
    }
    }
}
