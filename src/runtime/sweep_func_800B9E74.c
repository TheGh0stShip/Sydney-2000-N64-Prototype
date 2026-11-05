int func_800B9E74(unsigned char *object, unsigned int value)
{
    *(unsigned int *)(object + 324) =
        (*(unsigned int *)(object + 324) & 0x80000000U) | value;
    return 0;
}
