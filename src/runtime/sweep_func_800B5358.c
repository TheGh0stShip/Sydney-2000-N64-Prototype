extern void func_800AE568(void *object);
extern void func_800AED80(void *object);
extern void func_800B5224(void *object);
extern unsigned char D_800867C8[];

void *func_800B5358(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_800867C8;
    func_800AED80(object + 376);
    func_800B5224(object);
    return object;
}
