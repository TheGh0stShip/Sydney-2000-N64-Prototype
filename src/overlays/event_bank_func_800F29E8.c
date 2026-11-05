extern unsigned char D_8007C1F8[];
extern unsigned char D_8007C138[];
extern void func_8009BD10(float value, int first, int second, void *third,
                          void *fourth);
extern void func_800D33A0(void *object, void *data, int first, int second);

void func_800F29E8(unsigned char *object)
{
    unsigned char *state = *(unsigned char **)(object + 4);

    if (state[30123] == 3) {
        int value = *(int *)(state + 29684);

        *(int *)(object + 4352) = value;
        func_8009BD10((float)value, 0, 2, D_8007C1F8, D_8007C1F8 + 4);
        func_800D33A0(object + 812, D_8007C138, 0, -1);
    }
}
