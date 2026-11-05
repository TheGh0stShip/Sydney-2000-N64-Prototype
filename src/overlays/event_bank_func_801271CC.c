extern void func_8008397C(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);
extern void func_800A9C2C(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800BA1B4(void *object, int flags);
extern char D_800813D0[];
extern char D_80086598[];
extern char D_80081448[];

void func_801271CC(unsigned char *object, int flags)
{
    unsigned char *sub;

    *(void **)(object + 180) = D_800813D0;
    func_8008397C(object + 2076, 2);
    func_800AC3A4(object + 1860, 2);
    func_800AC3A4(object + 1668, 2);
    func_800AC3A4(object + 1480, 2);
    func_800AC3A4(object + 1292, 2);
    func_800A9C2C(object + 1048, 2);
    sub = object + 808;
    *(void **)(sub + 180) = D_80086598;
    func_800ADDA4(sub, 2);
    *(void **)(object + 180) = D_80081448;
    func_800BA1B4(object, flags);
}
