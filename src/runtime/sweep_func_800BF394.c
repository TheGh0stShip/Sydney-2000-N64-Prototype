extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800BF394(unsigned char *object)
{
    int *a;
    int *b;
    int *c;

    func_800AE4FC(object);
    *(int *)(object + 236) = 5;
    *(int *)(object + 240) = 5;
    a = (int *)(object + 408);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    b = (int *)(object + 424);
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    c = (int *)(object + 436);
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    *(int *)(object + 376) = 0;
    object[380] = 0;
    object[381] = 3;
    object[382] = 0;
    *(int *)(object + 384) = 0;
    func_800AED04(object + 292);
    object[383] = 0;
    object[481] = 0;
    object[480] = 0;
    *(float *)(object + 248) = 0.8f;
}
