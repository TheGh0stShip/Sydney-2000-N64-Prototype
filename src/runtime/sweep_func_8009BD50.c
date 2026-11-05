extern int D_800F1774;
extern unsigned char D_800F3BC0[];
extern int func_800B4784(void);
extern void func_800B4794(int enable);
extern void func_8001DA28(int a, int b);
extern void func_800C013C(void *object);

void func_8009BD50(void)
{
    if (func_800B4784() != 0) {
        D_800F1774 = 0;
    } else {
        D_800F1774 = 1;
        func_800B4794(1);
    }
    func_8001DA28(-1, 0);
    func_800C013C(D_800F3BC0);
    if (D_800F1774 != 0) {
        D_800F1774 = 0;
        func_800B4794(0);
    }
}
