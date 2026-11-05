extern void func_800A63F0(void *object);
extern void func_800ADED4(void *object);
extern void func_8008DCA8(void *object);
extern char D_8007E1E0[];

void *func_80117E08(unsigned char *object)
{
    unsigned int i;

    func_800A63F0(object);
    *(void **)(object + 180) = D_8007E1E0;
    func_800ADED4(object + 480);
    func_800ADED4(object + 740);
    func_8008DCA8(object + 956);
    func_8008DCA8(object + 1436);
    *(int *)(object + 476) = 0;
    for (i = 0; i < 10; i++) {
        ((int *)(object + 436))[i] = 0;
    }
    *(int *)(object + 728) = 0;
    for (i = 0; i < 9; i++) {
        ((int *)(object + 692))[i] = 0;
    }
    return object;
}
