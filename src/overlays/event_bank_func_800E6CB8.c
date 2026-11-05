extern unsigned char D_80078BD8[];
extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int mode);

void func_800E6CB8(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078BD8;
    func_800ADE84(object + 2408, 2);
    func_800ADE84(object + 2196, 2);
    func_800ADE84(object + 1984, 2);
    func_800ADE84(object + 1772, 2);
    func_800ADE84(object + 1560, 2);
    func_800ADE84(object + 1348, 2);
    func_800ADE84(object + 1136, 2);
    func_800ADE84(object + 924, 2);
    func_800ADE84(object + 712, 2);
    func_800BA1B4(object, mode);
}
