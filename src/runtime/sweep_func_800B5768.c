extern void func_800AE4D8(void *object);
extern unsigned char D_80086820[];

void func_800B5768(unsigned char *object)
{
    *(void **)(object + 180) = D_80086820;
    func_800AE4D8(object);
}
