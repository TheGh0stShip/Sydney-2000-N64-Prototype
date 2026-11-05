typedef void (*Destructor)(void *object);

extern void func_800ADB70(void *object);
extern void func_8001786C(void *resource);
extern void func_800BAC24(void);
extern void func_800BA0EC(void *object);

void func_800C8500(unsigned char *object)
{
    unsigned char *descriptor = *(unsigned char **)(object + 180);
    short offset = *(short *)(descriptor + 24);
    Destructor destroy = *(Destructor *)(descriptor + 28);
    destroy(object + offset);
    descriptor = *(unsigned char **)(object + 180);
    offset = *(short *)(descriptor + 72);
    destroy = *(Destructor *)(descriptor + 76);
    destroy(object + offset);
    func_800ADB70(object);
    func_8001786C(*(void **)(object + 748));
    *(void **)(object + 748) = 0;
    func_800BAC24();
    *(int *)(object + 740) = 0;
    *(int *)(object + 744) = 0;
    func_800BA0EC(object);
}
