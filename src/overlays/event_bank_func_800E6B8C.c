extern double func_80038550(double value);
extern void func_8007B614(void *object);

void func_800E6B8C(unsigned char *object)
{
    float value = (float)func_80038550((double)*(float *)(object + 796));
    if (value <= *(float *)(object + 2772)) {
        func_8007B614(object);
    }
}
