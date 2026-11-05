extern void func_800AC3A4(void *object);
extern unsigned char D_80085FC8[];

void func_800AE4D8(unsigned char *object)
{
    *(void **)(object + 180) = D_80085FC8;
    func_800AC3A4(object);
}
