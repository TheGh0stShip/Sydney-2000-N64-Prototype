extern void func_800813AC();

typedef struct {
    short offset;
    short pad;
    void (*func)(void *object);
} VEntry;

void func_8011F84C(unsigned char *object, int *event)
{
    VEntry *entry;

    switch (event[0]) {
    case 3:
        break;
    case 5:
        func_800813AC();
        entry = (VEntry *)(*(unsigned char **)(object + 180) + 32);
        entry->func(object + entry->offset);
        break;
    }
    *(int *)(object + 16) = event[1];
}
