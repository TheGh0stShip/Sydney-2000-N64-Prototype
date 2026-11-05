void func_800A20C4(void *object, float value)
{
    unsigned char *bytes = object;

    if (value > 0.0f) {
        *(float *)(bytes + 2364) = value;
    }
    *(int *)(bytes + 904) = 1;
}
