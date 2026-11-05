extern void func_800ADFAC(void *object);
extern void func_800AE304(void *object);

void func_800ADF40(unsigned char *object, int *event)
{
    int time = event[1];
    if (time >= *(int *)(object + 16)) {
        *(int *)(object + 16) = time;
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
