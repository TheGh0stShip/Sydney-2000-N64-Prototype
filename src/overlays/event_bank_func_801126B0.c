extern void func_800AD2A8(void *object, int arg, float *out, int flags);
extern void func_800B9480(void *object);

void func_801126B0(unsigned char *object, int arg)
{
    float out[4];

    *(float *)(object + 84) += *(float *)(object + 1260);
    *(float *)(object + 784) += *(float *)(object + 1260);
    if (arg != 0) {
        func_800AD2A8(object + 20, arg, out, 0);
        *(float *)(object + 88) = out[1] + *(float *)(object + 372);
    }
    func_800B9480(object);
}
