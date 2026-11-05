extern void func_800ADDA4(void *object);
extern unsigned char D_800865F0[];

void func_800B3840(unsigned char *object)
{
    *(void **)(object + 180) = D_800865F0;
    func_800ADDA4(object);
}
