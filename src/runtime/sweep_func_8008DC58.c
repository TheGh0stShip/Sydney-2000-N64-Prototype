extern unsigned char D_80083DD0[];
extern void func_800ADE84(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_8008DC58(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80083DD0;
    func_800ADE84(object + 192, 2);
    func_800AC3A4(object, mode);
}
