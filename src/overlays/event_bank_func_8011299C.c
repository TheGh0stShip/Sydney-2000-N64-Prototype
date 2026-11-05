extern unsigned char D_80078E50[];
extern void func_800BA1B4(void *object, int mode);

void func_8011299C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80078E50;
    func_800BA1B4(object, mode);
}
