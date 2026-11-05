void func_800E7534(unsigned char *table, unsigned char *entry)
{
    table += *(unsigned short *)(entry + 24) * 4;
    *(unsigned char **)(entry + 40) =
        *(unsigned char **)(table + 4) + (*(int *)(entry + 28) * 4 + 20);
}
