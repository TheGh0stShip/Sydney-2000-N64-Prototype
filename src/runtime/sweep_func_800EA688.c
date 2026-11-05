extern unsigned char D_8008C140;
extern void func_800AC3A4(void *object);

void func_800EA688(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C140;
    func_800AC3A4(object);
}
