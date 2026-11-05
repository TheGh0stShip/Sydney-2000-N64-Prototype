extern void func_800B3AFC(void *destination, int value, int size);

void func_800A30AC(unsigned char *object)
{
    *(int *)(object + 84) = 10;
    *(short *)(object + 88) = 0;
    *(short *)(object + 90) = 0;
    *(int *)(object + 92) = 0;
    *(int *)(object + 40) = 0;
    func_800B3AFC(object + 44, 0, 40);
}
