extern unsigned char D_8007E040[];
extern void func_800A63F0(void *object);
extern void func_800E57F4(void *object);
extern void func_800A6B90(void *object);

void *func_8011808C(unsigned char *object)
{
    func_800A63F0(object);
    *(void **)(object + 180) = D_8007E040;
    func_800E57F4(object + 196);
    func_800A6B90(object + 736);
    return object;
}
