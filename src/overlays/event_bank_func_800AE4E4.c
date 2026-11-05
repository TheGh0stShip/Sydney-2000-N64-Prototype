extern char *D_800FC270;
extern int D_800F2C14;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int a, int b);

void func_800AE4E4(char *self)
{
    unsigned char s = *(unsigned char *)(self + 0x811E);

    if (s != 0 && s != 5 && s != 1) {
        return;
    }
    if (*(unsigned char *)(self + 0x811E) != 5) {
        if (*(int *)(D_800FC270 + 2564) != 0) {
            func_800C0110(D_800F3BC0, 474, 0, 3840);
        }
    } else {
        D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
        if (*(int *)(D_800FC270 + 2564) != 0) {
            func_800C0110(D_800F3BC0, 479, 0, 0);
        }
    }
}
