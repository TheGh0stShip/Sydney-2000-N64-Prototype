extern unsigned char D_80086DF8[];
extern void func_800AE4D8(void *object);

void func_800BB1F4(unsigned char *object)
{
    *(void **)(object + 180) = D_80086DF8;
    func_800AE4D8(object);
}
