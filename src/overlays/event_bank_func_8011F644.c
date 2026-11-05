extern void func_80081C70(void *object);

typedef struct {
    short offset;
    short pad;
    void (*func)(void *object, int arg);
} VEntry;

void func_8011F644(unsigned char *object, int arg)
{
    VEntry *entry;

    entry = (VEntry *)(*(unsigned char **)(object + 180) + 24);
    ((void (*)(void *))entry->func)(object + entry->offset);
    entry = (VEntry *)(*(unsigned char **)(object + 180) + 16);
    entry->func(object + entry->offset, arg);
    func_80081C70(object);
}
