extern unsigned char D_80078B98[];
extern void func_800BA1B4(void *object, int mode);

void func_800F99A0(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078B98;
    func_800BA1B4(object, mode);
}
