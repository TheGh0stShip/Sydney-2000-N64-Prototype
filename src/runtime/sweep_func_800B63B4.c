extern void func_800AE568(void *object);
extern void func_800AED80(void *object);
extern void func_800B6268(void *object);
extern unsigned char D_80086938[];

void *func_800B63B4(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086938;
    func_800AED80(object + 376);
    func_800B6268(object);
    return object;
}
