extern unsigned char D_80070FE0[];
extern void func_800ADE84(void *object, int mode);
extern void func_800BB5CC(void *object, int mode);
extern void func_80081DC8(void *object, int value);

void func_800BAFF8(unsigned char *object, int value)
{
    *(void **)(object + 180) = D_80070FE0;
    func_800ADE84(object + 18328, 2);
    func_800ADE84(object + 18116, 2);
    func_800ADE84(object + 17904, 2);
    func_800ADE84(object + 17692, 2);
    func_800BB5CC(object + 17128, 2);
    func_80081DC8(object, value);
}
