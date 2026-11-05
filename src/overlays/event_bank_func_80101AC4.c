extern unsigned char D_80078B68[];
extern void func_800BA1B4(void *object, int mode);

void func_80101AC4(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078B68;
    func_800BA1B4(object, mode);
}
