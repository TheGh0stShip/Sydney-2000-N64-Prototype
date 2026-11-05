extern void func_800BA1B4(void *object);
extern unsigned char D_800713D0[];

void func_800887D0(unsigned char *object)
{
    *(void **)(object + 180) = D_800713D0;
    func_800BA1B4(object);
}
