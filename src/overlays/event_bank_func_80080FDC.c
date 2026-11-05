extern unsigned char D_800F2758[];
extern int D_8007879C;
extern void func_800AA658(void *list, void *entry);

void func_80080FDC(void)
{
    func_800AA658(D_800F2758, &D_8007879C);
    D_8007879C = 0;
}
