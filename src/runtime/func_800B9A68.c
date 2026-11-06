extern float D_80086DA4;
extern float D_80086DA8;
extern float D_80086DAC;
extern float D_80086DB0;

void func_800B9A68(unsigned char *object, int value)
{
    float step = (float)value / D_80086DA4 * D_80086DA8;
    int count = (int)(D_80086DAC / step * D_80086DB0);

    *(int *)(object + 0x13C) = count / 30;
}
