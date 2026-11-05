extern unsigned short D_800F26C8;
extern int D_800F26C4;
extern unsigned short D_80100D50[];

void func_800B3178(unsigned short *src, unsigned short count)
{
    unsigned short i;
    D_800F26C8 = count;
    for (i = 0; i < count; i++) {
        D_80100D50[i] = src[i];
    }
    D_800F26C4 = 1;
}
