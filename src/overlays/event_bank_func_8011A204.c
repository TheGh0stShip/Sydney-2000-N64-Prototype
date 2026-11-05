extern void func_800A6C40(void *object, int mode);
extern void func_800A74C8(void *object, int mode);
extern void func_800A7338(void *object, int mode);
extern void func_800A6B04(void *object, int mode);
extern void func_800ADE84(void *object, int mode);
extern void func_800E57A4(void *object, int mode);
extern void func_800A63CC(void *object, int flags);
extern char D_8007E758[];

void func_8011A204(unsigned char *object, int flags)
{
    *(void **)(object + 180) = D_8007E758;
    func_800A6C40(object + 5248, 2);
    func_800A74C8(object + 2912, 2);
    func_800A7338(object + 2492, 2);
    func_800A6B04(object + 1172, 2);
    func_800ADE84(object + 960, 2);
    func_800ADE84(object + 748, 2);
    func_800E57A4(object + 208, 2);
    func_800A63CC(object, flags);
}
