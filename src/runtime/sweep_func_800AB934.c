typedef struct Node {
    int key;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    char pad[20];
    Node *head;
} List;

extern void func_800AB66C(List *list, Node *node);

void func_800AB934(List *list, int key) {
    Node *n = list->head;

    while (n != 0 && n->key != key) {
        n = n->next;
    }
    if (n->key != key) {
        return;
    }
    if (n->prev != 0) {
        n->prev->next = n->next;
    } else {
        list->head = n->next;
    }
    if (n->next != 0) {
        n->next->prev = n->prev;
    }
    func_800AB66C(list, n);
}
