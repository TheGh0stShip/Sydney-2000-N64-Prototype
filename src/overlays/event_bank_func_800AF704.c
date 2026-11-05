extern unsigned char D_80071438[];
extern void func_800BA1B4(void *object, int mode);

void func_800AF704(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80071438;
    func_800BA1B4(object, mode);
}
