extern void func_800BA1B4(void *object);
extern unsigned char D_80071470[];

void func_8008F744(unsigned char *object)
{
    *(void **)(object + 180) = D_80071470;
    func_800BA1B4(object);
}
