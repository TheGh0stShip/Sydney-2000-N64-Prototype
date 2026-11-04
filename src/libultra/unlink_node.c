#ifndef LEAF_NAME
#define LEAF_NAME unlinkNode
#endif

typedef struct Node Node;

struct Node {
    Node *previous;
    Node *next;
};

void LEAF_NAME(Node *node) {
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
}
