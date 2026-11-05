extern void func_800AE4D8(void *object);
extern unsigned char D_80086990[];

void func_800B6804(unsigned char *object)
{
    *(void **)(object + 180) = D_80086990;
    func_800AE4D8(object);
}
