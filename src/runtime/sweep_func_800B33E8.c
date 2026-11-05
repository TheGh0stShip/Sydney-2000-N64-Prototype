int func_800B33E8(float value, unsigned short digits, int *whole, int *frac) {
    int neg;
    int ip;
    int fp;
    int scale;
    unsigned char n;

    scale = 1;
    neg = 0;
    if (value < 0.0f) {
        neg = 1;
    }
    ip = (int)value;
    if (digits == 0) {
        digits = 8;
    }
    value -= (float)ip;
    for (n = digits; n != 0; n--) {
        scale *= 10;
        value *= 10.0f;
    }
    fp = (int)value;
    value -= (float)fp;
    if (value > 0.5f) {
        fp++;
    }
    if (fp >= scale) {
        fp = 0;
        ip++;
    }
    *whole = ip;
    *frac = fp;
    if ((float)fp < 0.0f) {
        *frac = -fp;
    }
    return neg;
}
