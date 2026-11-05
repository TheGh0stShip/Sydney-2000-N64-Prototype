typedef struct {
    char pad[13];
    signed char parent;
    char pad2[2];
} Node;

typedef struct {
    short count;
    Node *nodes;
} NodeList;

void func_800B9D2C(char *obj, unsigned short index, unsigned char value)
{
    int i = 0;
    NodeList *list = *(NodeList **)(*(char **)(obj + 196) + 28);

    (*(char **)(obj + 220))[index] = value;
    for (; i < list->count; i++) {
        if (list->nodes[i].parent == index) {
            func_800B9D2C(obj, i, value);
        }
    }
}
