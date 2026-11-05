extern void func_800A8C1C(void *object);

void func_800A9BE8(unsigned char *object, unsigned char index)
{
    unsigned char *link = *(unsigned char **)(object + 192);
    *(int *)(object + 236) = 0;
    if (link != 0) {
        *(int *)(link + 296) = 0;
    }
    object[232] = index;
    *(unsigned char **)(object + 188) = *(unsigned char **)(object + 200) + index * 8;
    func_800A8C1C(object);
}
