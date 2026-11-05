extern unsigned int D_800F13F0;
extern void func_800B9E9C(void *obj, int slot, int index, int value, int a);

static __inline__ int func_rand(int range)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return (unsigned int)((D_800F13F0 >> 15) * range) >> 16;
}

void func_80104234(char *obj)
{
    int pick;
    int count;
    short *p;

    *(short *)(obj + 430) = 32;
    *(short *)(obj + 432) = 24;
    pick = func_rand(10);
    count = func_rand((8 - *(unsigned char *)(obj + 1228)) >> 1);
    p = (short *)(obj + 434);
    while (count != 0) {
        if (count != pick) {
            *p = 22;
        } else {
            *p = 51;
        }
        count--;
        p++;
    }
    p[0] = 53;
    p[1] = -1;
    *(unsigned char *)(obj + 429) = 0;
    func_800B9E9C(obj, *(short *)(obj + 430), -1, *(int *)(obj + 632), 0);
    *(float *)(obj + 632) = *(float *)(obj + 788);
}
