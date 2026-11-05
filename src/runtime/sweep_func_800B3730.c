extern void func_800ADDA4(void *object);
extern unsigned char D_80086598[];

void func_800B3730(unsigned char *object)
{
    *(void **)(object + 180) = D_80086598;
    func_800ADDA4(object);
}
