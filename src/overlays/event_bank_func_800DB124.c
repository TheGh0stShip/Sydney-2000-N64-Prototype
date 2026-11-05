#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern unsigned int D_800F2714;

static __inline__ unsigned int rand_range(unsigned int range)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7fffffff;
    return (D_800F2714 >> 15) * range >> 16;
}

void func_800DB124(char *obj)
{
    unsigned int k = 45;

    k += rand_range(k);
    k &= 0x7e;
    FIELD(obj, 0x6160, int) = k << 8;
}
