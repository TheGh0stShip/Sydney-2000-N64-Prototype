extern void func_8009D3D8(void *object, unsigned char value);
extern void func_800760F8(void *object, unsigned char slot, unsigned char value);

void func_80126F44(unsigned char *self, unsigned char level)
{
    unsigned char *owner;
    int show;

    owner = *(unsigned char **)(self + 4);
    self[26980] = level;
    if (level < 3 && self[426] != 4) {
        show = 0;
        if (owner[1556] != 5) {
            show = owner[1556] != 2;
        }
        if (show) {
            func_8009D3D8(self + 2076, level + 1);
        }
        func_800760F8(owner, self[743], level - 1);
    }
}
