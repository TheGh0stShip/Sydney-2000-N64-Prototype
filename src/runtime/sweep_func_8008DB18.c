extern short D_800F0E6C[];

int func_8008DB18(int unused, int angle)
{
    int negative = 0;
    int value;

    if (angle < 0) {
        angle = -angle;
        negative = 1;
    }
    if (angle >= 256) {
        angle = 255;
    }
    value = D_800F0E6C[angle];
    if (negative) {
        value = -value;
    }
    return value;
}
