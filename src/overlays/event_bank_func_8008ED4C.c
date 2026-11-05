extern void func_800AF064(void *object, int mode);
extern unsigned char D_80077700[];
extern unsigned char D_80077410[];

void func_8008ED4C(void)
{
    func_800AF064(D_80077700, 2);
    func_800AF064(D_80077410, 2);
}
