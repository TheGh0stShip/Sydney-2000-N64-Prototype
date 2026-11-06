extern unsigned int D_800F13F0;

void func_800E2564(unsigned char *object)
{
    unsigned int seed;
    int value;
    int product;
    int base = 45;

    seed = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    value = (int)(seed >> 15);
    product = value * base;
    D_800F13F0 = seed;
    base = (int)((unsigned int)product >> 16) + base;
    base &= 0x7E;
    *(unsigned int *)(object + 0x62C0) = base << 8;
}
