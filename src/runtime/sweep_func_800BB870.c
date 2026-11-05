extern unsigned char D_80086EA8[];
extern void func_800AE568(void *object);
extern void func_800BB634(void *object);

void *func_800BB870(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086EA8;
    func_800BB634(object);
    return object;
}
