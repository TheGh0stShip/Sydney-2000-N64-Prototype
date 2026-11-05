extern unsigned char D_80085068[];
extern void func_800ADE84(void *object, int mode);

void func_800A22E8(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80085068;
    func_800ADE84(object, mode);
}
