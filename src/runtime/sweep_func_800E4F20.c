extern unsigned char D_8008BC48;
extern void func_800AC3A4(void *object);

void func_800E4F20(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008BC48;
    func_800AC3A4(object);
}
