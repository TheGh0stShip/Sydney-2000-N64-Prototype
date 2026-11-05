extern unsigned char D_80084920[];
extern void func_800ADE84(void *object, int mode);

void func_8009DA1C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80084920;
    func_800ADE84(object, mode);
}
