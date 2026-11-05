extern void func_800D3054(void *object);

void func_800D334C(unsigned char *object, int *msg)
{
    if (msg[0] == 5 && *(int *)(object + 172) != 5) {
        func_800D3054(object);
    }
    *(int *)(object + 16) = msg[1];
}
