extern void func_800B3870(void *p, int a, int b);
extern void func_800D2B14(void *object, short v);

void func_800D33F8(unsigned char *object, int a, short b, short c)
{
    func_800B3870(object + 212, a, 36);
    *(short *)(object + 248) = 2;
    *(short *)(object + 250) = 376;
    *(short *)(object + 1398) = b;
    func_800D2B14(object, c);
}
