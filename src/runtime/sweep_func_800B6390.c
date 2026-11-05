extern void func_800AE4D8(void *object);
extern unsigned char D_80086938[];

void func_800B6390(unsigned char *object)
{
    *(void **)(object + 180) = D_80086938;
    func_800AE4D8(object);
}
