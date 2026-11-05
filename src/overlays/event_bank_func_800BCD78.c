extern unsigned char D_800709E0[];
extern void func_800ADE84(void *object, int mode);
extern void func_80081DC8(void *object, int mode);

void func_800BCD78(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800709E0;
    func_800ADE84(object + 17236, 2);
    func_80081DC8(object, mode);
}
