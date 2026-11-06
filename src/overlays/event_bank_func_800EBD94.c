void func_800EBD94(unsigned char *object, float *value, unsigned char *index,
                   unsigned char **table)
{
    if (value != 0) {
        *value = *(float *)(object + 0x448);
    }
    if (index != 0) {
        *index = object[0x413];
    }
    if (table != 0) {
        *table = *(unsigned char **)(object + 0x350);
    }
}
