extern void func_8007F1A4(void *object, int mode);
extern void func_800A9C2C(void *object, int mode);
extern void func_800AF064(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800AC3A4(void *object, void *value);
extern void func_800BA1B4(void *object, int mode);
extern void func_800AE4D8(void *object, int mode);
extern void func_800A86AC(void *object, int mode);

void func_80075754(unsigned char *object, void *value)
{
    func_8007F1A4(object + 4904, 2);
    func_800A9C2C(object + 4660, 2);
    func_800AF064(object + 4644, 2);
    func_800AF064(object + 4628, 2);
    func_800ADE84(object + 4416, 2);
    func_800ADE84(object + 4204, 2);
    func_800ADE84(object + 3992, 2);
    func_800ADE84(object + 3780, 2);
    func_800ADE84(object + 3568, 2);
    func_800ADE84(object + 3356, 2);
    func_800AC3A4(object + 3168, (void *)2);
    func_800BA1B4(object + 2764, 2);
    func_800BA1B4(object + 2360, 2);
    func_800BA1B4(object + 1956, 2);
    func_800AE4D8(object + 868, 2);
    func_800A86AC(object + 500, 2);
    func_800ADE84(object + 284, 2);
    func_800AC3A4(object, value);
}
