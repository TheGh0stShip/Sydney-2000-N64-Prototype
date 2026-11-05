extern unsigned char D_80088910[];
extern void func_800ADE84(void *object);

void func_800C80FC(unsigned char *object)
{
    *(void **)(object + 180) = D_80088910;
    func_800ADE84(object);
}
