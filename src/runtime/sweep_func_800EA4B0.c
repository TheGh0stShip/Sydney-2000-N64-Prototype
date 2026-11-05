typedef void (*DestroyCallback)(void *object);
extern void func_800EA368(void *entry);

void func_800EA4B0(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    unsigned char *entry = *(unsigned char **)(object + 188);
    DestroyCallback destroy = *(DestroyCallback *)(descriptor + 28);

    destroy(object + *(short *)(descriptor + 24));
    while (entry != 0) {
        unsigned char *next = *(unsigned char **)(entry + 12);
        func_800EA368(entry);
        entry = next;
    }
    *(void **)(object + 184) = 0;
    *(void **)(object + 188) = 0;
    *(int *)object = 58;
}
