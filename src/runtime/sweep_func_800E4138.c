extern unsigned char *D_800FC270;

void func_800E4138(int unused, short delta)
{
    int value;
    unsigned char *slot;

    value = *(unsigned short *)(D_800FC270 + 2550) >> 6;
    value += delta;

    if (value < 0) {
        value = 0;
    } else if (value > 1000) {
        value = 1000;
    }
    slot = D_800FC270 + *(unsigned short *)(D_800FC270 + 2524) * 32;
    *(short *)(slot + 854) = value << 6;
    *(short *)(slot + 846) = value << 6;
    *(short *)(slot + 838) = value << 6;
    *(short *)(slot + 830) = value << 6;
    *(short *)(D_800FC270 + 2550) = value << 6;
}
