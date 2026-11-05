extern unsigned char D_80085720[];
extern void func_800AC3A4(void *object, int mode);

void func_800A63CC(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80085720;
    func_800AC3A4(object, mode);
}
