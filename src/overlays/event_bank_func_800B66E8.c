extern unsigned char D_800714B8[];
extern void func_800BA1B4(void *object, int mode);

void func_800B66E8(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800714B8;
    func_800BA1B4(object, mode);
}
