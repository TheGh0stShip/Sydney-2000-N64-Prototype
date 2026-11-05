extern unsigned char D_800709A0[];
extern void func_800ADE84(void *object, int mode);
extern void func_80081DC8(void *object, int mode);

void func_800D02D0(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800709A0;
    func_800ADE84(object + 17640, 2);
    func_800ADE84(object + 17424, 2);
    func_800ADE84(object + 17144, 2);
    func_80081DC8(object, mode);
}
