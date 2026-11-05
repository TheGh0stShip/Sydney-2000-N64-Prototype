extern void func_800AE4D8(void *object);
extern unsigned char D_80086878[];

void func_800B58E4(unsigned char *object)
{
    *(void **)(object + 180) = D_80086878;
    func_800AE4D8(object);
}
