extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *a, int b, int c, int d);

void func_8009BE5C(unsigned char *state, unsigned char *cfg)
{
    int mode = *(int *)(cfg + 2560);

    if (mode < 0) {
        return;
    }
    if (mode >= 3 && mode != 5) {
        return;
    }
    if (state[0x8054] == 5) {
        if (*(int *)(cfg + 2564) != 0) {
            func_800C0110(D_800F3BC0, 216, 0, 0);
        }
    } else {
        if (*(int *)(cfg + 2564) != 0) {
            func_800C0110(D_800F3BC0, 226, 0, 0);
        }
    }
}
