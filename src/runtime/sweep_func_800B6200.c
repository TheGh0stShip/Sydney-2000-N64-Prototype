extern void func_800AE4D8(void *object);
extern unsigned char D_80086A40[];

void func_800B6200(unsigned char *object)
{
    *(void **)(object + 180) = D_80086A40;
    func_800AE4D8(object);
}
