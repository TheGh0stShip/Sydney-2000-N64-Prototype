extern int func_800B4784(void);
extern void func_800B4794(int);
extern void func_8001D550(void *, int);
extern void func_800C013C(void *);
extern void func_800A3394(void *, int, int, int);
extern void func_800A31BC(void *);
extern int D_800F1774;
extern char D_800F1AE0[];
extern char D_800F3BC0[];
void func_8009BB88(unsigned char mode, int flag)
{
    if (func_800B4784()) {
        D_800F1774 = 0;
    } else {
        D_800F1774 = 1;
        func_800B4794(1);
    }
    if (flag) {
        func_8001D550(D_800F1AE0, 1);
        func_800C013C(D_800F3BC0);
    }
    switch (mode) {
    case 3:
    case 4:
        if (!flag) func_800C013C(D_800F3BC0);
    case 2:
    case 5:
        func_800A3394(D_800F1AE0, 9830, -1, -1);
        func_800A31BC(D_800F1AE0);
        break;
    }
    if (D_800F1774) {
        D_800F1774 = 0;
        func_800B4794(0);
    }
}
