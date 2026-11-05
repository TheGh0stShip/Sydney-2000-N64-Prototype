extern void func_800AF064(void *object, int mode);
extern unsigned char D_80076530[];
extern unsigned char D_80076540[];

void func_80078FAC(void)
{
    func_800AF064(D_80076540, 2);
    func_800AF064(D_80076530, 2);
}
