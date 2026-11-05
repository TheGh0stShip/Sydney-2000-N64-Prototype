extern unsigned char D_800FFD30[];

void func_800EA520(unsigned char *object)
{
    unsigned char *vt = *(unsigned char **)(object + 180);

    *(int *)(object + 184) = 0;
    *(int *)(object + 188) = 0;
    *(int *)(object + 0) = 58;
    (*(void (**)(void *, void *))(vt + 20))(object + *(short *)(vt + 16), D_800FFD30);
}
