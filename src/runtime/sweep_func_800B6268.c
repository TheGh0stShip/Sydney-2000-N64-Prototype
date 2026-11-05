extern void func_800AE4FC(void *object);
extern void func_800AED04(void *object);

void func_800B6268(unsigned char *object)
{
    func_800AE4FC(object);
    *(int *)(object + 236) = 3;
    *(int *)(object + 240) = 3;
    func_800AED04(object + 376);
    *(int *)(object + 468) = 0;
    func_800AED04(object + 292);
    *(int *)(object + 192) = 0;
}
