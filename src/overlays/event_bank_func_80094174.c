extern void func_800AACB0(void *list, void *object, int mode);
extern unsigned char D_800F26E0[];

typedef struct {
    short offset;
    short pad;
    void (*func)();
} VEntry;

void func_80094174(unsigned char *object)
{
    unsigned char *child;
    VEntry *entry;

    if (*(unsigned char **)(object + 23444) != 0) {
        func_800AACB0(D_800F26E0, *(unsigned char **)(object + 23444), 0);
        child = *(unsigned char **)(object + 23444);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 24);
        entry->func(child + entry->offset);
        child = *(unsigned char **)(object + 23444);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 72);
        entry->func(child + entry->offset);
        child = *(unsigned char **)(object + 23444);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 8);
        entry->func(child + entry->offset, 2);
    }
    if (*(unsigned char **)(object + 23680) != 0) {
        func_800AACB0(D_800F26E0, *(unsigned char **)(object + 23680), 0);
        child = *(unsigned char **)(object + 23680);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 24);
        entry->func(child + entry->offset);
        child = *(unsigned char **)(object + 23680);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 72);
        entry->func(child + entry->offset);
        child = *(unsigned char **)(object + 23680);
        entry = (VEntry *)(*(unsigned char **)(child + 180) + 8);
        entry->func(child + entry->offset, 2);
    }
}
