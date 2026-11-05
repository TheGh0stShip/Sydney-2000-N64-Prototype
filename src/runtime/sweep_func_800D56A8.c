extern void func_800DC6A4(void *object);

void func_800D56A8(unsigned char *object)
{
    void *nested = *(void **)(object + 2780);
    if (nested != 0) {
        func_800DC6A4(nested);
    }
}
