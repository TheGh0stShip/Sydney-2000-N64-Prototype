extern void func_800AC334(void *object);
extern void func_800ADC1C(void *object);
extern void func_800CEE04(void *object);
extern void func_80076B94(void *object);
extern void func_80097504(void *object);

void func_8008F228(unsigned char *object)
{
    unsigned char *sub = object + 26356;

    *(int *)(object + 0x8000 + 1088) = 1;
    func_800AC334(sub);
    func_800ADC1C(sub);
    func_800CEE04(object + 31844);
    func_80076B94(object);
    func_80097504(object + 26580);
}
