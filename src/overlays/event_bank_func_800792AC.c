extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int value, int arg2, int arg3);

void func_800792AC(unsigned char *object)
{
    if (object[1556] < 2 && *(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0, 150, 768, 0);
    }
}
