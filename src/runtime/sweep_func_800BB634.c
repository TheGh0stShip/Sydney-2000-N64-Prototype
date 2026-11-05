extern void func_800AE4FC(void *object);

void func_800BB634(unsigned char *object)
{
    int *values;

    func_800AE4FC(object);
    *(int *)(object + 236) = 1;
    *(int *)(object + 240) = 4;
    values = (int *)(object + 376);
    values[0] = 0;
    values[1] = 0;
    values[2] = 0;
    *(int *)(object + 192) = 0;
    *(int *)(object + 388) = 0;
}
