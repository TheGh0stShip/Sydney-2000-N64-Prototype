extern float D_80078C98;

void func_800FE4D8(unsigned char *object, const unsigned char *source)
{
    unsigned char value;

    *(float *)(object + 0x458) = *(const short *)(source + 2);
    *(float *)(object + 0x45C) = *(const short *)(source + 6);
    value = source[1];
    *(float *)(object + 0x460) = value * D_80078C98;
}
