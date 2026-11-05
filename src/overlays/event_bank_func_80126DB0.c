extern void func_800A9BE8(void *channel, int sound);

void func_80126DB0(unsigned char *object)
{
    if (object[426] != 4) {
        if (*(int *)(object + 740) == 0) {
            func_800A9BE8(object + 1048, 1);
        } else {
            func_800A9BE8(object + 1048, 14);
        }
    }
}
