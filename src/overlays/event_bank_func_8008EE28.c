extern const float D_800714D0;
extern const float D_800714D4;

unsigned char *func_8008EE28(unsigned char *object, float amount)
{
    unsigned char *base;
    float value = amount - D_800714D0;

    if (value < 0.0f) {
        value = 0.0f;
    }
    base = object + 0x8000;
    *(float *)(base + 0x780) = value * D_800714D4;
    return base;
}
