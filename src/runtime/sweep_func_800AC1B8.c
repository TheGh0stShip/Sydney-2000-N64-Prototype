extern void func_800AC5CC(void *a, void *b, void *c, int d);
extern void func_800AD2A8(void *a, void *b, void *c, int d);

void func_800AC1B8(unsigned char *object)
{
    unsigned char *target = *(unsigned char **)(object + 4);
    if (target != 0 && *(signed char *)(object + 176) != 0) {
        func_800AC5CC(object + 96, target + 20, object + 20, 1);
        func_800AD2A8(*(unsigned char **)(object + 4) + 20, object + 160, object + 84, 1);
    }
}
