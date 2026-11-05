extern char *D_800FC270;
extern int D_800F2C14;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int a, int b);

void func_800AEFB4(char *self)
{
    int sfx;
    unsigned char s = *(unsigned char *)(self + 0x811E);

    if (s != 0 && s != 5 && s != 1) {
        return;
    }
    sfx = 472;
    if (*(unsigned char *)(self + 0x811E) == 5) {
        D_800F2C14 = (D_800F2C14 * 16807) & 0x7FFFFFFF;
        sfx = 493;
    }
    if (sfx >= 0 && *(int *)(D_800FC270 + 2564) != 0) {
        func_800C0110(D_800F3BC0, sfx, 0, 3840);
    }
}
