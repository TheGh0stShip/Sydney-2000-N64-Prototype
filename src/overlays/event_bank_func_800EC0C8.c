extern unsigned char D_80078CC8[];
extern void func_800BA1B4(void *object, int mode);

void func_800EC0C8(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078CC8;
    func_800BA1B4(object, mode);
}
