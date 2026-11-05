extern unsigned char D_80086598;
extern void func_800ADDA4(void *object);

void func_800D7100(unsigned char *object)
{
    *(void **)(object + 180) = &D_80086598;
    func_800ADDA4(object);
}
