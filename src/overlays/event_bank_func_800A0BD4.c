extern int D_800759F0;
extern int D_80075874;
extern int D_80075884;
extern void func_800D33A0(void *queue, void *message, int count, int timeout);

void func_800A0BD4(char *self, unsigned char value, unsigned char side, int alternate)
{
    int state = *(unsigned char *)(*(char **)(self + 23712) + 426);

    if (state != 1 || *(unsigned char *)(self + 24041) == 5) {
        return;
    }
    if (side == 0) {
        D_800759F0 = value;
        if (alternate == 0) {
            D_80075884 = 625;
        } else {
            D_80075884 = 630;
        }
    } else if (side == state) {
        if (alternate == 0) {
            D_80075884 = 626;
        } else {
            D_80075884 = 627;
        }
    } else {
        D_800759F0 = side;
        if (alternate == 0) {
            D_80075884 = 628;
        } else {
            D_80075884 = 629;
        }
    }
    func_800D33A0(self + 13020, &D_80075874, 1, -1);
}
