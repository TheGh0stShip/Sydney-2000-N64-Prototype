typedef struct { short adj; short pad; void (*fn)(); } VEnt;
typedef struct Obj { char pad0[0xC]; struct Obj *next; char pad10[0xB4 - 0x10]; VEnt *vt; } Obj;
typedef struct { char pad[0xB4]; VEnt *vt; char rest[212 - 0xB8]; } Sub;
typedef struct { char pad[0xC]; Obj **wp; unsigned short cap; unsigned short used; } Pool;
typedef struct {
    char pad0[8];
    Obj *head;
    char padc[0xDC - 0xC];
    int snd[5];
    char padf0[0xF0 - 0xF0];
    Sub subs[50];
    char pad[0x2A58 - (0xF0 + 50 * 212)];
    int active;
    char pad2a5c[0x2A64 - 0x2A5C];
    unsigned short nsubs;
    char pad2a66[0x2A70 - 0x2A66];
    int res;
} Scene;

extern Pool D_800F26B0;
extern char D_800F26E0[];
extern void func_800B35F0(void *o);
extern void func_8001A248(int *h);
extern void func_800AACB0(char *l, Obj *o, int n);
extern void func_80017860(int r);
extern void func_80017D64(int n);

static inline void sub_reset(Sub *u, char *self)
{
    u->vt[9].fn(self + u->vt[9].adj);
    u->vt[3].fn(self + u->vt[3].adj);
}

void func_800D771C(Scene *s)
{
    unsigned char i;
    int off;
    Obj *o;
    Obj *next;
    Pool *p;
    Sub *u;

    func_800B35F0(s);
    if (s->active != 0) {
        i = 0;
        do {
            if (s->snd[i] != 0) {
                func_8001A248(&s->snd[i]);
            }
            s->snd[i] = 0;
            i++;
        } while (i < 5);
        for (i = 0; i < s->nsubs; i++) {
            off = i * sizeof(Sub) + 0xF0;
            sub_reset(&s->subs[i], (char *)s + off);
        }
        s->nsubs = 0;
        s->active = 0;
    }
    o = s->head;
    while (1) {
        if (o == 0) break;
        next = o->next;
        func_800B35F0(o);
        o->vt[3].fn((char *)o + o->vt[3].adj);
        o->vt[3].fn((char *)o + o->vt[3].adj);
        p = &D_800F26B0;
        func_800AACB0(D_800F26E0, o, 0);
        if (p->used < p->cap) {
            o->vt[1].fn((char *)o + o->vt[1].adj, 2);
            *p->wp = o;
            p->wp++;
            p->used++;
        }
        o = next;
    }
    func_80017860(s->res);
    func_80017D64(0);
}
