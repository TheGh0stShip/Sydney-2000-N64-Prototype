extern void func_8001457C(void *object);

typedef struct {
    short offset;
    short pad;
    void (*func)(void *object);
} VEntry;

void func_8011F94C(unsigned char *object)
{
    unsigned int i;
    unsigned char *sub;
    VEntry *entry;

    func_8001457C(object);
    for (i = 0; i < *(unsigned short *)(object + 4304); i++) {
        func_8001457C(object + 440 + i * 212);
    }
    sub = object + 3832;
    entry = (VEntry *)(*(unsigned char **)(object + 4012) + 64);
    entry->func(sub + entry->offset);
    sub = object + 4044;
    entry = (VEntry *)(*(unsigned char **)(object + 4224) + 64);
    entry->func(sub + entry->offset);
}
