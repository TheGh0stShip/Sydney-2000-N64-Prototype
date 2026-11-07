typedef struct Node { int type; int pad[2]; struct Node *next; } Node;
typedef struct { int pad[2]; Node *head; } List;
typedef struct { int pad[6]; int time; } Clock;
extern char D_800F26E0[];
extern Clock D_800F272C;
extern void func_800AB2A4(void *, int, int, Node *, int, int);
static inline int ntype(Node *n, int t) { if (t == 107) return 107; return n->type; }
void func_800AC25C(List *l, int type, int a, int b)
{
    Node *n = l->head;
    Node *next;
    while (1) {
        if (n == 0) break;
        next = n->next;
        if (ntype(n, type) == type) {
            func_800AB2A4(D_800F26E0, D_800F272C.time, a, n, 0, b);
        }
        n = next;
    }
}
