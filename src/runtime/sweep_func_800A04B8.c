extern void func_800AD2A8(void *a, void *b, void *c, int d);

void func_800A04B8(unsigned char *object, float value)
{
    *(float *)(object + 212) = value;
    *(float *)(object + 84) = 489.368744f;
    *(float *)(object + 88) = *(float *)(object + 212) - 1.31068003f;
    *(float *)(object + 92) = 1856.57666f;
    func_800AD2A8(*(unsigned char **)(object + 228), object + 216,
                  *(unsigned char **)(object + 228) + 64, 1);
}
