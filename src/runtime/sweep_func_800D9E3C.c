extern unsigned int D_800F2714;

unsigned char func_800D9E3C(unsigned int *mask)
{
    unsigned char start;
    unsigned char i;

    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    start = D_800F2714 >> 26;
    for (i = start; i < 32; i++) {
        if (!(*mask & (1 << i))) {
            *mask |= 1 << i;
            return i;
        }
    }
    for (i = 0; i < start; i++) {
        if (!(*mask & (1 << i))) {
            *mask |= 1 << i;
            return i;
        }
    }
    return 0;
}
