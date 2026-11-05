extern void func_8009BD50(int id);
extern void func_800834F4(void *object);
extern void func_8009D8F0(void *object);
extern void func_80073498(void *object);
extern void func_800AC334(void *object);
extern void func_800BBD78(void *table, int a, int b, void *object, int c);
extern void func_800D771C(void *object);
extern unsigned char D_800F2AD8[];
extern int D_800F2728;

void func_80079584(unsigned char *object)
{
    unsigned char *hi;
    unsigned char *table;
    int mode;

    func_8009BD50(object[1556]);
    func_800834F4(object + 1584);
    func_8009D8F0(object + 3660);
    hi = object + 0x10000;
    if (hi[2841] >= 2) {
        func_800834F4(object + 28608);
        func_8009D8F0(object + 30684);
    }
    func_80073498(object);
    func_800AC334(object + 0x10A2C);
    table = D_800F2AD8;
    mode = 2;
    func_800BBD78(table, 12, 1, object, mode);
    func_800BBD78(table, 13, 1, object, mode);
    D_800F2728 = 0;
    *(int *)(hi + 2824) = -7680;
    *(int *)(object + 172) = 0;
    *(int *)(hi + 2832) = 0;
    object[1556] = object[1557];
    func_800D771C(object + 0xD954);
}
