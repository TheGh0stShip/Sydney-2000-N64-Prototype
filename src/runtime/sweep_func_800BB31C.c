extern void func_800AE4FC(void *object);

void func_800BB31C(unsigned char *object)
{
    func_800AE4FC(object);
    *(int *)(object + 236) = 1;
    *(int *)(object + 240) = 2;
    *(int *)(object + 376) = 0;
    *(int *)(object + 380) = 0;
    *(int *)(object + 192) = 0;
    *(float *)(object + 428) = 1.0f;
}
