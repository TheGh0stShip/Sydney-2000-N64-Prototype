extern unsigned char D_800709E8[];
extern void func_800ADE84(void *object, int mode);
extern void func_800B43F4(void *object, int mode);
extern void func_80081DC8(void *object, int mode);

void func_800BE7EC(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800709E8;
    func_800ADE84(object + 18376, 2);
    func_800ADE84(object + 18160, 2);
    func_800ADE84(object + 17944, 2);
    func_800ADE84(object + 17696, 2);
    func_800B43F4(object + 17124, 2);
    func_80081DC8(object, mode);
}
