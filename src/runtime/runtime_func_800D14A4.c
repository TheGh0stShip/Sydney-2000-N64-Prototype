void func_800D14A4(unsigned char *object)
{
    switch (object[0x7C8]) {
    case 1:
    case 3:
        *(int *)(object + 0x374) = *(int *)(object + 0x100);
        break;
    case 2:
    case 4:
        *(int *)(object + 0x2A0) = *(int *)(object + 0x100);
        break;
    }
}
