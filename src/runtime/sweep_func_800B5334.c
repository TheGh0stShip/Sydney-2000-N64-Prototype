extern void func_800AE4D8(void *object);
extern unsigned char D_800867C8[];

void func_800B5334(unsigned char *object)
{
    *(void **)(object + 180) = D_800867C8;
    func_800AE4D8(object);
}
