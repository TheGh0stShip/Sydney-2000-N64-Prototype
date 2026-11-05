typedef struct Node {
    int type;
    int pad;
    struct Node *child;
    struct Node *next;
} Node;

typedef struct Owner {
    char pad[8];
    Node *nodes;
    char pad2[460];
    unsigned char mode;
} Owner;

extern void func_800B32D4(Node *, int);

void func_800DCC58(Owner *owner)
{
    Node *node;
    Node *child;
    int want = 63;

    node = owner->nodes;
outer:
    if (node == 0) {
        return;
    }
    if (node->type == want) {
        func_800B32D4(node, owner->mode);
    }
    child = node->child;
inner:
    if (child != 0) {
        if (child->type == want) {
            func_800B32D4(child, owner->mode);
        }
        child = child->next;
        goto inner;
    }
    node = node->next;
    goto outer;
}
