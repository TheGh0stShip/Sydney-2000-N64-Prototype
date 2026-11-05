extern unsigned char D_8008C2C0;
extern unsigned char D_8008C300;
extern unsigned char D_8008C140;
extern void func_800AC3A4(void *object);

void func_800EAEB0(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C2C0;
    *(void **)(object + 356) = &D_8008C300;
    *(void **)(object + 328) = &D_8008C300;
    *(void **)(object + 300) = &D_8008C300;
    *(void **)(object + 272) = &D_8008C300;
    *(void **)(object + 244) = &D_8008C300;
    *(void **)(object + 180) = &D_8008C140;
    func_800AC3A4(object);
}
