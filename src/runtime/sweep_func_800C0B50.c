extern int D_800F2770;
extern void func_800C0AA8(void *object);


void func_800C0B50(unsigned char *object, int *event)
{
    switch (event[0]) {
    case 5:
        if (D_800F2770 != 0) {
            func_800C0AA8(object);
        }
        break;
    case 7:
        *(int *)(object + 172) = 2;
        break;
    }
    *(int *)(object + 16) = event[1];
}
