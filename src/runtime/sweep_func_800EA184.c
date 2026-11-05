typedef struct {
    char a;
    char b;
    short c;
    char pad[40];
} Slot;

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
    unsigned int nSlots;
    Slot *slots;
} Pool;

extern char D_800F2758[];
extern void func_800AA658(void *, void *);

static __inline__ void pool_clear(Pool *p)
{
    p->nodes = 0;
    p->a = 0;
    p->nNodes = 0;
    p->unkC = 0;
    p->b = 0;
}

void func_800EA184(Pool *p)
{
    unsigned int i;
    unsigned int off;
    Slot *s;

    if (p->nodes != 0) {
        func_800AA658(D_800F2758, &p->nodes);
    }
    pool_clear(p);
    i = 0;
    off = 0;
    while (1) {
        if (!(i < p->nSlots)) {
            break;
        }
        s = (Slot *)(off + (unsigned int)p->slots);
        i++;
        off += sizeof(Slot);
        s->a = 0;
        s->b = 0;
        s->c = 0;
    }
    if (p->nodes != 0) {
        p->a = 0;
        p->b = 0;
        for (i = 0; i < p->nNodes; i++) {
            p->nodes[i].used = 0;
        }
    }
    if (p->slots != 0) {
        func_800AA658(D_800F2758, &p->slots);
    }
}
