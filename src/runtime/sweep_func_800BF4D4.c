extern unsigned char D_80087050[];
extern void func_800AE4D8(void *object);

void func_800BF4D4(unsigned char *object)
{
    *(void **)(object + 180) = D_80087050;
    func_800AE4D8(object);
}
