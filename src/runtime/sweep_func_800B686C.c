extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800B686C(unsigned char *object)
{
    int *v;
    func_800AE4FC(object);
    *(int *)(object + 236) = 3;
    *(int *)(object + 240) = 1;
    v = (int *)(object + 376);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    *(int *)(object + 400) = 0;
    func_800AED04(object + 292);
    *(int *)(object + 192) = 0;
}
