void func_800EA494(unsigned char *container, unsigned char *entry)
{
    *(void **)(entry + 12) = *(void **)(container + 188);
    *(void **)(container + 188) = entry;
    *(int *)(container + 184) += 1;
}
