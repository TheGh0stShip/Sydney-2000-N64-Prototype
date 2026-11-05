extern unsigned char D_80078BB8[];
extern void func_800BA1B4(void *object, int mode);

void func_80104BCC(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078BB8;
    func_800BA1B4(object, mode);
}
