extern unsigned char D_80086E50[];
extern void func_800AE568(void *object);
extern void func_800BB31C(void *object);

void *func_800BB5F0(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086E50;
    func_800BB31C(object);
    return object;
}
