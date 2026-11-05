extern void func_800D3FD0(void *object, int a, int b, int c, int d, int e);

void func_800D577C(unsigned char *object, int a, int b)
{
    *(int *)(object + 656) = 1;
    func_800D3FD0(object, a, b, -1, -1, -1);
    *(void **)(object + 2784) = object + 220;
}
