extern void func_800AE4D8(void *object);
extern unsigned char D_80086770[];

void func_800B51BC(unsigned char *object)
{
    *(void **)(object + 180) = D_80086770;
    func_800AE4D8(object);
}
