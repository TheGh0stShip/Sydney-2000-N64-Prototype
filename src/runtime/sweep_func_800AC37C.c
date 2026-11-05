int func_800AC37C(unsigned char *list, unsigned char *entry)
{
    if (*(void **)(list + 4) != 0) {
        return 0;
    }
    *(void **)(list + 4) = entry;
    *(void **)(list + 12) = *(void **)(entry + 8);
    *(void **)(entry + 8) = list;
    return 1;
}
