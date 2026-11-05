extern void func_800A3240(void *object);

void func_800A3298(unsigned char *object, int value)
{
    func_800A3240(object);
    *(int *)(object + 84) = value;
}
