extern unsigned char D_80088470[];
extern void func_800ADE84(void *object, int mode);
extern void func_800AC3A4(void *object, int arg);

void func_800C0D94(unsigned char *object, int arg)
{
    *(void **)(object + 180) = D_80088470;
    func_800ADE84(object + 184, 2);
    func_800AC3A4(object, arg);
}
