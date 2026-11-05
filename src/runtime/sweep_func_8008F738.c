extern unsigned char D_80084048[];
extern unsigned char D_80086598[];
extern void func_800ADE84(void *object, int mode);
extern void func_800ADDA4(void *object, int mode);
extern void func_800AE4D8(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_8008F738(unsigned char *object, int mode)
{
    unsigned char *part;

    *(void **)(object + 180) = D_80084048;
    func_800ADE84(object + 1212, 2);
    part = object + 864;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);
    part = object + 628;
    *(void **)(part + 180) = D_80086598;
    func_800ADDA4(part, 2);
    func_800AE4D8(object + 252, 2);
    func_800AC3A4(object, mode);
}
