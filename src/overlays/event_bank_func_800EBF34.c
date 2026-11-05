extern void func_8007C994(void *object);

void func_800EBF34(unsigned char *object, unsigned char first, float value,
                   unsigned char second, int third, int fourth)
{
    func_8007C994(object);
    object[840] = first;
    object[852] = second;
    *(int *)(object + 172) = 21;
    *(float *)(object + 844) = value;
    *(int *)(object + 848) = third;
    *(int *)(object + 856) = fourth;
}
