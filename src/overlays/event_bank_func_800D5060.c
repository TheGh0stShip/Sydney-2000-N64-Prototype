void func_800D5060(unsigned char *object)
{
    unsigned int index = object[0x4D20];
    unsigned char *entry = object;

    entry += index * 212;
    *(int *)(entry + 0x4640) = *(int *)(object + 0x4578);
    *(int *)(object + 0x4D60) = 1;
    *(short *)(object + 0x4D08) = 0;
    *(short *)(object + 0x4D06) = 0;
    *(short *)(object + 0x4D04) = 0;
    *(int *)(object + 0x4D80) = 0;
    *(int *)(object + 0x4D7C) = 0;
    *(int *)(object + 0x4D74) = 0;
    *(int *)(object + 0x4D70) = 1;
    *(int *)(object + 0x4D10) = *(int *)(object + 0x4CF0);
}
