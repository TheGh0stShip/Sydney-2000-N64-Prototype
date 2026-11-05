extern void func_800AE568(void *object);
extern void func_800B4F94(void *object);
extern unsigned char D_80086770[];

void *func_800B51E0(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086770;
    func_800B4F94(object);
    return object;
}
