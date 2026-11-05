extern void func_800811F4(void *p);

void func_800A0B14(char *self)
{
    int i = 0;
    int k;
    char *entry;

next:
    k = i & 0xff;
    if (k < *(unsigned int *)(self + 18060)) {
        i++;
        entry = *(char **)(self + 18056) + k * 760;
        func_800811F4(entry + 212);
        func_800811F4(entry + 472);
        goto next;
    }
}
