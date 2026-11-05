extern unsigned char D_80081448[];
extern void func_800BA1B4(void *object, int mode);

void func_801274A8(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80081448;
    func_800BA1B4(object, mode);
}
