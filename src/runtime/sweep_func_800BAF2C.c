extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800BAF2C(unsigned char *object)
{
    int *values;

    func_800AE4FC(object);
    *(int *)(object + 236) = 2;
    *(int *)(object + 240) = 2;
    *(int *)(object + 376) = 0;
    *(int *)(object + 380) = 0;
    *(int *)(object + 200) = 0;
    values = (int *)(object + 396);
    values[0] = 0;
    *(float *)(object + 460) = 1.0f;
    values[1] = 0;
    values[2] = 0;
    func_800AED04(object + 292);
    *(int *)(object + 192) = 0;
}
