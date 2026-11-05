extern void func_800C4008(void *object);
extern void func_800AC308(void *object);

void func_800DE424(unsigned char *object)
{
    unsigned char *vt;

    func_800C4008(object);
    func_800AC308(object);
    vt = *(unsigned char **)(object + 180);
    (*(void (**)(void *))(vt + 28))(object + *(short *)(vt + 24));
}
