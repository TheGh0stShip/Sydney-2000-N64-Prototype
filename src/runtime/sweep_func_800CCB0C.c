typedef void (*Destructor)(void *object);

extern void func_800ADC1C(void *object);

void func_800CCB0C(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    short offset = *(short *)(descriptor + 72);
    Destructor destroy = *(Destructor *)(descriptor + 76);
    destroy(object + offset);
    func_800ADC1C(object + 240);
}
