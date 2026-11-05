extern unsigned int D_800F13F0;

static __inline__ unsigned int random_below(unsigned int range)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * range) >> 16;
}

void func_80087B84(unsigned char *object)
{
    unsigned int value = random_below(45);
    *(unsigned int *)(object + 0x5420) = ((value + 60) & 0x7E) << 8;
}
