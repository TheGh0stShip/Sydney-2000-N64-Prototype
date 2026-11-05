extern unsigned char D_80070A00[];
extern void func_800ADE84(void *object, int mode);
extern void func_80081DC8(void *object, int mode);

void func_800C04B4(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80070A00;
    func_800ADE84(object + 17368, 2);
    func_800ADE84(object + 17148, 2);
    func_80081DC8(object, mode);
}
