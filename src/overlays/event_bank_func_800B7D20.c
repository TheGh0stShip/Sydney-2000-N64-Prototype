extern unsigned char D_80070930[];
extern void func_800ADE84(void *object, int mode);
extern void func_80081DC8(void *object, int mode);

void func_800B7D20(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80070930;
    func_800ADE84(object + 17372, 2);
    func_800ADE84(object + 17160, 2);
    func_80081DC8(object, mode);
}
