extern void func_800ADDA4(void *object);
extern unsigned char D_800898F0[];

void func_800CCE84(unsigned char *object)
{
    *(void **)(object + 180) = D_800898F0;
    *(int *)(object + 196) = 0;
    func_800ADDA4(object);
}
