extern int D_800FF4DC[];
extern int func_800B31F8(void);
extern void func_800B31EC(int mode);
extern void func_800B3208(int value);
extern void func_800B360C(void *dest, void *data);

void func_800E9974(unsigned char *object, int value)
{
    int saved = func_800B31F8();
    int *data = D_800FF4DC;

    data[4] = value;
    func_800B31EC(3);
    func_800B3208(376);
    func_800B360C(object + 27876, data);
    func_800B3208(saved & 0xffff);
}
