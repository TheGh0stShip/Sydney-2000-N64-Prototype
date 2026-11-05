extern unsigned char D_80086DF8[];
extern void func_800AE568(void *object);
extern void func_800BAF2C(void *object);

void *func_800BB218(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086DF8;
    func_800BAF2C(object);
    return object;
}
