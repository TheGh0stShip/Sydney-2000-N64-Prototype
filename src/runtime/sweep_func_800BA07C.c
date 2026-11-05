typedef struct {
    short offset;
    short pad;
    void (*func)(void *);
} MethodEntry;

void func_800BA07C(unsigned char *object, int *event)
{
    MethodEntry *entry;

    if (event[1] > *(int *)(object + 16)) {
        switch (event[0]) {
        case 3:
            break;
        case 5:
            entry = (MethodEntry *)(*(unsigned char **)(object + 180) + 32);
            entry->func(object + entry->offset);
            break;
        }
        event[1] = *(int *)(object + 16);
    }
}
