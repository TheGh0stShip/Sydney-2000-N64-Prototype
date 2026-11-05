extern void func_800ADE84(void *object);
extern unsigned char D_80089750[];

void func_800CB9E4(unsigned char *object)
{
    *(void **)(object + 180) = D_80089750;
    func_800ADE84(object);
}
