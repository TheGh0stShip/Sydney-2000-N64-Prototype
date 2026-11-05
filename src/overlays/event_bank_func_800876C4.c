extern void func_800BBD78(void *object, int id, int a, void *owner, int b);
extern void func_800BC180(void *object);
extern void func_800D771C(void *object);
extern void func_800A9BE8(void *object, int mode);
extern void func_8009B0E4(int id, int a, void *object, int b, int c, int d, int e);
extern unsigned char D_800F2AD8[];

void func_800876C4(unsigned char *object)
{
    unsigned char *sub;
    int count = object[1550] * object[1555];

    func_800BBD78(D_800F2AD8, 12, 1, object, 2);
    func_800BBD78(D_800F2AD8, 13, 1, object, 2);
    func_800BC180(D_800F2AD8);
    sub = object + 2016;
    func_800D771C(sub);
    object[1551] = 44;
    func_800A9BE8(object + 1116, 9);
    *(int *)(object + 21540) = 0x1C200;
    func_8009B0E4(232, 0, sub, 2, 1, 0, count & 0xff);
}
