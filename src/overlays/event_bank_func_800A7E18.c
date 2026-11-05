extern void func_800CEE04(void *object);
extern void func_80097504(void *object);

void func_800A7E18(unsigned char *object)
{
    *(int *)(object + 31948) = 1;
    func_800CEE04(object + 29936);
    func_80097504(object + 13804);
}
