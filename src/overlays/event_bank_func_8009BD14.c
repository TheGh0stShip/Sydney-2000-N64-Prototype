extern void func_800AF064(void *object, int mode);
extern unsigned char D_80076F90[];
extern unsigned char D_80076D40[];

void func_8009BD14(void)
{
    func_800AF064(D_80076F90, 2);
    func_800AF064(D_80076D40, 2);
}
