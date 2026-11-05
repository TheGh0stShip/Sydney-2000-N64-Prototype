unsigned short func_800DCDC8(unsigned char *object)
{
    unsigned char *value = *(unsigned char **)(object + 444);

    if (value != 0) {
        return *(unsigned short *)(value + 14);
    }
    return 0;
}
