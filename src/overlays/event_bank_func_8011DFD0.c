extern void func_80080D94();

void func_8011DFD0(unsigned char *object, int *event)
{
    if (((event[1] - *(int *)(object + 16)) >> 8) == 1 && event[0] == 5) {
        func_80080D94();
    }
    *(int *)(object + 16) = event[1];
}
