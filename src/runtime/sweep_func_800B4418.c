extern void func_800AE568(void *object);
extern void func_800B4204(void *object);
extern unsigned char D_800866F0[];

void *func_800B4418(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_800866F0;
    func_800B4204(object);
    return object;
}
