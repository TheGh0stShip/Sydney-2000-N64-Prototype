extern void func_800AC718(void *dst, void *src);
extern void func_800B48CC(void *self, int value, int flag);
extern void func_800BAF90(void *self);

void func_800BB070(unsigned char *self, int value, int keep, unsigned int mode)
{
    if (mode - 1 < 2) {
        *(int *)(self + 380) = value;
    }
    if (mode == 0 || mode == 2) {
        func_800AC718(self + 20, self + 428);
        func_800B48CC(self, value, 0);
        func_800AC718(self + 20, self + 444);
        *(int *)(self + 376) = value;
        if (keep == 0) {
            *(int *)(self + 460) = 0;
            func_800BAF90(self);
        }
    }
}
