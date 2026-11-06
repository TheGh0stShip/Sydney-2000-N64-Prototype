extern char *D_800FC270;

void func_800A0A18(char *self)
{
    unsigned char phase = *(unsigned char *)(self + 24041);

    if (phase < 2) {
        int mode = *(int *)(self + 24104);

        if (mode == 1) {
            if (phase == mode || *(int *)(D_800FC270 + 2560) != 4) {
                *(unsigned char *)(self + 1757) = mode;
                *(int *)(self + 1760) = 0xB400;
            } else {
                *(unsigned char *)(self + 1757) = 0;
                *(int *)(self + 1760) = 0x1C200;
            }
        } else {
            *(unsigned char *)(self + 1757) = 2;
            *(int *)(self + 1760) = 0x5A00;
        }
    } else {
        *(unsigned char *)(self + 1757) = 1;
        *(int *)(self + 1760) = 0xB400;
        if (phase == 2) {
            *(int *)(self + 1760) = 0x16800;
            *(unsigned char *)(self + 1757) = 0;
        }
    }
    *(int *)(self + 1764) = *(int *)(self + 1760);
}
