extern void func_800B3870(void *dest, void *src, int size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *source);
extern void func_800A9B78(void *object, void *sub, int first, int second,
                          int third);

void func_800E22F4(unsigned char *object, unsigned char *source, int value)
{
    unsigned char *sub;

    func_800B3870(object + 1380, source + 20, 76);
    sub = object + 1360;
    if (*(int *)(sub + 4) != 0) {
        func_800AC334(sub);
    }
    func_800AC37C(sub, source);
    func_800A9B78(object + 1116, sub, 1, value, 2);
}
