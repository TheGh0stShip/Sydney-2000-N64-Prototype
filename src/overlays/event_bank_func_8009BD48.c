extern void func_800B3870(void *destination, void *source, int size);
extern void func_800AC334(void *object);
extern void func_800AC37C(void *object, void *source);
extern void func_800A9B78(void *object, void *state, int enabled, int mode,
                          int count);

void func_8009BD48(unsigned char *object, unsigned char *source, int mode)
{
    unsigned char *state;
    float current;
    float minimum;

    func_800B3870(object + 32492, source + 20, 76);
    current = *(float *)(object + 32560);
    minimum = *(float *)0x800715B8;
    if (current < minimum) {
        *(float *)(object + 32560) = minimum;
    }
    state = object + 32472;
    if (*(int *)(state + 4) != 0) {
        func_800AC334(state);
    }
    func_800AC37C(state, source);
    func_800A9B78(object + 32228, state, 1, mode, 2);
}
