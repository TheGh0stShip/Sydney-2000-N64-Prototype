extern void func_800BA1B4(void *object, int mode);
extern unsigned char D_80070DA0[];

void func_80079850(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80070DA0;
    func_800BA1B4(object, mode);
}
