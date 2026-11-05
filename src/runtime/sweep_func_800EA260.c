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
    int pad;
    unsigned int nSlots;
    Slot *slots;
} Pool;

void func_800EA260(Pool *p)
{
    unsigned int i;
    Slot *s;
    unsigned int off;

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
}
