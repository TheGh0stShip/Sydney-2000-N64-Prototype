extern unsigned char D_80077C80[];
extern unsigned char D_80077A30[];
extern void func_800AF064(void *object, int mode);

void func_800AEC0C(void)
{
    func_800AF064(D_80077C80, 2);
    func_800AF064(D_80077A30, 2);
}
