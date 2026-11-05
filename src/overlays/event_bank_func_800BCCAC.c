void func_800BCCAC(unsigned char *object, float amount)
{
    float value = *(float *)(object + 0x4428) -
                  (amount * *(const float *)0x80070A20) /
                  *(const float *)0x80070A24;

    *(float *)(object + 0x4428) = value;
    *(float *)(object + 0x2574) = value;
}
