extern void func_800E5830(void *object, int a, int b, int c);

void func_8009D9C0(unsigned char *object)
{
    func_800E5830(object, 8, 5, 6);
    *(int *)(object + 212) = 0;
    *(int *)(object + 260) = 0;
}
