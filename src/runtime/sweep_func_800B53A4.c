extern void func_800AE4FC(void *object);

void func_800B53A4(unsigned char *object)
{
    func_800AE4FC(object);
    *(int *)(object + 236) = 4;
    *(int *)(object + 240) = 2;
    *(int *)(object + 376) = 0;
    *(int *)(object + 192) = 0;
    *(float *)(object + 412) = 1.0f;
}
