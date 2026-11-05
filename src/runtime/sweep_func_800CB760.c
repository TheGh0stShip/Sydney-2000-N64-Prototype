typedef void (*Destructor)(void *object);

void func_800CB760(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    short offset = *(short *)(descriptor + 32);
    Destructor destroy = *(Destructor *)(descriptor + 36);
    destroy(object + offset);
    if (*(int *)(object + 172) == 0) {
        *(float *)(object + 88) = *(float *)(object + 212);
    }
}
