extern unsigned char *D_800FC270;
extern float D_800778A0[];
extern int D_800F2714;

float func_800DFFA0(int unused, float *range, unsigned char count, float total, unsigned char extra)
{
    float scale;
    float share;
    float sum;
    float r;
    float r2;
    double d;
    double two32;
    float k0, k1, k2;
    double two32b;
    float k3, k4;
    int bits;

    scale = (range[0] + range[1]) * *(float *)0x800712B0
            * (D_800778A0[D_800FC270[0xD53]] - *(float *)0x800712AC) + *(float *)0x800712AC;
    share = total / scale;
    sum = 0.0f;
    two32 = *(double *)0x800712B8;
    k0 = *(float *)0x800712C0;
    k1 = *(float *)0x800712C4;
    k2 = *(float *)0x800712C8;
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
    count = extra;
    two32b = *(double *)0x800712D0;
    k3 = *(float *)0x800712D8;
    k4 = *(float *)0x800712DC;
    while (1) {
        if (count == 0) {
            break;
        }
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        bits = (unsigned int)D_800F2714 >> 19;
        d = bits;
        if (bits < 0) {
            d += two32b;
        }
        r2 = (float)d * k3;
        count--;
        if (range[2] < r2) {
            sum += r2 * k4;
        }
    }
    return sum;
}
