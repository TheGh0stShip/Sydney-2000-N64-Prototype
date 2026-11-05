extern unsigned char D_80078C40[];
extern void func_800BA1B4(void *object, int mode);

void func_800F6708(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078C40;
    func_800BA1B4(object, mode);
}
