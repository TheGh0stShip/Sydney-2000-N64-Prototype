extern void func_800E7950(void);

void func_800E7A74(unsigned char *object, int *event)
{
    if (event[0] == 5) {
        func_800E7950();
    }
    *(int *)(object + 16) = event[1];
}
