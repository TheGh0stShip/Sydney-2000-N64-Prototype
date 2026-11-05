extern void func_800AC3A4(void *object);
extern unsigned char D_80085DB8[];

void func_800AC144(unsigned char *object)
{
    *(void **)(object + 180) = D_80085DB8;
    func_800AC3A4(object);
}
