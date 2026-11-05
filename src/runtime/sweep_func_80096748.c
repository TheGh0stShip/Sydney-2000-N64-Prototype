extern unsigned char D_80084258[];
extern void func_800BA1B4(void *object, int mode);

void func_80096748(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084258;
    func_800BA1B4(object, mode);
}
