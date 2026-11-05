extern unsigned char D_80100230[];
extern unsigned char D_80100310[];
extern unsigned char D_801003F0[];
extern unsigned char D_801004D0[];
extern void func_800ADE84(void *object, int mode);

void func_8008F6DC(void)
{
    func_800ADE84(D_80100230, 2);
    func_800ADE84(D_80100310, 2);
    func_800ADE84(D_801003F0, 2);
    func_800ADE84(D_801004D0, 2);
}
