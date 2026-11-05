typedef struct {
    short offset;
    short pad;
    void (*func)(void *);
} MethodEntry;

typedef struct {
    unsigned char pad[204];
    unsigned char *children[1];
} Group;

extern void func_800ADC38(void *object);

void func_800C9E6C(unsigned char *object)
{
    unsigned char i;
    unsigned char *child;
    MethodEntry *entry;

    func_800ADC38(object + 364);
    for (i = 0; i < object[585]; i++) {
        child = ((Group *)object)->children[i];
        entry = (MethodEntry *)(*(unsigned char **)(child + 180) + 64);
        entry->func(child + entry->offset);
    }
    *(int *)(object + 604) = 1;
    *(int *)(object + 608) |= 3;
}
