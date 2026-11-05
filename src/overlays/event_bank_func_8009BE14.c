extern void func_800CEE04(void *object);
extern void func_80097504(void *object);

void func_8009BE14(unsigned char *object)
{
    *(int *)(object + 0x807C) = 1;
    func_800CEE04(object + 14548);
    func_80097504(object + 15860);
}
