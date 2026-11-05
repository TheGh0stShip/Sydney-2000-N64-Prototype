extern unsigned char D_80103D40[];

unsigned char *func_800EA308(unsigned short *pool, unsigned short kind, int data)
{
    unsigned char *slot = *(unsigned char **)(pool + 4) + pool[0] * 64;

    pool[0]++;
    if (!(pool[0] < *(unsigned int *)(pool + 2))) {
        pool[0] = 0;
    }
    if (*(unsigned short *)slot != 0) {
        slot = D_80103D40;
    } else {
        pool[1]++;
    }
    *(unsigned short *)slot = kind;
    *(int *)(slot + 60) = data;
    return slot;
}
