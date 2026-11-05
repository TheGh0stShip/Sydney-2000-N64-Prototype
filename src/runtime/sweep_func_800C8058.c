typedef void (*Destructor)(void *object);

void func_800C8058(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    short offset = *(short *)(descriptor + 24);
    Destructor destroy = *(Destructor *)(descriptor + 28);
    destroy(object + offset);
    *(int *)(object + 196) = 0;
}
