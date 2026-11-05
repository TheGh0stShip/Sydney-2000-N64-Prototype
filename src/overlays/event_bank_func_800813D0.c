extern void func_800CFFC4(void *object);
extern void func_800CCB0C(void *object);
extern void func_800D29E0(void *object);

void func_800813D0(unsigned char *object)
{
    unsigned char *sub = object + 21396;
    unsigned char *descriptor = *(unsigned char **)(sub + 180);
    void (*initialize)(void *) = *(void (**)(void *))(descriptor + 28);

    initialize(sub + *(short *)(descriptor + 24));
    sub[176] = 0;
    func_800CFFC4(sub);
    func_800CCB0C(object + 31156);
    func_800D29E0(object + 13200);
}
