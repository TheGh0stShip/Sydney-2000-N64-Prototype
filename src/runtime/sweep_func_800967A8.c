extern char D_80086598[];
extern void func_800ADDA4(void *object, int mode);
extern void func_800CE380(void *object, int mode);

#define DESTROY_WITH_VTABLE(o) \
    p = (o); \
    *(void **)(p + 180) = D_80086598; \
    func_800ADDA4(p, 2)

void func_800967A8(char *self, int mode)
{
    char *p;

    DESTROY_WITH_VTABLE(self + 1772);
    DESTROY_WITH_VTABLE(self + 1552);
    DESTROY_WITH_VTABLE(self + 1332);
    DESTROY_WITH_VTABLE(self + 1112);
    func_800CE380(self + 900, 2);
    func_800ADDA4(self + 688, 2);
    func_800ADDA4(self + 476, 2);
    func_800ADDA4(self + 264, 2);
    func_800ADDA4(self, mode);
}
