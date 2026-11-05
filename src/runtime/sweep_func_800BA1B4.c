extern unsigned char D_80086D30[];
extern void func_800BA0EC(void *object);
extern void func_800ADE84(void *object, int arg);

void func_800BA1B4(unsigned char *object, int arg)
{
    *(void **)(object + 180) = D_80086D30;
    func_800BA0EC(object);
    func_800ADE84(object, arg);
}
