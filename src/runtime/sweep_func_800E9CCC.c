extern unsigned char D_8008C0B8;
extern void func_800BA1B4(void *object);

void func_800E9CCC(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008C0B8;
    func_800BA1B4(object);
}
