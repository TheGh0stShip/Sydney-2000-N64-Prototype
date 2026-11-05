extern void func_800AE568(void *object);
extern void func_800B57D0(void *object);
extern unsigned char D_80086878[];

void *func_800B5908(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086878;
    func_800B57D0(object);
    return object;
}
