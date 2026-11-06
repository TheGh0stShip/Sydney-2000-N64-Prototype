extern unsigned int D_800F13F0;

void func_8007951C(unsigned char *object)
{
    register int mask __asm__("$8") = 0x7FFFFFFF;
    unsigned int seed;
    int value;
    int product;
    int result;
    register unsigned int base __asm__("$7") = 45;

    seed = (D_800F13F0 * 16807) & mask;
    value = (int)(seed >> 15);
    product = value * base;
    D_800F13F0 = seed;
    object += 0x10000;
    result = (int)((unsigned int)product >> 16) + 60;
    result &= 0x7E;
    *(unsigned int *)(object + 0xB14) = result << 8;
}
