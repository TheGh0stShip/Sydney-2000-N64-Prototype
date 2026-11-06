typedef struct Game {
    char pad0[0xD53];
    unsigned char mode;
} Game;

extern Game *D_800FC270;

int func_800F2920(char *obj)
{
    float sum;
    float scale;
    int base;

    sum = *(float *)(obj + 0x194) * *(float *)0x80078B78
        + *(float *)(obj + 0x198) * *(float *)0x80078B7C;
    switch (D_800FC270->mode) {
    case 0:
        scale = *(float *)0x80078B80;
        base = 160;
        break;
    case 1:
        scale = *(float *)0x80078B84;
        base = 160;
        break;
    case 2:
        scale = *(float *)0x80078B88;
        base = 175;
        break;
    case 3:
        scale = *(float *)0x80078B8C;
        base = 170;
        break;
    default:
        base = 0;
        scale = 0.0f;
        break;
    }
    return base + (int)(scale * sum);
}
