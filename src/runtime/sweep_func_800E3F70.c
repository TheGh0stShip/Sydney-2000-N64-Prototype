extern unsigned char *D_800FC270;

int func_800E3F70(int unused, int value)
{
    unsigned int i;

    for (i = 0; i < 32; i++) {
        if (D_800FC270[i * 4 + 1372] == value) {
            return i;
        }
    }
    return 0;
}
