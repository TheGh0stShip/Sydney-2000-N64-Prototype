extern unsigned char D_80077650[];
extern unsigned char D_80077640[];
extern void func_800AF064(void *object, int mode);

void func_800B614C(void)
{
    func_800AF064(D_80077650, 2);
    func_800AF064(D_80077640, 2);
}
