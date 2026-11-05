extern void func_800AD9E8(void *object);

void func_800BCBE0(unsigned char *object, float offset)
{
    unsigned char i;

    for (i = 0; i < *(int *)(object + 17556); i++) {
        unsigned char *slot = object + i * 4;

        *(float *)(*(unsigned char **)(slot + 17148) + 92) = *(float *)(slot + 17472) + offset;
        func_800AD9E8(*(unsigned char **)(slot + 17148));
    }
    *(float *)(object + 17328) = offset;
    func_800AD9E8(object + 17236);
}
