extern unsigned char *D_800FC270;

int func_800D6A58(void)
{
    int value = *(int *)(D_800FC270 + 3432) ^ 4095;

    *(int *)(D_800FC270 + 3432) = value;
    if (value == 0) {
        *(int *)(D_800FC270 + 3432) = 1;
    }
    return -1;
}
