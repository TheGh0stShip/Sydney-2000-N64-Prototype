extern unsigned char D_80078B30[];
extern void func_800BA1B4(void *object, int mode);

void func_8010B138(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078B30;
    func_800BA1B4(object, mode);
}
