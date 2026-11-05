extern void func_800B3870(void *dst, void *src, int size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *source);
extern void func_800A9B78(void *object, void *source, int a, int b, int c);

void func_8008F194(unsigned char *object, unsigned char *source, int value)
{
    unsigned char *sub;

    func_800B3870(object + 23028, source + 20, 76);
    sub = object + 23008;
    if (*(int *)(sub + 4) != 0) {
        func_800AC334(sub);
    }
    func_800AC37C(sub, source);
    func_800A9B78(object + 0x8264, sub, 1, value, 2);
}
