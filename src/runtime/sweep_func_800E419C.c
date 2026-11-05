extern unsigned char *D_800FC270;
extern void func_800C79AC(void *object, int a, int b, int c);

void func_800E419C(unsigned char *object, int mode)
{
    func_800C79AC(object + 4032, *(unsigned short *)(D_800FC270 + 2544),
                  *(unsigned short *)(D_800FC270 + 2538), mode);
    func_800C79AC(object + 5796, *(unsigned short *)(D_800FC270 + 2546),
                  *(unsigned short *)(D_800FC270 + 2540), mode);
    func_800C79AC(object + 7560, *(unsigned short *)(D_800FC270 + 2548),
                  *(unsigned short *)(D_800FC270 + 2542), mode);
    func_800C79AC(object + 9324, *(unsigned short *)(D_800FC270 + 2550),
                  *(unsigned short *)(D_800FC270 + 2550), mode);
}
