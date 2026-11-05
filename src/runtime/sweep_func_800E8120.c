extern void func_800E7AE0(void);
extern void func_800ADFAC(void *object);
extern void func_800AE304(void *object);

void func_800E8120(unsigned char *object, int *event)
{
    if ((event[1] - *(int *)(object + 16)) >> 8 != 0) {
        if (event[0] == 5) {
            func_800E7AE0();
        }
        *(int *)(object + 16) = event[1];
        if (*(int *)(object + 296) == 0) {
            if (*(int *)(object + 268) != 0) {
                func_800ADFAC(object);
            }
            if (*(unsigned short *)(object + 196) & 1) {
                func_800AE304(object);
            }
        }
    }
}
