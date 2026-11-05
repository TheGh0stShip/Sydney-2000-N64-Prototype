extern unsigned char D_80088BF8[];
extern void func_800BA1B4(void *object);

void func_800C879C(unsigned char *object)
{
    *(void **)(object + 180) = D_80088BF8;
    func_800BA1B4(object);
}
