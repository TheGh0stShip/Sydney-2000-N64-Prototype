extern unsigned char D_80086EA8[];
extern void func_800AE4D8(void *object);

void func_800BB84C(unsigned char *object)
{
    *(void **)(object + 180) = D_80086EA8;
    func_800AE4D8(object);
}
