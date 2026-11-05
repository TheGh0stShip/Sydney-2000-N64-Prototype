extern unsigned int D_800F13F0;
extern void func_800B9E9C(void *object, int first, int second, int third, int fourth);

static inline unsigned int random_below(unsigned int count)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * count) >> 16;
}

void func_800F5D70(unsigned char *object)
{
    unsigned int marker;
    unsigned int count;
    short *slot;

    *(short *)(object + 430) = 32;
    *(short *)(object + 432) = 21;
    marker = random_below(10);
    count = random_below((8 - object[1228]) >> 1);
    slot = (short *)(object + 434);
    while (count != 0) {
        if (count != marker) {
            *slot = 19;
        } else {
            *slot = 51;
        }
        count--;
        slot++;
    }
    slot[0] = 53;
    slot[1] = -1;
    object[429] = 0;
    func_800B9E9C(object, *(short *)(object + 430), -1,
                   *(int *)(object + 632), 0);
    *(float *)(object + 632) = *(float *)(object + 788);
}
