typedef struct {
    unsigned char *info;
    short pad4;
    short value;
    char pad8[84 - 8];
} TrackEntry;

extern char D_80086BB4[];
extern char D_80086BE8[];
extern void func_800AAA60(const char *file, unsigned int line, const char *message);

int func_800B9DD0(unsigned char *self, unsigned short index, short value)
{
    TrackEntry *entry;

    if (index >= *(unsigned int *)(self + 212)) {
        return 1;
    }
    entry = &(*(TrackEntry **)(self + 216))[index];
    if (**(short **)(*(unsigned char **)(self + 196) + 28) + value < *(short *)(entry->info + 24)) {
        func_800AAA60(D_80086BB4, 1137, D_80086BE8);
    }
    entry->value = value;
    return 0;
}
