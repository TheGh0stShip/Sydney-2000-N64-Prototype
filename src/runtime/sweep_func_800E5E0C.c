void func_800E5E0C(unsigned char *object)
{
    unsigned int i;
    unsigned char *vt;

    *(int *)(object + 212) = 0;
    *(unsigned int *)(object + 232) |= 0x80;
    for (i = 0; i < *(unsigned int *)(object + 220); i++) {
        *(unsigned int *)(*(unsigned char **)(object + 228) + i * 8 + 4) &= ~1;
    }
    vt = *(unsigned char **)(object + 180);
    (*(void (**)(void *))(vt + 76))(object + *(short *)(vt + 72));
}
