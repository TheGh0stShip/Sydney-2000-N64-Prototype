extern void func_800AE4D8(void *object, int flags);
extern void func_800AC3A4(void *object, int flags);
extern unsigned char D_80086B30[];

void func_800B70D8(unsigned char *object, int flags)
{
    *(void **)(object + 180) = D_80086B30;
    func_800AE4D8(object + 260, 2);
    func_800AC3A4(object, flags);
}
