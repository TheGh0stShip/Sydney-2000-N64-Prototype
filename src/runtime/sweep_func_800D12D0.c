#define AT(self, off) ((char *)(self) + (off))

extern int D_80102880;
extern char D_800F4B10[];
extern char D_800F4B28[];
extern void func_800ADC1C(void *);
extern void func_800ADC38(void *);
extern void func_800B31EC(int);
extern void func_800B360C(void *, void *);
extern void func_800B35F0(void *);

void func_800D12D0(void *self, unsigned char mode)
{
    void *right = AT(self, 1772);
    void *left;
    int value;

    value = *(int *)AT(self, 260);
    *(unsigned char *)AT(self, 1992) = mode;
    *(int *)AT(self, 884) = value;
    *(int *)AT(self, 672) = value;
    func_800B35F0(right);
    left = AT(self, 1552);
    func_800B35F0(left);
    func_800B31EC(3);
    switch (mode) {
    case 1:
        func_800ADC1C(AT(self, 476));
        func_800ADC38(AT(self, 688));
        D_80102880 = 1;
        func_800B360C(right, D_800F4B28);
        break;
    case 2:
        func_800ADC1C(AT(self, 688));
        func_800ADC38(AT(self, 476));
        D_80102880 = 1;
        func_800B360C(left, D_800F4B10);
        break;
    case 3:
        func_800ADC38(AT(self, 476));
        func_800ADC38(AT(self, 688));
        D_80102880 = 1;
        func_800B360C(right, D_800F4B28);
        D_80102880 = 2;
        func_800B360C(left, D_800F4B10);
        break;
    case 4:
        func_800ADC38(AT(self, 476));
        func_800ADC38(AT(self, 688));
        D_80102880 = 2;
        func_800B360C(right, D_800F4B28);
        D_80102880 = 1;
        func_800B360C(left, D_800F4B10);
        break;
    }
}
