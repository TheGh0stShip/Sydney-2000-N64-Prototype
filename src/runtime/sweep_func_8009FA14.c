extern unsigned char D_80084BD8[];
extern void func_800ADE84(void *object, int mode);

void func_8009FA14(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084BD8;
    func_800ADE84(object, mode);
}
