extern int D_800F13F0;
extern unsigned short D_8007C0C8;
extern void func_800B9E9C(void *object, int first, int second, int third, int fourth);

void func_800E69B8(unsigned char *object)
{
    *(short *)(object + 406) = 21;
    D_800F13F0 = (D_800F13F0 * 16807) & 0x7FFFFFFF;
    *(short *)(object + 408) = D_8007C0C8;
    object[404] = 0;
    *(short *)(object + 410) = 24;
    *(short *)(object + 412) = 24;
    *(short *)(object + 414) = -1;
    func_800B9E9C(object, *(short *)(object + 406), -1,
                   *(int *)(object + 608), 0);
    *(float *)(object + 608) = *(float *)(object + 3056);
}
