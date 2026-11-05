extern unsigned char D_80078CA0[];
extern void func_800BA1B4(void *object, int mode);

void func_800FE57C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078CA0;
    func_800BA1B4(object, mode);
}
