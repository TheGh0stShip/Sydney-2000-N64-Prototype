typedef struct {
    short h0;
    short h2;
    float f4;
    float f8;
} Ent;

extern char *D_800FC270;

void func_8009A104(char *obj, float f)
{
    signed char *hi = (signed char *)obj + 0x8000;
    Ent *e = (Ent *)(D_800FC270 + 0xA10) + hi[0x51];

    if (hi[0x50] >= 3) {
        (*(float **)(hi + 0x8C))[hi[0x51] * 3 + 0] = (*(float **)(hi + 0x8C))[hi[0x51] * 3 + 1];
        (*(float **)(hi + 0x8C))[hi[0x51] * 3 + 1] = (*(float **)(hi + 0x8C))[hi[0x51] * 3 + 2];
        (*(float **)(hi + 0x8C))[hi[0x51] * 3 + 2] = f;
    } else {
        (*(float **)(hi + 0x8C))[hi[0x51] * 3 + hi[0x50]] = f;
    }
    if (e->f4 < f) {
        e->f4 = f;
    }
    if (0.0f < e->f4) {
        e->h2 = (short)(int)(e->f4 * *(float *)0x80071440) * 15 / 10;
    }
}
