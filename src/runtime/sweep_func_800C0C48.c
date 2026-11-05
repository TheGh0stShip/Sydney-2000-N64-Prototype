extern void func_8001A1D8(void *target, float span, int flags, float start, float value);

void func_800C0C48(unsigned char *object)
{
    func_8001A1D8(object + 380,
                  *(float *)(object + 408) - *(float *)(object + 404), 0,
                  *(float *)(object + 404), *(float *)(object + 400));
}
