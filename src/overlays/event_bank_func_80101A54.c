extern unsigned char D_80078AE8[];
extern unsigned char D_80078B68[];
extern void func_800BA1B4(void *object, int mode);
extern void func_800B43F4(void *object, int mode);

void func_80101A54(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078AE8;
    func_800BA1B4(object + 1256, 2);
    func_800B43F4(object + 820, 2);
    *(void **)(object + 180) = D_80078B68;
    func_800BA1B4(object, mode);
}
