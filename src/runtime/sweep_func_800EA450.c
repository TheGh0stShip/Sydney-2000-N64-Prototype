extern void func_800EA3B4(void *object);

void *func_800EA450(unsigned char *object, int initialize)
{
    *(void **)(object + 8) = 0;
    *(unsigned short *)(object + 0) = 0;
    *(void **)(object + 4) = 0;
    *(void **)(object + 12) = 0;
    *(unsigned short *)(object + 2) = 0;
    if (initialize != 0) {
        func_800EA3B4(object);
    }
    return object;
}
