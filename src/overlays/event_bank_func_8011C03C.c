extern unsigned char D_80080C20[];
extern void func_800ADE84(void *object, int mode);

void func_8011C03C(unsigned char *object, int mode)
{
    *(void **)(object + 180) = D_80080C20;
    func_800ADE84(object, mode);
}
