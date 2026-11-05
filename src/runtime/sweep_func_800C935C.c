extern void func_800ADC38(void *object);

void func_800C935C(unsigned char *object)
{
    unsigned char *nested = object + 1960;
    *(unsigned int *)(nested + 192) |= 0x20;
    func_800ADC38(nested);
    *(short *)(object + 186) = 1;
}
