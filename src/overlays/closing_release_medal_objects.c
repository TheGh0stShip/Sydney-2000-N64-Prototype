typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short off; short pad; void (*fn)(); } VEnt;
typedef struct { VEnt e[10]; } VT;
typedef struct { u8 pad[180]; VT *vt; } Obj;
typedef struct { void *base; int f4; int f8; Obj **top; u16 cap; u16 cnt; } Pool;
typedef struct { u8 pad[1084]; Pool p1; Pool p2; Obj *a[10]; Obj *b[10]; u8 pad2[9053 - 1204]; u8 flag; } Scene;
extern void func_800AC308(Obj *);
extern void func_800AACB0(void *, Obj *, int);
extern void func_800AA658(void *, void *);
extern char D_800F26E0[];
#define VCALL(o, k) ((o)->vt->e[k].fn((char *)(o) + (o)->vt->e[k].off))
static __inline__ void push(Pool *p, Obj *o) {
    if (p->cnt < p->cap) {
        o->vt->e[1].fn((char *)o + o->vt->e[1].off, 2);
        *p->top = o;
        p->top++;
        p->cnt++;
    }
}
#define PFREE(P) { Obj *b = (Obj *)(P).base; if (b != 0) { Pool *p = &(P); (P).base = 0;     if (p->f4) func_800AA658(b, &(P).f4); if (p->f8) func_800AA658(b, &(P).f8);     p->cap = 0; p->cnt = 0; p->top = 0; (P).base = 0; } }
void func_80072368(Scene *s) {
    int i = 0;
    char *ctx = D_800F26E0;
    Obj *o;
    Pool *p;
    while (1) {
        u8 n = i;
        if (n >= 10) break;
        func_800AC308(s->a[n]);
        VCALL(s->a[n], 3);
        VCALL(s->a[n], 9);
        VCALL(s->b[n], 3);
        VCALL(s->b[n], 9);
        o = s->a[n];
        VCALL(o, 3);
        func_800AACB0(ctx, o, 0);
        push(&s->p1, o);
        o = s->b[n];
        p = &s->p2;
        VCALL(o, 3);
        func_800AACB0(ctx, o, 0);
        push(p, o);
        i++;
    }
    PFREE(s->p1);
    PFREE(s->p2);
    s->flag = 0;
}
