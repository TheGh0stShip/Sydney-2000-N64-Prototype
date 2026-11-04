typedef signed int s32;

s32 func_80027CC0(s32 xmaxc)
{
    s32 exponent = 0;
    s32 mantissa;

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
    return (exponent << 4) | (mantissa & 7);
}
