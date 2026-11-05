void func_800AF0BC(void *object, float *output)
{
    void **records = *(void ***)((unsigned char *)object + 12);
    float *source = (float *)((unsigned char *)records[0] + 4);

    output[0] = source[0];
    output[1] = source[1];
    output[2] = source[2];
}
