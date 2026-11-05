extern void func_8001A248(void *p);

void func_800CC47C(unsigned char *object)
{
    if (*(int *)(object + 212) != 0) {
        func_8001A248(object + 212);
    }
    *(int *)(object + 212) = 0;
}
