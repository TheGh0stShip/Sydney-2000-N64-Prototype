extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800B60E0(unsigned char *object)
{
    int *v;
    func_800AE4FC(object);
    *(int *)(object + 236) = 3;
    *(int *)(object + 240) = 0;
    v = (int *)(object + 280);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    *(int *)(object + 388) = 0;
    func_800AED04(object + 292);
    *(int *)(object + 192) = 0;
}
