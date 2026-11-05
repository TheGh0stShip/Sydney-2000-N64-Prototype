extern void func_800AE420(void *p, int v);

void func_800D58A8(unsigned char *object)
{
    unsigned char *p = object + 220;

    func_800AE420(p, 0);
    *(float *)(p + 244) = 1.5707964f;
}
