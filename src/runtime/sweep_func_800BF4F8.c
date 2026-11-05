extern unsigned char D_80087050[];
extern void func_800AE568(void *object);
extern void func_800BF394(void *object);

void *func_800BF4F8(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80087050;
    func_800BF394(object);
    return object;
}
