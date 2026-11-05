extern void func_800AD58C(void *p, float a, float b, float c);

void func_800CB7A8(unsigned char *object, float x, float y)
{
    if (*(int *)(object + 196) != 0) {
        func_800AD58C(object + 96, 0.0f, 1.5707961f, 0.0f);
        *(float *)(object + 160) = 0.0f;
        *(float *)(object + 164) = 0.0f;
        *(float *)(object + 168) = x;
        *(float *)(object + 212) = y;
        *(int *)(object + 172) = 0;
        *(int *)(object + 192) &= ~0x400000;
    }
}
