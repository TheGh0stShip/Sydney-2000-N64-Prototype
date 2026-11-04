typedef signed short s16;
typedef signed int s32;

void func_80027CD4(s32 xmaxc, s32 grid, s16 *coded, s16 *output)
{
    s32 exponent;
    s32 mantissa;
    s32 factor;
    s32 shift;
    s32 rounding;
    s32 index;

    exponent = 0;
    if (xmaxc > 15) {
        exponent = (xmaxc >> 3) - 1;
    }
    mantissa = xmaxc - (exponent << 3);
    if (mantissa == 0) {
        exponent = -4;
        mantissa = 7;
    } else {
        while (mantissa <= 7) {
            mantissa = (mantissa << 1) | 1;
            exponent--;
        }
        mantissa -= 8;
    }

    factor = (mantissa << 11) + 0x47FF;
    shift = 6 - exponent;
    rounding = 1 << (shift - 1);
    for (index = 0; index < 13; index++) {
        s32 value = ((s32)coded[index] << 13) - 0x7000;
        value = ((value * factor + 0x4000) >> 15) + rounding;
        coded[index] = value >> shift;
    }
    for (index = 0; index < 40; index++) {
        output[index] = 0;
    }
    for (index = 0; index < 13; index++) {
        output[grid + index * 3] = coded[index];
    }
}
