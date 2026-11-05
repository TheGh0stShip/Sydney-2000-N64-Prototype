typedef void (*Destructor)(void *object);
extern void func_8001A248(void *slot);

void func_800C0A5C(unsigned char *object)
{
    if (*(void **)(object + 196) != 0) {
        unsigned char *descriptor = *(unsigned char **)(object + 180);
        short offset = *(short *)(descriptor + 24);
        Destructor destroy = *(Destructor *)(descriptor + 28);
        destroy(object + offset);
        func_8001A248(object + 196);
        *(void **)(object + 196) = 0;
    }
}
