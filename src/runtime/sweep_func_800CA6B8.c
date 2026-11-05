typedef struct {
    short offset;
    short pad;
    void (*func)(void *);
} MethodEntry;

extern int D_800F2770;
extern void func_800CA354(void *object);
extern void func_800CA4F0(void *object);

void func_800CA6B8(unsigned char *object, int *event)
{
    MethodEntry *entry;

    if (event[0] == 5) {
        entry = (MethodEntry *)(*(unsigned char **)(object + 180) + 32);
        entry->func(object + entry->offset);
        if (D_800F2770 != 0) {
            func_800CA354(object);
        }
        if (*(int *)(object + 4616) == 1) {
            func_800CA4F0(object);
        }
    }
    *(int *)(object + 16) = event[1];
}
