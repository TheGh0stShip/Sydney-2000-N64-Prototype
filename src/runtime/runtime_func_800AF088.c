void func_800AF088(void *object, float *output)
{
    unsigned char *bytes = object;
    void **records = *(void ***)(bytes + 12);
    float *source = (float *)((unsigned char *)records[*(int *)bytes - 1] + 40);

    output[0] = source[0];
    output[1] = source[1];
    output[2] = source[2];
}
