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

typedef struct Pool {
    unsigned short a;
    unsigned short b;
    unsigned int nNodes;
    Node *nodes;
    struct Pool *next;
    unsigned int nSlots;
    Slot *slots;
} Pool;

typedef struct {
    char pad[184];
    int count;
    Pool *head;
} PoolList;

extern char D_800F2758[];
extern void func_8008C120(void);
extern void func_8008C130(void);
extern void func_800AA804(void *, void *, unsigned int, void (*)(void));

static __inline__ void pool_clear(Pool *p)
{
    p->nodes = 0;
    p->a = 0;
    p->nNodes = 0;
    p->next = 0;
    p->b = 0;
}

static __inline__ void pool_reset_nodes(Pool *p)
{
    unsigned int i;

    if (p->nodes != 0) {
        p->a = 0;
        p->b = 0;
        for (i = 0; i < p->nNodes; i++) {
            p->nodes[i].used = 0;
        }
    }
}

static __inline__ void pool_reset(Pool *p)
{
    unsigned int i;
    unsigned int off;
    Slot *s;

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
    pool_reset_nodes(p);
}

void func_800E9F2C(Pool *p, unsigned int nSlots, unsigned int nNodes, PoolList *list)
{
    p->nSlots = 0;
    p->slots = 0;
    p->nSlots = nSlots;
    func_800AA804(D_800F2758, &p->slots, nSlots * sizeof(Slot), func_8008C130);
    pool_reset(p);
    pool_clear(p);
    p->nNodes = nNodes;
    func_800AA804(D_800F2758, &p->nodes, nNodes * sizeof(Node), func_8008C120);
    pool_reset_nodes(p);
    if (list != 0) {
        p->next = list->head;
        list->head = p;
        list->count++;
    }
}
