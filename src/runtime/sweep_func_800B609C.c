extern void func_800AE568(void *object);
extern void func_800B5E14(void *object);
extern unsigned char D_800868E0[];

void *func_800B609C(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_800868E0;
    func_800B5E14(object);
    return object;
}
