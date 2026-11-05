extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int value, int a, int b);

void func_800780E0(unsigned char *object, int index)
{
    int value = -1;

    if ((*(int *)(D_800FC270 + 2560) != 5 ||
         object[(index & 0xFF) * 27024 + 2010] == 3) &&
        *(int *)(D_800FC270 + 2564) == 1) {
        value = 288;
    }
    if (*(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0, value, 0, 0);
    }
}
