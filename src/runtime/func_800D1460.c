void func_800D1460(unsigned char *object)
{
    int mode = object[0x7C8];

    if (mode == 3) {
        goto mode3;
    }
    if (mode < 4) {
        return;
    }
    if (mode == 4) {
        goto mode4;
    }
    return;
mode3:
    *(int *)(object + 0x2A0) = *(int *)(object + 0x100);
    return;
mode4:
    *(int *)(object + 0x374) = *(int *)(object + 0x100);
}
