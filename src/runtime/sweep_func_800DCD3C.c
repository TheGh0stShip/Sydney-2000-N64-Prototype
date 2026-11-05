extern void func_800BBD14(void *a, void *b);
extern void func_800DB988(void *object, int arg);
extern void func_800DCC58(void *object);
extern unsigned char D_800F2AD8[];

void func_800DCD3C(unsigned char *object, int value, int arg)
{
    object[473] = 0;
    object[475] = 0;
    func_800BBD14(D_800F2AD8, object + 184);
    func_800DB988(object, arg);
    object[472] = 0;
    func_800DCC58(object);
    object[176] = 1;
    *(int *)(object + 448) = value;
    *(int *)(object + 172) = 0;
    object[478] = 0;
    *(int *)(object + 1548) = 1;
}
