extern void func_800AE568(void *object);
extern void func_800B686C(void *object);
extern unsigned char D_800869E8[];

void *func_800B69C0(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_800869E8;
    func_800B686C(object);
    return object;
}
