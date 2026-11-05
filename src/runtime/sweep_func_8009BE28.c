extern unsigned char D_800F1AE0[];
extern void func_800A3394(void *, int, int, int);
extern void func_800A3298(void *, int);

void func_8009BE28(unsigned char mode)
{
    func_800A3394(D_800F1AE0, 32767, 32767, 32767);
    switch (mode) {
    case 4:
        func_800A3298(D_800F1AE0, 2);
        break;
    case 2:
    case 3:
        func_800A3298(D_800F1AE0, 7);
        break;
    default:
        func_800A3298(D_800F1AE0, 0);
        break;
    }
}
