extern void func_800AE4D8(void *object);
extern unsigned char D_800869E8[];

void func_800B699C(unsigned char *object)
{
    *(void **)(object + 180) = D_800869E8;
    func_800AE4D8(object);
}
