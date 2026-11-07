typedef struct { float x, y, z; } Vec;
typedef struct { char pad[12]; Vec cur; Vec prev; unsigned char type; char pad25; short link; char a[12]; char b[72 - 52]; } Node;
typedef struct { unsigned char n; char pad1; unsigned short cnt[3]; Node *lv[3]; int last; int now; } Grid;
typedef struct { char p[76]; } Link;
typedef struct { char pad[0x14]; char xf[0xD0 - 0x14]; Grid *grid; char pad_d4[0x160 - 0xD4]; Link *links; } Obj;
typedef struct { char p[80]; } Tmp;

extern int D_800F2744;
extern void func_800AC5CC(Link *l, void *xf, Tmp *t, int n);
extern void func_800AD2A8(void *xf, void *a, void *b, int n);

static inline void vcopy(Vec *a, Vec *b) { a->x = b->x; a->y = b->y; a->z = b->z; }

void func_800B9480(Obj *o)
{
    unsigned char k;
    unsigned short m;
    Node *n;
    Tmp t;

    if (o->grid == 0) {
        return;
    }
    k = 0;
    while (1) {
        if (k >= o->grid->n) break;
        m = 0;
        while (1) {
            if (m >= o->grid->cnt[k]) break;
            n = &o->grid->lv[k][m];
            vcopy(&n->prev, &n->cur);
            if (n->link >= 0) {
                func_800AC5CC(&o->links[n->link], o->xf, &t, 1);
                func_800AD2A8(&t, n, &n->cur, 1);
                if (n->type == 4) {
                    func_800AD2A8(&o->links[n->link], n->b, n->a, 0);
                }
            } else {
                func_800AD2A8(o->xf, n, &n->cur, 1);
                if (n->type == 4) {
                    func_800AD2A8(o->xf, n->b, n->a, 0);
                }
            }
            m++;
        }
        k++;
    }
    o->grid->last = o->grid->now;
    o->grid->now = D_800F2744;
}
