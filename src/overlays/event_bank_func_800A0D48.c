extern int D_800F2728;
extern void func_800A0C8C(char *self);
extern void func_800732AC(char *self, float value);

void func_800A0D48(char *self)
{
    unsigned char *player = *(unsigned char **)(self + 23712);

    if (player != 0) {
        if (player[426] != 1) {
            func_800A0C8C(self);
        } else {
            func_800732AC(self, -1.0f);
        }
    }
    D_800F2728 = 0;
    *(int *)(self + 24068) = -7680;
    self[24124] = 2;
}
