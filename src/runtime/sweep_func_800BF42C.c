extern void func_800BE630(void *self);
extern void func_800ADFAC(void *self);
extern void func_800AE304(void *self);

void func_800BF42C(unsigned char *self, int *message)
{
    int elapsed = (message[1] - *(int *)(self + 16)) >> 8;

    switch (message[0]) {
    case 3:
        break;
    case 5:
        if (elapsed == 0) {
            return;
        }
        func_800BE630(self);
        break;
    }
    *(int *)(self + 16) = message[1];
    if (*(int *)(self + 296) != 0) {
        return;
    }
    if (*(int *)(self + 268) != 0) {
        func_800ADFAC(self);
    }
    if (*(unsigned short *)(self + 196) & 1) {
        func_800AE304(self);
    }
}
