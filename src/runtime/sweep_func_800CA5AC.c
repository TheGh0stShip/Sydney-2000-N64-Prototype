typedef struct {
    short offset;
    short pad;
    void (*func)(void *);
} MethodEntry;

typedef struct {
    unsigned char pad[180];
    unsigned char *methods;
    unsigned char rest[28];
} Child;

typedef struct {
    unsigned char pad[188];
    Child children[20];
} Parent;

void func_800CA5AC(Parent *object)
{
    unsigned char i;
    MethodEntry *entry;

    for (i = 0; i < 20; i++) {
        entry = (MethodEntry *)((object->children + i)->methods + 64);
        entry->func((unsigned char *)&object->children[i] + entry->offset);
    }
    *(int *)((unsigned char *)object + 4616) = 1;
}
