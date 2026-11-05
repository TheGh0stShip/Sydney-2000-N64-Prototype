extern unsigned char *D_800FC270;

int func_800DBA38(unsigned char *object)
{
    unsigned int count = ++object[0x60E];
    unsigned char *state = D_800FC270;

    if ((count & 0xFF) >= state[0xA0C]) {
        if (*(int *)(state + 0xA00) != 5 || (state[0xD52] & 4) != 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}
