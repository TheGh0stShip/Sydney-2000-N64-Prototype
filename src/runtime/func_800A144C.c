extern unsigned char *D_800F1A44;
extern float D_8007DC94;

void func_800A144C(unsigned char *object, float *position, float duration)
{
    float *source;
    float *target;
    float reset;

    if (object[0x100] < 2) {
        return;
    }
    source = (float *)(D_800F1A44 + 0x490);
    *(float *)(object + 0xE8) = source[0];
    target = (float *)(object + 0xE8);
    target[1] = source[1];
    target[2] = source[2];
    reset = D_8007DC94;
    *(float *)(object + 0xDC) = position[0];
    target = (float *)(object + 0xDC);
    target[1] = position[1];
    target[2] = position[2];
    *(float *)(object + 0xF4) = reset;
    *(int *)(object + 0xFC) = 1;
    *(float *)(object + 0xF8) = duration;
}
