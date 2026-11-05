void *func_800AEF6C(unsigned char *array, int index)
{
    if (index < 0 || index >= *(int *)array) {
        return 0;
    }
    return *(unsigned char **)(array + 4) + index * 28;
}
