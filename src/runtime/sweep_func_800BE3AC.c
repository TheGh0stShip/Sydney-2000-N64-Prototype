typedef struct { char pad[36]; unsigned char type; char pad25[72 - 37]; } Node;
typedef struct { unsigned char n; char pad1; unsigned short cnt[3]; Node *lv[4]; } Grid;
typedef struct { char p[40]; } Res;
typedef struct { char pad[0xD0]; Grid *grid; } Obj;

extern int func_800BCEE8(Obj *o, Node *n, int p, float f, Res *r, int q, int s, int z);
extern void func_800BC480(Obj *o, int z, Res *r);

int func_800BE3AC(Obj *o, int p, float f, int q, int s)
{
    Grid *g;
    Res res;
    unsigned char k;
    unsigned short m;
    int hit;
    Node *nd;

    g = o->grid;
    nd = g->lv[0];
    if (func_800BCEE8(o, nd, p, f, &res, q, s, 0) == 0) {
        return 0;
    }
    for (k = 1; k < g->n; k++) {
        hit = 0;
        for (m = 0; m < g->cnt[k]; m++) {
            nd = &g->lv[k][m];
            if (nd->type == 1) {
                if (func_800BCEE8(o, nd, p, f, &res, q, s, 0)) {
                    hit = 1;
                    break;
                }
            }
            if (nd->type == 4) {
                return 0;
            }
        }
        if (!hit) {
            return 0;
        }
    }
    func_800BC480(o, 0, &res);
    return 1;
}
