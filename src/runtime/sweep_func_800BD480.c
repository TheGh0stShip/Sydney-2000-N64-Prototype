typedef struct { float x, y, z; } Vec;
typedef struct { char pad[36]; unsigned char type; char pad25[72 - 37]; } Node;
typedef struct { unsigned char n; char pad1; unsigned short cnt[3]; Node *lv[4]; } Grid;
typedef struct { char p0[12]; Vec a; char p1[16]; Vec b; char p2[20]; } Seg;
typedef struct { char p[40]; } Res;
typedef struct { char pad[0xD0]; Grid *grid; } Obj;

extern int func_800BC618(Node *n, Seg *s, Res *r, int arg);
extern int func_800BCAEC(Seg *s, Node *n, Res *r, int arg);
extern void func_800BC480(Obj *o, int z, Res *r);

int func_800BD480(Obj *o, Vec *a, Vec *b, int arg)
{
    Grid *g;
    Res res;
    Seg seg;
    unsigned char k;
    unsigned short m;
    int hit;
    Node *nd;

    g = o->grid;
    nd = g->lv[0];
    seg.a.x = a->x;
    seg.a.y = a->y;
    seg.a.z = a->z;
    seg.b.x = b->x;
    seg.b.y = b->y;
    seg.b.z = b->z;
    if (func_800BC618(nd, &seg, &res, arg) == 0) {
        return 0;
    }
    for (k = 1; k < g->n; k++) {
        hit = 0;
        for (m = 0; m < g->cnt[k]; m++) {
            nd = &g->lv[k][m];
            if (nd->type == 1) {
                if (func_800BC618(nd, &seg, &res, arg)) {
                    hit = 1;
                    break;
                }
            }
            if (nd->type == 4) {
                if (func_800BCAEC(&seg, nd, &res, arg)) {
                    hit = 1;
                    break;
                }
            }
        }
        if (!hit) {
            return 0;
        }
    }
    func_800BC480(o, 0, &res);
    return 1;
}
