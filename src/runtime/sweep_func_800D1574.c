extern void func_800B31EC(int a);
extern void func_800B360C(void *dst, void *src);
extern int D_80102880;
extern unsigned char D_800F4AF8[];

void func_800D1574(unsigned char *object, int value)
{
    func_800B31EC(0);
    D_80102880 = value;
    func_800B31EC(3);
    func_800B360C(object + 1332, D_800F4AF8);
}
