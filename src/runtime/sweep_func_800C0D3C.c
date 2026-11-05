extern int D_800F2770;
extern void func_800C0C88(void);

void func_800C0D3C(unsigned char *object, int *event)
{
    if (event[0] == 5 && D_800F2770 != 0) {
        func_800C0C88();
    }
    *(int *)(object + 16) = event[1];
}
