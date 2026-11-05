typedef void (*Destructor)(void *object);

extern void func_800D29E0(void *object);

void func_800A2158(unsigned char *parent)
{
    unsigned char *object = parent + 964;
    unsigned char *descriptor;
    short offset;
    Destructor destroy;
    func_800D29E0(object);
    descriptor = *(unsigned char **)(object + 180);
    offset = *(short *)(descriptor + 24);
    destroy = *(Destructor *)(descriptor + 28);
    destroy(object + offset);
    object[176] = 0;
}
