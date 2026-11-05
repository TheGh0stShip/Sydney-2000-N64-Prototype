extern unsigned int D_800F13F0;
extern unsigned short D_8007C0CC[];
extern void func_800B9E9C(void *object, int first, int second, int third, int fourth);

static inline unsigned int random_below(unsigned int count)
{
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    return ((D_800F13F0 >> 15) * count) >> 16;
}

void func_800E68F4(unsigned char *object)
{
    *(short *)(object + 406) = 21;
    *(short *)(object + 408) = D_8007C0CC[random_below(5)];
    *(short *)(object + 410) = 24;
    *(short *)(object + 412) = 24;
    *(short *)(object + 414) = -1;
    object[404] = 0;
    func_800B9E9C(object, *(short *)(object + 406), -1,
                   *(int *)(object + 608), 0);
    *(float *)(object + 608) = *(float *)(object + 3056);
}
