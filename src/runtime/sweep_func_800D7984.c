extern void func_800D78F8(void *object);

void func_800D7984(unsigned char *object, int *msg)
{
    if (msg[0] == 5 && *(int *)(object + 10848) == 1) {
        func_800D78F8(object);
    }
    *(int *)(object + 16) = msg[1];
}
