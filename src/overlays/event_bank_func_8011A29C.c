extern void func_800A63F0(void *object);
extern void func_800E57F4(void *object);
extern void func_800ADED4(void *object);
extern void func_800A6B90(void *object);
extern void func_800A73A4(void *object);
extern void func_800A7554(void *object);
extern void func_800A6C64(void *object);
extern char D_8007E758[];

void *func_8011A29C(unsigned char *object)
{
    func_800A63F0(object);
    *(void **)(object + 180) = D_8007E758;
    *(int *)(object + 196) = 0;
    *(int *)(object + 200) = 0;
    func_800E57F4(object + 208);
    func_800ADED4(object + 748);
    func_800ADED4(object + 960);
    func_800A6B90(object + 1172);
    func_800A73A4(object + 2492);
    func_800A7554(object + 2912);
    func_800A6C64(object + 5248);
    return object;
}
