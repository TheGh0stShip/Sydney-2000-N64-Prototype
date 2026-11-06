void func_800D2588(unsigned char *object, int *state)
{
    unsigned char flags;
    float value;
    float step;

    if (*state != 5) {
        return;
    }
    flags = object[0x1509];
    if (flags == 0 || (flags & 0x1F) == 0) {
        return;
    }
    if (flags & 1) {
        value = *(float *)(object + 0xA0);
        if (value > 112.0f) {
            step = (value - 112.0f) * 4.0f;
            if (step < 18.0f) {
                step = 18.0f;
            }
            *(float *)(object + 0xA0) = value - step / 30.0f;
            if (*(float *)(object + 0xA0) < 112.0f) {
                *(float *)(object + 0xA0) = 112.0f;
                object[0x1509] &= 0xFE;
            }
        }
    }
    if (object[0x1509] & 0x1E) {
        value = *(float *)(object + 0x678);
        if (value < 10.0f) {
            step = (10.0f - value) * 4.0f;
            if (step < 10.0f) {
                step = 10.0f;
            }
            *(float *)(object + 0x678) = value + step / 30.0f;
            if (*(float *)(object + 0x678) > 10.0f) {
                *(float *)(object + 0x678) = 10.0f;
                object[0x1509] &= 0xE1;
            }
        }
    }
}
