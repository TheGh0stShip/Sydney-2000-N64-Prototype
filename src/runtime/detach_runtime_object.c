typedef struct Node { int pad0; struct Node *parent; struct Node *child; struct Node *next; } Node;
void func_800AC334(Node *n) {
    Node *p = n->parent;
    Node *c;
    if (p != 0) {
        c = p->child;
        if (c == n) {
            p->child = n->next;
        } else {
            Node *prev;
            do { prev = c; c = c->next; } while (c != n);
            prev->next = n->next;
        }
        n->next = 0;
        n->parent = 0;
    }
}
