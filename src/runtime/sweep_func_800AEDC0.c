typedef struct { int cap; int n; int type; char **pts; int f10; int f14; float total; } Curve;
typedef struct { int count; Curve *curves; int *hdr; int src; } Holder;

extern char D_800F2758[];
extern int func_80005A3C(int src, char **cur, char *pool, int f);
extern void func_800AA804(char *pool, void *slot, int size, char *name);

static inline void curve_init(Curve *c, int cnt)
{
    c->cap = cnt;
    c->n = 0;
    c->type = 0;
    c->pts = 0;
    c->total = 0.0f;
    c->f10 = 0;
    func_800AA804(D_800F2758, &c->pts, c->cap * 4, "CUR_PNT");
}

static inline void curve_add(Curve *c, char *p)
{
    if (c->n != c->cap) {
        c->pts[c->n] = p;
        c->total += *(float *)p;
        c->n++;
    }
}

void func_800AEDC0(Holder *h, int src)
{
    char *cur;
    int i;
    int j;
    int type;
    int cnt;

    cur = 0;
    h->count = 0;
    h->curves = 0;
    h->hdr = 0;
    h->src = src;
    if (func_80005A3C(src, &cur, D_800F2758, 1) == 0) {
        return;
    }
    h->hdr = (int *)cur;
    cur += 4;
    h->count = *(int *)cur;
    cur += 4;
    func_800AA804(D_800F2758, &h->curves, h->count * sizeof(Curve), "CUR_HLD");
    i = 0;
    while (1) {
        if (i >= h->count) break;
        type = *(int *)cur;
        cur += 4;
        cnt = *(int *)cur;
        cur += 4;
        curve_init(&h->curves[i], cnt);
        if (type == 1) {
            h->curves[i].type = type;
        }
        j = 0;
        while (1) {
            if (j >= cnt) break;
            curve_add(&h->curves[i], cur);
            cur += 52;
            j++;
        }
        i++;
    }
}
