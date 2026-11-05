extern unsigned char D_8008B1D0;
extern void func_800AC3A4(void *object);

void func_800DEA78(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008B1D0;
    func_800AC3A4(object);
}
