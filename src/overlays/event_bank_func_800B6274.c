void func_800B6274(unsigned char *object)
{
    if (object[0x5B99] == 0) {
        object[0x5B99] = 1;
        *(int *)(object + 0x37C) = *(int *)(object + 0x38C);
    }
}
