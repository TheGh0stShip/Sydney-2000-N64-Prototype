extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800B6400(unsigned char *object)
{
    func_800AE4FC(object);
    *(int *)(object + 236) = 3;
    *(int *)(object + 240) = 2;
    *(int *)(object + 376) = 0;
    *(int *)(object + 380) = 0;
    *(float *)(object + 428) = 1.0f;
    func_800AED04(object + 292);
    *(int *)(object + 192) = 0;
}
