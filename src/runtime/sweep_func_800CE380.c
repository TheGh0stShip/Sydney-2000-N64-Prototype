extern void func_800ADDA4(void *object);
extern unsigned char D_80089AD0[];

void func_800CE380(unsigned char *object)
{
    *(void **)(object + 180) = D_80089AD0;
    *(int *)(object + 196) = 0;
    func_800ADDA4(object);
}
