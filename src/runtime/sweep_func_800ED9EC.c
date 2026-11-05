extern unsigned char D_8008C680;
extern unsigned char D_8008C6C8;
extern unsigned char D_8008C140;
extern void func_800AC3A4(void *object);

void func_800ED9EC(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C680;
    *(void **)(object + 272) = &D_8008C6C8;
    *(void **)(object + 244) = &D_8008C6C8;
    *(void **)(object + 216) = &D_8008C6C8;
    *(void **)(object + 180) = &D_8008C140;
    func_800AC3A4(object);
}
