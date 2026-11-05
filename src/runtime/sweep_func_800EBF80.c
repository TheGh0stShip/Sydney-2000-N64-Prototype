extern unsigned char D_8008C480;
extern unsigned char D_8008C4C0;
extern unsigned char D_8008C140;
extern void func_800AC3A4(void *object);

void func_800EBF80(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C480;
    *(void **)(object + 640) = &D_8008C4C0;
    *(void **)(object + 612) = &D_8008C4C0;
    *(void **)(object + 584) = &D_8008C4C0;
    *(void **)(object + 556) = &D_8008C4C0;
    *(void **)(object + 528) = &D_8008C4C0;
    *(void **)(object + 500) = &D_8008C4C0;
    *(void **)(object + 472) = &D_8008C4C0;
    *(void **)(object + 180) = &D_8008C140;
    func_800AC3A4(object);
}
