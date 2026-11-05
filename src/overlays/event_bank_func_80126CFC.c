extern void func_800A9BE8(void *channel, int sound);

void func_80126CFC(unsigned char *object)
{
    if (object[426] != 4) {
        if (*(int *)(object + 740) == 0) {
            func_800A9BE8(object + 1048, 24);
        } else {
            func_800A9BE8(object + 1048, 25);
        }
    }
}
