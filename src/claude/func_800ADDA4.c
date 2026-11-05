extern char D_80085EF8[];
extern char D_80085F48[];
extern void func_800ADC1C(void *obj);
extern void func_800ADB70(void *obj);
extern void func_800AC3A4(void *obj, void *arg);

void func_800ADDA4(char *obj, void *arg1)
{
    *(void **)(obj + 0xB4) = D_80085EF8;
    func_800ADC1C(obj);
    func_800ADB70(obj);
    *(void **)(obj + 0xB4) = D_80085F48;
    func_800ADC1C(obj);
    func_800ADB70(obj);
    func_800AC3A4(obj, arg1);
}
