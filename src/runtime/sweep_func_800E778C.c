typedef struct { char p0[6]; unsigned short n; } Hdr;
typedef struct { unsigned char id; unsigned char pad; } Link;
typedef struct { char p0[12]; Link l[4]; } Node;
typedef struct {
    Hdr *hdr; Node *nodes[(1028 - 4) / 4];
    signed char lv[1284 - 1028];
    unsigned char out[256][4];
} Obj;

void func_800E778C(Obj *o)
{
    unsigned int i, k;
    int v, w;
    Link *p;
    i = 0;
    while (1) {
        if (i >= o->hdr->n) break;
        v = o->lv[i];
        if (v >= 0) {
            p = o->nodes[i]->l;
            k = 0;
            while (1) {
                if (k >= 4) break;
                o->out[i][k] = 0;
                if (p->id != 255) {
                    w = o->lv[p->id];
                    if (v < w) o->out[i][k] = 1 << (w - v);
                }
                p++;
                k++;
            }
        }
        i++;
    }
}
