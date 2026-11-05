typedef void (*Method)(void *object);

void func_800AC218(unsigned char *object, int *event)
{
    unsigned char *vt;
    switch (*event) {
    case 3:
        break;
    case 5:
        vt = *(unsigned char **)(object + 180);
        (*(Method *)(vt + 36))(object + *(short *)(vt + 32));
        break;
    }
}
