extern unsigned char D_80077660[];

void func_800B636C(unsigned char *object, unsigned char **first,
                   unsigned char **second, unsigned char *value)
{
    *first = object + 0x5330;
    *second = object + 0x5464;
    *value = D_80077660[object[0x5B7B] + object[0x5B78] * 4];
}
