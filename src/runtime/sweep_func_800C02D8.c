extern unsigned char D_80088210[];
extern void func_800AC3A4(void *object);

void func_800C02D8(unsigned char *object)
{
    *(void **)(object + 180) = D_80088210;
    func_800AC3A4(object);
}
