extern void func_800E5FC0(void *object, int a, int b);
extern void func_800ADC54(void *object, int mode);
extern void func_800E7828(void *object, int a, int b, int c);

void func_800E79E0(unsigned char *object, unsigned char kind)
{
    unsigned char *vt;

    func_800E5FC0(object, 2500, 3750);
    *(int *)(object + 0) = 80;
    func_800ADC54(object, 1);
    vt = *(unsigned char **)(object + 180);
    (*(void (**)(void *, void *))(vt + 20))(object + *(short *)(vt + 16), object);
    vt = *(unsigned char **)(object + 180);
    (*(void (**)(void *))(vt + 68))(object + *(short *)(vt + 64));
    func_800E7828(object + 220, 2500, 3750, kind);
}
