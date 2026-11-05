extern unsigned char *D_800FC270;
extern unsigned char D_800F3BC0[];
extern float D_80076F18[][7];
extern void func_800C0110(void *a, int b, int c, int d);

void func_8009B378(unsigned char *state, float dist)
{
    unsigned char *info = *(unsigned char **)(state + 0x2F68);
    unsigned char *cfg;
    int mode;
    float base;
    float hi;
    float lo;

    if (*(int *)(info + 0x2E8) != 0) {
        cfg = D_800FC270;
        mode = *(int *)(cfg + 0xA00);
        base = D_80076F18[cfg[0xD53]][mode];
        hi = base * *(float *)0x800714E8;
        lo = base * *(float *)0x800714EC;
        if (*(int *)(info + 0x30C) != 0) {
            if (*(int *)(cfg + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x7C, 0, 0);
            }
        } else if (mode == 4 && *(int *)(info + 0x310) != 0) {
            if (*(int *)(cfg + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x232, 0, 0);
            }
        } else if (dist < lo) {
            if (*(int *)(D_800FC270 + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x76, 0, 0);
            }
        } else if (dist < hi) {
            if (*(int *)(D_800FC270 + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x75, 0, 0);
            }
        } else if (dist < base) {
            if (*(int *)(D_800FC270 + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x78, 0, 0);
            }
        } else if (*(int *)(*(unsigned char **)(state + 0x2F68) + 0x314) != 0) {
            if (*(int *)(D_800FC270 + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x77, 0, 0);
            }
        } else {
            if (*(int *)(D_800FC270 + 0xA04) != 0) {
                func_800C0110(D_800F3BC0, 0x78, 0, 0);
            }
        }
    } else {
        if (*(int *)(D_800FC270 + 0xA04) != 0) {
            func_800C0110(D_800F3BC0, 2, 0, 0);
        }
    }
}
