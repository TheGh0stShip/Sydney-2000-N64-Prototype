extern unsigned char D_80086E50[];
extern void func_800AE4D8(void *object);

void func_800BB5CC(unsigned char *object)
{
    *(void **)(object + 180) = D_80086E50;
    func_800AE4D8(object);
}
