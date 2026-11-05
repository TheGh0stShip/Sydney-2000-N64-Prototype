void func_800C3D20(unsigned char *object)
{
    unsigned char *state = *(unsigned char **)(object + 220);
    unsigned char *target;

    switch ((unsigned int)*(unsigned short *)(state + 6)) {
    case 10:
    case 11:
    case 12:
        target = *(unsigned char **)(object + 716);
        *(int *)(target + 192) |= 4;
        target = *(unsigned char **)(object + 712);
        break;
    case 27:
        target = *(unsigned char **)(object + 720);
        *(int *)(target + 192) |= 4;
        target = *(unsigned char **)(object + 716);
        break;
    default:
        return;
    }
    *(int *)(target + 192) |= 4;
}
