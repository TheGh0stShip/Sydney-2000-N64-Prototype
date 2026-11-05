extern unsigned char D_8008BF48;
extern void func_800AE4D8(void *object);

void func_800E81CC(unsigned char *object)
{
    *(void **)(object + 180) = &D_8008BF48;
    func_800AE4D8(object);
}
