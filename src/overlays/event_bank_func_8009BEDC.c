extern char *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *queue, int a1, int a2, int a3);

void func_8009BEDC(void *obj, int a1, int a2, int a3)
{
    if (*(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0, a1, a2, a3);
    }
}
