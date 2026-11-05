void func_800FE480(unsigned char *object)
{
    unsigned char *entry;
    int count;

    *(int *)(object + 0x5AC) = 0;
    entry = object + 0x2E0;
    count = 25;
    do {
        *(int *)(object + 0x5AC) += *entry++;
    } while ((unsigned char)--count != 0);
}
