extern unsigned char D_80084CF0[];
extern void func_800ADE84(void *object, int mode);

void func_800A067C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084CF0;
    func_800ADE84(object, mode);
}
