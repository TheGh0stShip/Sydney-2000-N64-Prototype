extern void func_800B9E9C(void *object, int first, int second, int third, int fourth);

void func_800E6A5C(unsigned char *object)
{
    *(short *)(object + 406) = 21;
    *(short *)(object + 408) = 24;
    *(short *)(object + 410) = -1;
    object[404] = 0;
    func_800B9E9C(object, *(short *)(object + 406), -1,
                   *(int *)(object + 608), 0);
    *(float *)(object + 608) = *(float *)(object + 3056);
}
