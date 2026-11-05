typedef struct VEntry {
    short delta;
    short pad;
    void (*func)(char *self, int flags);
} VEntry;

extern char D_80089F28[];
extern char D_80086598[];
extern void func_800ADDA4(char *self, int flags);

void func_800D3460(char *self, int flags)
{
    char *arr;
    char *p;
    char *m;

    *(char **)(self + 0xB4) = D_80089F28;
    arr = self + 0x210;
    if (arr != 0) {
        p = self + 0x560;
        if (arr != p) {
            char *base = arr;
            do {
                VEntry *v;
                p -= 0xD4;
                v = (VEntry *)(*(char **)(p + 0xB4) + 8);
                v->func(p + v->delta, 2);
            } while (base != p);
        }
    }
    m = self + 0xFC;
    *(char **)(m + 0xB4) = D_80086598;
    func_800ADDA4(m, 2);
    func_800ADDA4(self, flags);
}
