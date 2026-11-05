void func_800C38A8(unsigned char *object)
{
    unsigned char *state = *(unsigned char **)(*(unsigned char **)(object + 220) + 28);
    unsigned int counter;

    if (*(void **)(object + 712) != 0) {
        counter = ++*(unsigned int *)(object + 780);
        if (*(int *)(state + 12) != 0) {
            if (counter >= 9) {
                *(int *)(*(unsigned char **)(object + 712) + 192) ^= 4;
                *(int *)(object + 780) = 0;
            }
        } else {
            *(int *)(*(unsigned char **)(object + 712) + 192) |= 4;
        }
    }
}
