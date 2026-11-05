typedef struct GameState {
    char pad0[2560];
    int mode;
    int sound;
} GameState;

extern GameState *D_800FC270;
extern unsigned int D_800F2714;
extern char D_800F3BC0[];
extern void func_800C0110(void *bank, int id, int volume, int flags);

void func_800779F0(void)
{
    int first = -1;
    int second = -1;

    if (D_800FC270->mode == 4 && D_800FC270->sound != 5) {
        if (D_800FC270->sound == 1) {
            first = 148;
            second = 229;
        }
    } else {
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        first = 148;
        if (D_800F2714 >> 29) {
            first = 149;
        }
    }
    if (D_800FC270->sound) {
        func_800C0110(D_800F3BC0, first, 3072, 0);
    }
    if (second != -1 && D_800FC270->sound) {
        func_800C0110(D_800F3BC0, second, 18432, 0);
    }
}
