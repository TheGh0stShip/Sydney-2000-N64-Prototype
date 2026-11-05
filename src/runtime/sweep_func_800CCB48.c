extern void func_800CC7EC(void *object, void *state);

void func_800CCB48(void *object, int *state)
{
    if (*state == 5) {
        func_800CC7EC(object, state);
    }
}
