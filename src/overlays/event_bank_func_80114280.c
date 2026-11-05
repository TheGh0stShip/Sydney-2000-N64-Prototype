typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

extern char D_8007E288[];
extern void func_800ADE84(void *object, int mode);
extern void func_800AE4D8(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_80114280(char *self, int mode)
{
    char *arr;
    char *p;
    char *q;
    VtEntry *vt;

    *(void **)(self + 180) = D_8007E288;
    func_800ADE84(self + 1972, 2);
    q = self + 784;
    if (q != 0) {
        p = self + 784 + 5 * 236;
        if (q != p) {
            arr = q;
            do {
                p -= 236;
                vt = *(VtEntry **)(p + 180);
                vt[1].func(p + vt[1].offset, 2);
            } while (arr != p);
        }
    }
    func_800AE4D8(self + 220, 2);
    func_800AC3A4(self, mode);
}
