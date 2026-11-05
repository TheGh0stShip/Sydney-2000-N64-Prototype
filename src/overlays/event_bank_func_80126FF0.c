int func_80126FF0(unsigned char *object)
{
    unsigned char *state = *(unsigned char **)(object + 0x288);
    if (state[3] & 0x10) {
        return 1;
    }
    return 0;
}
