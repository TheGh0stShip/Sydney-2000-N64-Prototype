int func_80095800(unsigned char *object)
{
    signed char index = *(signed char *)(object + 0x75A8);
    int *entries = *(int **)(object + 0x75FC);

    return entries[index * 7 + 3];
}
