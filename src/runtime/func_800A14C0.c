extern unsigned char *D_800F1A44;
extern float D_8007DC94;

void func_800A14C0(unsigned char *object)
{
    register unsigned char *self = object;
    float *source;
    float *target;
    float reset;

    if (self[0x100] < 2) {
        return;
    }
    source = (float *)(D_800F1A44 + 0x490);
    *(float *)(self + 0xE8) = source[0];
    target = (float *)(self + 0xE8);
    target[1] = source[1];
    target[2] = source[2];
    reset = D_8007DC94;
    source = (float *)(self + 0x54);
    *(float *)(self + 0xDC) = source[0];
    object = self + 0xDC;
    ((float *)object)[1] = source[1];
    ((float *)object)[2] = source[2];
    *(float *)(self + 0xF4) = reset;
    *(int *)(self + 0xFC) = 1;
    *(float *)(self + 0xF8) = 0.0f;
}
