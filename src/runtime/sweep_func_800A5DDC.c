extern void func_800ADC1C(void *object);
extern void func_800ADC38(void *object);

void func_800A5DDC(unsigned char *object, unsigned char enabled)
{
    object[252] = enabled;
    if (enabled != 0) {
        func_800ADC1C(object + 4572);
        func_800ADC1C(object + 4784);
    } else {
        func_800ADC38(object + 4572);
        func_800ADC38(object + 4784);
    }
}
