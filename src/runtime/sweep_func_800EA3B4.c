typedef struct {
    short used;
    char pad[62];
} Node;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned int nNodes;
    Node *nodes;
    int unkC;
} Pool;

extern char D_800F2758[];
extern void func_8008C120(void);
extern void func_800AA804(void *, void *, unsigned int, void (*)(void));

static __inline__ void pool_clear(Pool *p)
{
    p->nNodes = 0;
    p->nodes = 0;
    p->a = 0;
    p->unkC = 0;
    p->b = 0;
}

void func_800EA3B4(Pool *p, unsigned int n)
{
    unsigned int i;

    pool_clear(p);
    p->nNodes = n;
    func_800AA804(D_800F2758, &p->nodes, n << 6, func_8008C120);
    if (p->nodes != 0) {
        p->a = 0;
        p->b = 0;
        for (i = 0; i < p->nNodes; i++) {
            p->nodes[i].used = 0;
        }
    }
}
