extern void func_800AE4FC(void *object);

void func_800B4F94(unsigned char *object)
{
    func_800AE4FC(object);
    *(int *)(object + 236) = 4;
    *(int *)(object + 240) = 4;
    *(int *)(object + 192) = 0;
}
