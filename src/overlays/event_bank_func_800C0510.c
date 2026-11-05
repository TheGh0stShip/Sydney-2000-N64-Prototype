extern unsigned char D_80070A90[];
extern void func_800ADE84(void *object, int mode);

void func_800C0510(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80070A90;
    func_800ADE84(object, mode);
}
