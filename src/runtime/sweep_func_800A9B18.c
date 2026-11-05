extern void func_800A895C(void *object);

void func_800A9B18(unsigned char *object, int *event)
{
    if (event[0] == 11 && *(int *)(object + 236) == 0 && event[4] == 3) {
        func_800A895C(object);
    }
    *(int *)(object + 16) = event[1];
}
