extern unsigned char D_8007E0B8[];
extern void func_800A63F0(void *object);
extern void func_800ADED4(void *object);

void *func_80116E44(unsigned char *object)
{
    func_800A63F0(object);
    *(void **)(object + 180) = D_8007E0B8;
    func_800ADED4(object + 328);
    return object;
}
