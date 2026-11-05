typedef void (*Destructor)(void *object);

extern void func_800ADC1C(void *object);
extern void func_800B35F0(void *object);

void func_800D1500(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    short offset = *(short *)(descriptor + 72);
    Destructor destroy = *(Destructor *)(descriptor + 76);
    destroy(object + offset);
    func_800ADC1C(object + 476);
    func_800ADC1C(object + 688);
    func_800ADC1C(object + 264);
    func_800ADC1C(object + 900);
    func_800B35F0(object + 1112);
    func_800B35F0(object + 1332);
    func_800B35F0(object + 1552);
    func_800B35F0(object + 1772);
}
