extern unsigned char *D_800FC270;
extern float D_80077340[];
extern int D_800F2714;

float func_800DB5D0(int unused, float *range, unsigned char count, float total)
{
    float scale;
    float share;
    float sum;
    float r;
    double d;
    double two32;
    float k0, k1, k2;
    int bits;

    scale = (range[0] + range[1]) * *(float *)0x80071414
            * (D_80077340[D_800FC270[0xD53]] - *(float *)0x80071410) + *(float *)0x80071410;
    share = total / scale;
    sum = 0.0f;
    two32 = *(double *)0x80071418;
    k0 = *(float *)0x80071420;
    k1 = *(float *)0x80071424;
    k2 = *(float *)0x80071428;
    while (1) {
        if (count == 0) {
            break;
        }
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        bits = (unsigned int)D_800F2714 >> 19;
        d = bits;
        if (bits < 0) {
            d += two32;
        }
        r = (float)d * k0;
        if (r < range[2]) {
            r = range[2];
        }
        count--;
        sum += share / (r * k1 + k2);
    }
    return sum;
}
