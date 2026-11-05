extern unsigned int D_800F2714;
extern unsigned int D_801006E0;

void func_8009BEE0(unsigned int range)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    D_801006E0 = ((D_800F2714 >> 15) * range) >> 16;
}
