extern unsigned char D_800713A8[];
extern void func_800BA1B4(void *object, int mode);

void func_800DBE70(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_800713A8;
    func_800BA1B4(object, mode);
}
