extern unsigned char D_8008BE48;
extern void func_800ADE84(void *object);

void func_800E7ABC(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008BE48;
    func_800ADE84(object);
}
