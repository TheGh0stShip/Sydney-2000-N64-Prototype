extern unsigned char *D_800FCC74;
extern unsigned char *D_800FC270;

int func_800DE464(void)
{
    unsigned char *target = *(unsigned char **)(D_800FCC74 + 32);
    int found = 0;
    unsigned char i;

    if (target != 0) {
        int id = *(int *)(target + 688);

        for (i = 0; i < 8; i++) {
            if (*(signed char *)(D_800FC270 + i + 500) == id) {
                found = 1;
            }
        }
    }
    return found;
}
