extern unsigned char D_80080A78[];
extern void func_800BA1B4(void *object, int mode);

void func_8011D78C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80080A78;
    func_800BA1B4(object, mode);
}
