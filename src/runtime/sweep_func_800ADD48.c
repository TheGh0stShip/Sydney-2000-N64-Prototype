typedef void (*Method)(void *object);

void func_800ADD48(unsigned char *object, int *event)
{
    unsigned char *vt;
    if (event[0] == 5) {
        vt = *(unsigned char **)(object + 180);
        (*(Method *)(vt + 36))(object + *(short *)(vt + 32));
    }
    *(int *)(object + 16) = event[1];
}
