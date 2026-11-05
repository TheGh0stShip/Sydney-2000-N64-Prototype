extern void func_8001A248(void *slot);

void func_800CCE4C(unsigned char *object)
{
    if (*(void **)(object + 196) != 0) {
        func_8001A248(object + 196);
    }
    *(void **)(object + 196) = 0;
}
