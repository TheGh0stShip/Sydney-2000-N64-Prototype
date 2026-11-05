typedef struct VEntry {
    short delta;
    short pad;
    void (*func)(char *self, struct Ctx *ctx);
} VEntry;

typedef struct Node {
    char pad0[8];
    struct Node *child;   /* 0x08 */
    struct Node *next;    /* 0x0C */
    char pad10[0xB1 - 0x10];
    signed char active;   /* 0xB1 */
    char padB2[2];
    char *vtbl;           /* 0xB4 */
} Node;

typedef struct Clock {
    char pad0[0x18];
    int time;             /* 0x18 */
} Clock;

typedef struct Ctx {
    int pad0;
    int time;             /* 0x04 */
    Node *node;           /* 0x08 */
} Ctx;

extern Clock D_800F272C;
extern Ctx D_800F2640;

void func_800AB81C(Clock *a, Node *n)
{
    VEntry *v;
    Node *c;

    D_800F2640.node = n;
    D_800F2640.time = D_800F272C.time;
    v = (VEntry *)(n->vtbl + 0x30);
    v->func((char *)n + v->delta, &D_800F2640);
    c = n->child;
    if (c == 0) {
        return;
    }
    for (;;) {
        if (c == 0) {
            return;
        }
        if (c->active != 0) {
            if (D_800F272C.time > a->time) {
                func_800AB81C(a, c);
            }
        }
        c = c->next;
    }
}
