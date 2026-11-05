extern unsigned char D_8008B118[];
extern unsigned char D_8008B1D0[];
extern void func_800ADE84(void *object, int mode);
extern void func_800AC3A4(void *object, int mode);

void func_800DE5FC(unsigned char *object, int mode)
{
    unsigned char *child;

    *(void **)(object + 180) = D_8008B118;
    func_800ADE84(object + 380, 2);
    child = object + 192;
    *(void **)(child + 180) = D_8008B1D0;
    func_800AC3A4(child, 2);
    func_800AC3A4(object, mode);
}
