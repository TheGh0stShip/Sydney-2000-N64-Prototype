extern void func_800AE4FC(void *object);

void func_800B57D0(unsigned char *object)
{
    int *v;
    func_800AE4FC(object);
    *(int *)(object + 236) = 4;
    *(int *)(object + 240) = 1;
    v = (int *)(object + 376);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    *(int *)(object + 192) = 0;
}
