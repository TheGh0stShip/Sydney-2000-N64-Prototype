extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110();

void func_800792F4(void)
{
    if (*(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0);
    }
}
