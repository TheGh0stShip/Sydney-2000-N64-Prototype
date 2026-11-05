extern void func_800AC5CC(void *a, void *b, void *c, int d);
extern void func_800AD2A8(void *a, void *b, void *c, int d);
extern void func_800AD9E8(void *object);

void func_800ADC5C(unsigned char *object)
{
    unsigned char *target = *(unsigned char **)(object + 4);
    if (target != 0 && *(signed char *)(object + 176) != 0) {
        func_800AC5CC(object + 96, target + 20, object + 20, 1);
        func_800AD2A8(*(unsigned char **)(object + 4) + 20, object + 160, object + 84, 1);
        if (*(int *)(object + 208) != 0) {
            func_800AD9E8(object);
        }
    }
}
