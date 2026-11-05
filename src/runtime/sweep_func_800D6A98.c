extern void func_800DA720(void);
extern unsigned char *D_800FC270;
extern unsigned char D_800FC274;
extern unsigned char D_800FC275;

int func_800D6A98(void)
{
    D_800FC270[3411] = 1;
    D_800FC274 = 1;
    D_800FC275 = 0;
    D_800FC270[3438] = 0;
    func_800DA720();
    *(unsigned short *)(D_800FC270 + 3408) &= 0xff0f;
    return -1;
}
