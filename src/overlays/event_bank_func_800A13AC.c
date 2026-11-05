extern unsigned char D_800712C0[];
extern void func_800BA1B4(void *object, int mode);

void func_800A13AC(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800712C0;
    func_800BA1B4(object, mode);
}
