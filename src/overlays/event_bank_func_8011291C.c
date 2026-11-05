extern void func_800ADE84(void *object, int mode);
extern void func_800BA1B4(void *object, int flags);
extern char D_80078DA8[];
extern char D_80089750[];
extern char D_80078E50[];

void func_8011291C(unsigned char *object, int flags)
{
    unsigned char *sub;

    *(void **)(object + 180) = D_80078DA8;
    func_800ADE84(object + 1276, 2);
    sub = object + 1036;
    *(void **)(sub + 180) = D_80089750;
    func_800ADE84(sub, 2);
    func_800ADE84(object + 824, 2);
    *(void **)(object + 180) = D_80078E50;
    func_800BA1B4(object, flags);
}
