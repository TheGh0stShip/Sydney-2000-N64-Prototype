extern unsigned char D_800857E0[];
extern void func_800AC3A4(void *object, int mode);

void func_800A6C40(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800857E0;
    func_800AC3A4(object, mode);
}
