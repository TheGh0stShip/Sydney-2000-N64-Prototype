void func_800A0FB4(unsigned char *object)
{
    unsigned char index = 0;

    *(int *)(object + 0x5E48) = -0x1E00;
    *(int *)(object + 0x5E4C) = -0x1E00;
    *(int *)(object + 0x5E0C) = -0x1E00;
    *(int *)(object + 0x5E28) = 1;
    object[0x5E3D] = (*(unsigned int *)(object + 0x468C) + 1) >> 1;
    do {
        *(int *)((index << 2) + object + 0x5DA4) = 0;
        index++;
    } while (index < 16);
}
