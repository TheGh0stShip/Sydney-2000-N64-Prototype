extern void func_800AC3A4(void *object);
extern unsigned char D_80085B98[];

void func_800A9C2C(unsigned char *object)
{
    *(void **)(object + 180) = D_80085B98;
    func_800AC3A4(object);
}
