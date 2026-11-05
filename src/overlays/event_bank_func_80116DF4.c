extern unsigned char D_8007E0B8[];
extern void func_800ADE84(void *object, int mode);
extern void func_800A63CC(void *object, int mode);

void func_80116DF4(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_8007E0B8;
    func_800ADE84(object + 328, 2);
    func_800A63CC(object, mode);
}
