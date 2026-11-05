extern void func_800B31EC(int a);
extern void func_800B360C(void *dst, void *src);
extern int D_80102890;
extern unsigned char D_800F4B98[];

void func_800D2544(unsigned char *object, unsigned short value)
{
    D_80102890 = value;
    func_800B31EC(0);
    func_800B360C(object + 3236, D_800F4B98);
}
