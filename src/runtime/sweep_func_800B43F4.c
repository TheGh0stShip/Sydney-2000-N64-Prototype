extern void func_800AE4D8(void *object);
extern unsigned char D_800866F0[];

void func_800B43F4(unsigned char *object)
{
    *(void **)(object + 180) = D_800866F0;
    func_800AE4D8(object);
}
