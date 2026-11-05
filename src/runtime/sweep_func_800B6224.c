extern void func_800AE568(void *object);
extern void func_800B60E0(void *object);
extern unsigned char D_80086A40[];

void *func_800B6224(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086A40;
    func_800B60E0(object);
    return object;
}
