extern unsigned char D_800F2758[];
extern unsigned char D_800F165C[];
extern int D_800F1660;
extern int D_800F1664;
extern int D_800F1668;
extern void func_800AA658(void *a, void *b);

void func_8009C100(void)
{
    func_800AA658(D_800F2758, D_800F165C);
    D_800F1668 = 0;
    D_800F1664 = 0;
    D_800F1660 = 0;
}
