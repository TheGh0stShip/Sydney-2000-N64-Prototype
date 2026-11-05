typedef struct VtEntry {
    short offset;
    short pad;
    void (*func)(void *, ...);
} VtEntry;

extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);
extern void func_800BB1F4(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_801154F8(char *self, int mode)
{
    char *arr;
    char *p;
    char *q;
    VtEntry *vt;

    func_800ADE84(self + 5192, 2);
    func_800BA1B4(self + 4784, 2);
    q = self + 784;
    if (q != 0) {
        p = self + 784 + 18 * 220;
        if (q != p) {
            arr = q;
            do {
                p -= 220;
                vt = *(VtEntry **)(p + 180);
                vt[1].func(p + vt[1].offset, 2);
            } while (arr != p);
        }
    }
    func_800BB1F4(self + 216, 2);
    func_800AC3A4(self, mode);
}
