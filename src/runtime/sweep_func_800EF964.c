typedef void (*Callback)(void *object);

void func_800EF964(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    Callback callback = *(Callback *)(descriptor + 76);
    callback(object + *(short *)(descriptor + 72));
}
