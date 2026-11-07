typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short off; short pad; void (*fn)(); } VEnt;
typedef struct { VEnt e[10]; } VT;
typedef struct { u8 pad[180]; VT *vt; } Obj;
typedef struct { void *base; int f4; int f8; Obj **top; u16 cap; u16 cnt; } Pool;
typedef struct { u8 pad[1432]; Pool pool; Obj *grid[3][4]; } Cer;
extern void func_800AC308(Obj *);
extern void func_800AACB0(void *, Obj *, int);
extern void func_800AA658(void *, void *);
extern void func_800AC334(void *);
extern void func_800ADC1C(void *);
extern void func_800A7910(void *);
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
#define PFREE(P) { Obj *b = (Obj *)(P).base; if (b != 0) { Pool *p = &(P); (P).base = 0; \
    if (p->f4) func_800AA658(b, &(P).f4); if (p->f8) func_800AA658(b, &(P).f8); \
    p->cap = 0; p->cnt = 0; p->top = 0; (P).base = 0; } }
void func_80074E48(Cer *c) {
    int i = 0;

    while (1) {
        u8 n = i;
        int j;
        if (n >= 3) break;
        j = 0;
        while (1) {
            u8 m = j;
            Obj *ob;
            Pool *p;
            if (m >= 4) break;
            func_800AC308(c->grid[n][m]);
            VCALL(c->grid[n][m], 3);
            VCALL(c->grid[n][m], 9);
            ob = c->grid[n][m];
            p = &c->pool;
            VCALL(ob, 3);
            func_800AACB0(D_800F26E0, ob, 0);
            push(p, ob);
            j++;
        }
        i++;
    }
    PFREE(c->pool);
    func_800AC334((u8 *)c + 1956); func_800ADC1C((u8 *)c + 1956);
    func_800AC334((u8 *)c + 2360); func_800ADC1C((u8 *)c + 2360);
    func_800ADC1C((u8 *)c + 3356);
    func_800ADC1C((u8 *)c + 3568);
    func_800AC334((u8 *)c + 500); func_800A7910((u8 *)c + 500);
    ((u8 *)c)[10338] = 0;
}
