extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *a, int b, int c, int d);

void func_8009A76C(unsigned char *state)
{
    unsigned char *cfg;
    unsigned char kind = state[0x8054];
    int mode;
    int sel;

    if (kind != 0 && kind != 5 && kind != 1) {
        return;
    }
    cfg = D_800FC270;
    mode = *(int *)(cfg + 2560);
    if (mode < 0) {
        return;
    }
    if (mode >= 3 && mode != 5) {
        return;
    }
    if (state[0x8054] != 5) {
        return;
    }
    sel = *(int *)(*(unsigned char **)(state + 12136) + 776);
    switch (sel) {
    case 0:
        if (*(int *)(cfg + 2564) != 0) {
            func_800C0110(D_800F3BC0, 168, 0, 7680);
        }
        break;
    case 2:
        if (*(int *)(cfg + 2564) != 0) {
            func_800C0110(D_800F3BC0, 167, 0, 7680);
        }
        break;
    }
}
