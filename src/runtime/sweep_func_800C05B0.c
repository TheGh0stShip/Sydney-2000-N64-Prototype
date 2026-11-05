extern int D_800F2770;
extern void func_800C05A8(void *object);
extern void func_800C04DC(void *object);

void func_800C05B0(unsigned char *object, int *event)
{
    switch (event[0]) {
    case 5:
        if (D_800F2770 != 0) {
            func_800C05A8(object);
        }
        break;
    case 7:
        func_800C04DC(object);
        break;
    }
    *(int *)(object + 16) = event[1];
}
