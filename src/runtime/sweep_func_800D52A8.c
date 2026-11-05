extern void func_800D58E0(void);
extern void func_800D29E0(void *object);
extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);
extern void func_8001A248(void *slot);

void func_800D52A8(unsigned char *object)
{
    unsigned char *nested;
    func_800D58E0();
    nested = object + 660;
    func_800D29E0(nested);
    func_800AC334(nested);
    func_800ADC1C(nested);
    *(int *)(object + 652) = 0;
    if (*(void **)(object + 2520) != 0) {
        func_8001A248(object + 2520);
    }
    if (*(void **)(object + 2732) != 0) {
        func_8001A248(object + 2732);
    }
}
