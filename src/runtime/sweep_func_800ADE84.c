extern void func_800ADC1C(void *object);
extern void func_800ADB70(void *object);
extern void func_800AC3A4(void *object, int flags);
extern unsigned char D_80085F48[];

void func_800ADE84(unsigned char *object, int flags)
{
    *(void **)(object + 180) = D_80085F48;
    func_800ADC1C(object);
    func_800ADB70(object);
    func_800AC3A4(object, flags);
}
