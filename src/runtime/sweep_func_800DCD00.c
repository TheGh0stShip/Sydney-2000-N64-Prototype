extern void func_800AC25C(void *object, int type, int count, int flags);

void func_800DCD00(unsigned char *object)
{
    func_800AC25C(object, 107, 7, 0);
    *(short *)(object + 468) = 0;
}
