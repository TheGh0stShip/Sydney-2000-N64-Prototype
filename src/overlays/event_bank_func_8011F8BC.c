extern void func_80014480(void *object);

typedef struct {
    short offset;
    short pad;
    void (*func)(void *object);
} VEntry;

void func_8011F8BC(unsigned char *object)
{
    unsigned int i;
    unsigned char *sub;
    VEntry *entry;

    func_80014480(object);
    for (i = 0; i < *(unsigned short *)(object + 4304); i++) {
        func_80014480(object + 440 + i * 212);
    }
    sub = object + 3832;
    entry = (VEntry *)(*(unsigned char **)(object + 4012) + 72);
    entry->func(sub + entry->offset);
    sub = object + 4044;
    entry = (VEntry *)(*(unsigned char **)(object + 4224) + 72);
    entry->func(sub + entry->offset);
}
