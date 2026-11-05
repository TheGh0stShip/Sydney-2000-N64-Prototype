extern int func_800B4784(void);
extern void func_800B4794(int enable);
extern void func_80017A90(unsigned int mask);

void func_8009BC9C(int alternate)
{
    unsigned int mask = 0x80000000;
    int active;

    active = func_800B4784();
    if (alternate != 0) {
        mask = 0x40000000;
    }
    if (active == 0) {
        func_800B4794(1);
    }
    func_80017A90(mask);
    func_80017A90(0x20000000);
    if (active == 0) {
        func_800B4794(0);
    }
}
