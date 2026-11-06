extern unsigned int D_800F13F0;

static __inline__ int rand_n(int n)
{
    unsigned int seed = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    D_800F13F0 = seed;
    return (int)(((unsigned int)((int)(seed >> 15) * n)) >> 16);
}

void func_8007951C(unsigned char *object)
{
    int result = (rand_n(45) + 60) & 0x7E;

    *(unsigned int *)(object + 0x10B14) = result << 8;
}
