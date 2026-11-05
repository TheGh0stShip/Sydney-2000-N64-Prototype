extern unsigned char D_8008C578;
extern unsigned char D_8008C5C0;
extern unsigned char D_8008C140;
extern void func_800AC3A4(void *object);

void func_800ECA74(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C578;
    *(void **)(object + 268) = &D_8008C5C0;
    *(void **)(object + 240) = &D_8008C5C0;
    *(void **)(object + 180) = &D_8008C140;
    func_800AC3A4(object);
}
